//
// Created by ngrande on 12/15/15.
//

#ifndef PIALARM_SCHEDULETIME_H
#define PIALARM_SCHEDULETIME_H

//using namespace std;

#include "ITask.h"
#include <time.h>
#include <memory>

using namespace std;

class ScheduleTask {
private:
    // reference: http://www.cplusplus.com/reference/ctime/tm/
    int dayOfWeek; // 0 - 6 days since sunday
    int hour; // 0 - 23 hours since midnight
    int minute; // 0 - 59 minutes after the hour
    int second; // 0 - 60 seconds after the minute (is generally 0-59. The extra range is to accommodate for leap seconds in certain systems.)

    // set the values to -1 if you do not want to "use" them

    shared_ptr<ITask> task;
    bool doRepeat;
    struct tm lastExecutionTime;
public:
    ScheduleTask(shared_ptr<ITask> task, int dayOfWeek, int hour, int minute, int second, bool doRepeat) : task(task),
                                                                                                           dayOfWeek(dayOfWeek),
                                                                                                           hour(hour),
                                                                                                           minute(minute),
                                                                                                           second(second),
                                                                                                           doRepeat(doRepeat) { };

    void executeTaskAsync();

    bool getDoRepeat() const { return doRepeat; };

    double calculateLeftTime() const;
};


#endif //PIALARM_SCHEDULETIME_H
