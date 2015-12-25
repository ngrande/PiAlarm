//
// Created by ngrande on 12/13/15.
//

#ifndef PIALARM_SCHEDULER_H
#define PIALARM_SCHEDULER_H

#include <condition_variable>
#include <map>
#include <vector>
#include "ScheduleTask.h"
#include <thread>

using namespace std;

// This class should be used to create schedules events / tasks that will trigger after a specific time -> periodically or only one time
class Scheduler {
private:
    condition_variable cv; // used to stop or continue a thread
    mutex cv_m; // used to protect a shared resource
    vector<shared_ptr<ScheduleTask>> tasks;
    thread taskStarterThread;
    bool stopped = true;

    void startNextTask();

    double calcSecondsUntilNextTask();

    void startTaskStarterThread();

public:

    void addTask(shared_ptr<ITask> task, int dayOfWeek, int hour, int minute, int second, bool repeat);

    void start();

    void stop();
};


#endif //PIALARM_SCHEDULER_H
