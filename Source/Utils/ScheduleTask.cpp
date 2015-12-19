//
// Created by ngrande on 12/15/15.
//

#include <time.h>
#include "ScheduleTask.h"
#include <thread>

double ScheduleTask::calculateLeftTime() const {
    time_t timerNow;
    time(&timerNow); // get current time
    struct tm timeNow;
    localtime_r(&timerNow, &timeNow); // get local time
    struct tm timeOfTask;
    localtime_r(&timerNow, &timeOfTask);


    double diffDayBuffer = 0;
    // check if task was already executed today (to be sure check the year != 0)
    // if yes then add 7 days
    // if not then add rest of days
    if (lastExecutionTime.tm_year != 0 && lastExecutionTime.tm_wday == this->dayOfWeek) {
        diffDayBuffer = 7 * 24 * 60 * 60;
    } else if (timeNow.tm_wday != this->dayOfWeek) {
        if (timeNow.tm_wday > this->dayOfWeek) {
            diffDayBuffer = (7 + (this->dayOfWeek - timeNow.tm_wday)) * 24 * 60 * 60;
        } else if (timeNow.tm_wday < this->dayOfWeek) {
            diffDayBuffer = (this->dayOfWeek - timeNow.tm_wday) * 24 * 60 * 60; // seconds
        }
    }

    timeOfTask.tm_hour = this->hour >= 0 ? this->hour : timeOfTask.tm_hour;
    timeOfTask.tm_min = this->minute >= 0 ? this->minute : timeOfTask.tm_min;
    timeOfTask.tm_sec = this->second; // seconds MUST be set
    timeOfTask.tm_wday = this->dayOfWeek >= 0 ? this->dayOfWeek : timeOfTask.tm_wday;


    // -3682348492 | -36832362
    double diff = difftime(mktime(&timeOfTask), mktime(&timeNow)) + diffDayBuffer;
    return diff;
}

void ScheduleTask::executeTaskAsync() {
    time_t timerNow;
    time(&timerNow); // get current time
    localtime_r(&timerNow, &lastExecutionTime); // get local time

    std::thread executeThread(&ITask::onTimeExceeded, this->task);
    executeThread.detach();
}
