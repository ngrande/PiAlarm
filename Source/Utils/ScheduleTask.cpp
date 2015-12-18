//
// Created by ngrande on 12/15/15.
//

#include <time.h>
#include "ScheduleTask.h"

double ScheduleTask::calculateLeftTime() const {
    time_t timerNow;
    time(&timerNow); // get current time
    struct tm timeNow;
    localtime_r(&timerNow, &timeNow); // get local time
    struct tm timeOfTask;
    localtime_r(&timerNow, &timeOfTask);


    timeOfTask.tm_wday = this->dayOfWeek >= 0 ? this->dayOfWeek : timeOfTask.tm_wday;
    timeOfTask.tm_hour = this->hour >= 0 ? this->hour : timeOfTask.tm_hour;
    timeOfTask.tm_min = this->minute >= 0 ? this->minute : timeOfTask.tm_min;
    timeOfTask.tm_sec = this->second; // seconds MUST be set

    // -3682348492 | -36832362
    double diff = difftime(mktime(&timeOfTask), mktime(&timeNow));
    return diff;
}
