//
// Created by ngrande on 12/13/15.
//

#ifndef PIALARM_SCHEDULER_H
#define PIALARM_SCHEDULER_H

#include <condition_variable>
#include <map>
#include <vector>
#include "ITask.h"
#include "../SoundPlayer.h"

using namespace std;

struct TaskTime {
    ushort dayOfWeek;
    ushort hour;
    ushort minute;
    ushort second;

    int calcCompareableTime() const { return dayOfWeek * 1000 + hour * 100 + minute * 10 + second; };
};

struct TaskSave {
    TaskTime time;
    ITask *task;
};

// This class should be used to create schedules events / tasks that will trigger after a specific time -> periodically or only one time
class Scheduler {
private:
    condition_variable cv; // used to stop or continue a thread
    mutex cv_m; // used to protect a shared resource
//    map<TaskTime, vector<ITask*>> tasksMap;
    vector<TaskSave *> tasks;

    void taskController();

    double calculateTimeUntilNextTask();

public:

    void addTask(ITask *task, TaskTime taskTime);

    void start();

    void stop();
};


#endif //PIALARM_SCHEDULER_H
