//
// Created by ngrande on 12/23/15.
//

#ifndef PIALARM_ALARMCONTROLLER_H
#define PIALARM_ALARMCONTROLLER_H

#include <string>
#include <vector>
#include "Utils/Scheduler.h"
#include "SoundPlayer.h"
#include "StandardMode.h"

using namespace std;

struct AlarmSetup {
    string name;
    string message;
    int hour;
    int minute;
    int second;
    string soundPath;
    vector<int> days; // 1 = Monday, 2 = Tuesday, ... 7 = Sunday.
};

class AlarmController {
private:
    const char *CONFIG_FILENAME = ".PiAlarm.xml";
    Scheduler scheduler;
    vector<AlarmSetup> alarmSetups;
    SoundPlayer soundPlayer;
    StandardMode standardMode;

    void loadAlarmSetups();

public:
    void startAlarms();

    void stopCurrentAlarm();
};


#endif //PIALARM_ALARMCONTROLLER_H
