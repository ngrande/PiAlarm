//
// Created by ngrande on 12/23/15.
//

#include <rapidxml.hpp>
#include <rapidxml_utils.hpp>
#include "AlarmController.h"
#include "Utils/Helper.h"
#include "AlarmTask.h"

using namespace rapidxml;

void AlarmController::loadAlarmSetups() {
    file<> xmlFile = file<>(CONFIG_FILENAME);
    xml_document<> doc;
    doc.parse<0>(xmlFile.data());

    xml_node<> *rootNode = doc.first_node();
    rootNode = rootNode->first_node("AlarmSetups");

    for (xml_node<> *valueNode = rootNode->first_node("AlarmSetup"); valueNode; valueNode = valueNode->next_sibling()) {
        AlarmSetup alarmSetup;
        alarmSetup.name = valueNode->first_node("name")->value();
        alarmSetup.message = valueNode->first_node("message")->value();
        alarmSetup.soundPath = valueNode->first_node("sound-path")->value();
        alarmSetup.hour = stoi(valueNode->first_node("hour")->value());
        alarmSetup.minute = stoi(valueNode->first_node("minute")->value());
        alarmSetup.second = stoi(valueNode->first_node("second")->value());
        string daysString = valueNode->first_node("days")->value();

        int appearanceCount = Helper::countAppearance(daysString, ',') + 1;
        string daysStringArr[appearanceCount];
        Helper::separate(daysStringArr, daysString.c_str(), ',');

        for (int i = 0; i < appearanceCount; i++) {
            alarmSetup.days.push_back(stoi(daysStringArr[i]));
        }

        alarmSetups.push_back(alarmSetup);
    }
}

void AlarmController::startAlarms() {
    for (vector<AlarmSetup>::iterator alarmsIt = alarmSetups.begin(); alarmsIt < alarmSetups.end(); alarmsIt++) {
        auto alarmPt = alarmsIt.base();

        for (int i = 0; i < alarmPt->days.size(); i++) {
            shared_ptr<AlarmTask> alarmTask(
                    new AlarmTask(&soundPlayer, &standardMode, alarmPt->name, alarmPt->message, alarmPt->soundPath));
            // i assume a shared_ptr would make more sense here
            scheduler.addTask(alarmTask, alarmPt->days[i], alarmPt->hour, alarmPt->minute, alarmPt->second, true);
        }
    }
}

void AlarmController::stopCurrentAlarm() {
    soundPlayer.stopPlayback();
}
