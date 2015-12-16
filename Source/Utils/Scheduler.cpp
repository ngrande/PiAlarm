//
// Created by ngrande on 12/13/15.
//

#include <thread>
#include <algorithm>
#include "Scheduler.h"

// TODO: add support for repeatable tasks
// TODO: add support for times where not all values are set (i.e. an event which triggers after 30 seconds -> like the crons)

void Scheduler::addTask(shared_ptr<ITask> task, shared_ptr<ScheduleTime> scheduleTime) {
    tasks.push_back(unique_ptr<TaskSave>(new TaskSave(task, scheduleTime)));
}

void Scheduler::start() {
    stopped = false;
    // start thread to wait
    taskStarterThread = thread(&Scheduler::startNextTask, this);
}

void Scheduler::stop() {
// stop thread to wait
    stopped = true;
    cv.notify_all();
    taskStarterThread.join();
}

void Scheduler::startNextTask() {
    // start each task (every task in a new thread)
    while (!stopped) {
        double secondsUntilNextTask = calcSecondsUntilNextTask();
        unique_lock<mutex> lck(cv_m);
        cv.wait_for(lck, chrono::seconds((long) secondsUntilNextTask));

        // start all overdue tasks
        for (int i = (int) tasks.size() - 1; i >= 0; i--) {
            if (tasks[i]->time->calculateLeftTime() <= 0) {
                thread taskExecutorThread(&ITask::onTimeExceeded, tasks[i]->task);
                taskExecutorThread.detach(); // otherwise it would be destroyed as soon as out of scope...


                // Todo: delete task after execution...
                // delete this task from the vector [at the end]
                // "[...] Compared to the other dynamic sequence containers (deques, lists and forward_lists),
                // vectors are very efficient accessing its elements (just like arrays) and relatively efficient adding
                // or removing elements from its end." - http://www.cplusplus.com/reference/vector/vector
//                tasks.pop_back();
            }
        }
    }
}

double Scheduler::calcSecondsUntilNextTask() {

    // even though this might cause a small performance issue -> you can be sure the list is sorted before taking the first element
    sort(tasks.begin(), tasks.end(),
         [](shared_ptr<TaskSave> a, shared_ptr<TaskSave> b) -> bool {
             return a->time->calculateLeftTime() > b->time->calculateLeftTime();
         });

// use the last element to check when the next task will be started
//    auto taskSave = tasks[tasks.size() - 1];
    return tasks.at(tasks.size() - 1)->time->calculateLeftTime();
}
