//
// Created by ngrande on 12/13/15.
//

#include <thread>
#include <algorithm>
#include "Scheduler.h"

void Scheduler::addTask(ITask *task, TaskTime taskTime) {
    TaskSave taskSave;
    taskSave.task = task;
    taskSave.time = taskTime;
    tasks.push_back(&taskSave);
}

void Scheduler::start() {

    // start thread to wait
    thread taskControllerThread(&Scheduler::taskController, this);
}

void Scheduler::stop() {
// stop thread to wait
}

void Scheduler::taskController() {
    ulong timeUntilNextTask = 0;
}

double Scheduler::calculateTimeUntilNextTask() {


    sort(tasks.begin(), tasks.end(),
         [](TaskSave *a, TaskSave *b) { return a->time.calcCompareableTime() < b->time.calcCompareableTime(); });
    auto taskSave = tasks[0];

    time_t *timer = nullptr;
    time(timer); // get current time
    struct tm *timeNow = localtime(timer); // get local time
    struct tm taskTime = {0};
    taskTime.tm_hour = taskSave->time.hour;
    taskTime.tm_wday = taskSave->time.dayOfWeek;
    taskTime.tm_min = taskSave->time.minute;
    taskTime.tm_sec = taskSave->time.second;
    return difftime(mktime(&taskTime), mktime(timeNow));
}