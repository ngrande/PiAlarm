//
// Created by ngrande on 12/13/15.
//

#ifndef PIALARM_SCHEDULER_H
#define PIALARM_SCHEDULER_H

#include <condition_variable>
#include <map>
#include <vector>
#include "ITask.h"
#include "ScheduleTime.h"
#include <thread>

using namespace std;

struct TaskSave {
    shared_ptr<ScheduleTime> time;
    shared_ptr<ITask> task;

    TaskSave(shared_ptr<ITask> taskPtr, shared_ptr<ScheduleTime> scheduleTimePtr) {
        task = taskPtr;
        time = scheduleTimePtr;
    }
};

// This class should be used to create schedules events / tasks that will trigger after a specific time -> periodically or only one time
class Scheduler {
private:
    condition_variable cv; // used to stop or continue a thread
    mutex cv_m; // used to protect a shared resource
//    map<TaskTime, vector<ITask*>> tasksMap;
    vector<shared_ptr<TaskSave>> tasks;
    thread taskStarterThread;
    thread taskExecutorThread;
    bool stopped;

    void startNextTask();

    double calcSecondsUntilNextTask();

public:

    void addTask(shared_ptr<ITask> task, shared_ptr<ScheduleTime> scheduleTime);

    void start();

    void stop();
};


#endif //PIALARM_SCHEDULER_H
