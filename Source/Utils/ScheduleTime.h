//
// Created by ngrande on 12/15/15.
//

#ifndef PIALARM_SCHEDULETIME_H
#define PIALARM_SCHEDULETIME_H

//using namespace std;

class ScheduleTime {
private:
    int dayOfWeek;
    int hour;
    int minute;
    int second;

public:
    ScheduleTime(int dayOfWeek, int hour, int minute, int second) : dayOfWeek(dayOfWeek), hour(hour), minute(minute),
                                                                    second(second) { };

    double calculateLeftTime() const;
};


#endif //PIALARM_SCHEDULETIME_H
