//
// Created by ngrande on 12/15/15.
//

#include <time.h>
#include "ScheduleTime.h"

double ScheduleTime::calculateLeftTime() const {
    time_t timerNow;
    time(&timerNow); // get current time
    struct tm timeNow;
    localtime_r(&timerNow, &timeNow); // get local time
    struct tm timeOfTask;
    localtime_r(&timerNow, &timeOfTask);


    timeOfTask.tm_hour = this->hour;
    timeOfTask.tm_wday = this->dayOfWeek;
    timeOfTask.tm_min = this->minute;
    timeOfTask.tm_sec = this->second;

    // -3682348492 | -36832362
    double diff = difftime(mktime(&timeOfTask), mktime(&timeNow));
    return diff;
}
