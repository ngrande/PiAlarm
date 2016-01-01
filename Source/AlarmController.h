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
#include <rapidxml.hpp>

using namespace rapidxml;
using namespace std;

struct AlarmSetup {
    string name;
    string message;
    int hour;
    int minute;
    int second;
    int id;
    string soundPath;
    vector<int> days; // 1 = Monday, 2 = Tuesday, ... 7 = Sunday.
};

class AlarmController {
private:
    // todo: add complete path and a standard file - auto create if none exists.
    const char *CONFIG_FILENAME = ".PiAlarm.xml";
    Scheduler scheduler;
    vector<AlarmSetup> alarmSetups;
    SoundPlayer soundPlayer;
    StandardMode standardMode;

    int generateAlarmSetupId();

    void saveXmlConfigDoc(string &data);

    void loadXmlConfigDoc(xml_document<> &doc);

public:
    void start();

    void stop();

    void addAlarmSetup(AlarmSetup &alarmSetup);

    void deleteAlarmSetup(int id);

    void readAlarmSetups(vector<AlarmSetup> &buffer);

    void dismissAlarm();
};


#endif //PIALARM_ALARMCONTROLLER_H
