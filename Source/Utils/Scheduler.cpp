//
// Created by ngrande on 12/13/15.
//

#include <thread>
#include <algorithm>
#include "Scheduler.h"

// TODO: add support for periodically times (i.e. every 30 minutes or every 3 days)

void Scheduler::addTask(shared_ptr<ITask> task, int dayOfWeek, int hour, int minute, int second, bool repeat) {
    tasks.push_back(unique_ptr<ScheduleTask>(new ScheduleTask(task, dayOfWeek, hour, minute, second, repeat)));

    // to ensure that a latter added task which comes first is done first.
    stop();
    start();
}


void Scheduler::start() {
    stopped = false;
    // start thread to wait
    startTaskStarterThread();
}

void Scheduler::stop() {
// stop thread to wait
    stopped = true;
    cv.notify_all();
    taskStarterThread.join();
}

void Scheduler::startNextTask() {
    // start the tasks (chronological order) in a thread
    while (!stopped && tasks.size() > 0) {
        double secondsUntilNextTask = calcSecondsUntilNextTask();
        unique_lock<mutex> lck(cv_m);
        cv.wait_for(lck, chrono::seconds((long) secondsUntilNextTask));

        // start all overdue tasks
        for (int i = (int) tasks.size() - 1; i >= 0; i--) {
            if (tasks[i]->calculateLeftTime() <= 0) {

//                thread taskExecutorThread(&ITask::onTimeExceeded, tasks[i]->getTaskImpl());
//                taskExecutorThread.detach(); // otherwise it would be destroyed as soon as out of scope...
                tasks[i]->executeTaskAsync();

                // delete element from vector when repeat is false
                if (!tasks[i]->getDoRepeat()) {
                    // delete this task from the vector [at the end]
                    // "[...] Compared to the other dynamic sequence containers (deques, lists and forward_lists),
                    // vectors are very efficient accessing its elements (just like arrays) and relatively efficient adding
                    // or removing elements from its end." - http://www.cplusplus.com/reference/vector/vector
                    tasks.erase(tasks.begin() + i);
                }
            }
        }
    }
}

double Scheduler::calcSecondsUntilNextTask() {

    // even though this might cause a small performance issue -> you can be sure the list is sorted before taking the first element
    sort(tasks.begin(), tasks.end(),
         [](shared_ptr<ScheduleTask> a, shared_ptr<ScheduleTask> b) -> bool {
             return a->calculateLeftTime() > b->calculateLeftTime();
         });

// use the last element to check when the next task will be started
//    auto taskSave = tasks[tasks.size() - 1];>
    if (tasks.size() > 0) {
        return tasks.at(tasks.size() - 1)->calculateLeftTime();
    } else {
        return 0;
    }
}

void Scheduler::startTaskStarterThread() {
    taskStarterThread = thread(&Scheduler::startNextTask, this);
}
