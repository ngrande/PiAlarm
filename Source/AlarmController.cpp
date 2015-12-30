//
// Created by ngrande on 12/23/15.
//

#include <rapidxml.hpp>
#include <rapidxml_utils.hpp>
#include <rapidxml_print.hpp>
#include "Utils/Helper.h"
#include "AlarmTask.h"
#include "AlarmController.h"

using namespace rapidxml;

void AlarmController::readAlarmSetups(vector<AlarmSetup> &buffer) {
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

        buffer.push_back(alarmSetup);
    }
}

void AlarmController::start() {
    readAlarmSetups(alarmSetups);

    for (vector<AlarmSetup>::iterator alarmsIt = alarmSetups.begin(); alarmsIt < alarmSetups.end(); alarmsIt++) {
        auto alarmPt = alarmsIt.base();

        for (int i = 0; i < alarmPt->days.size(); i++) {
            shared_ptr<AlarmTask> alarmTask(
                    new AlarmTask(&soundPlayer, &standardMode, alarmPt->name, alarmPt->message, alarmPt->soundPath));
            // i assume a shared_ptr would make more sense here
            scheduler.addTask(alarmTask, alarmPt->days[i], alarmPt->hour, alarmPt->minute, alarmPt->second, true);
        }
    }

    scheduler.start();
}

void AlarmController::stop() {
    scheduler.stop();
}

void AlarmController::dismissAlarm() {
    soundPlayer.stopPlayback();
}

void AlarmController::addAlarm(AlarmSetup &alarmSetup) {
    file<> xmlFile = file<>(CONFIG_FILENAME);
    xml_document<> doc;
    doc.parse<0>(xmlFile.data());

    xml_node<> *rootNode = doc.first_node();
    rootNode = rootNode->first_node("AlarmSetups");

    // create node to add
    xml_node<> *addedNode = doc.allocate_node(node_element, "AlarmSetup");

    // add node attributes
    xml_node<> *addedNestedNode = doc.allocate_node(node_element, "name");
    addedNestedNode->value(alarmSetup.name.c_str());
    addedNode->append_node(addedNestedNode);

    addedNestedNode = doc.allocate_node(node_element, "message");
    addedNestedNode->value(alarmSetup.message.c_str());
    addedNode->append_node(addedNestedNode);

    addedNestedNode = doc.allocate_node(node_element, "sound-path");
    addedNestedNode->value(alarmSetup.soundPath.c_str());
    addedNode->append_node(addedNestedNode);
    char buffer[2];
    memory_pool<> memoryPool;
    sprintf(buffer, "%d", alarmSetup.hour);
    addedNestedNode = doc.allocate_node(node_element, "hour");
    addedNestedNode->value(memoryPool.allocate_string(buffer, sizeof(buffer)));
    addedNode->append_node(addedNestedNode);

    sprintf(buffer, "%d", alarmSetup.minute);
    addedNestedNode = doc.allocate_node(node_element, "minute");
    addedNestedNode->value(memoryPool.allocate_string(buffer, sizeof(buffer)));
    addedNode->append_node(addedNestedNode);

    sprintf(buffer, "%d", alarmSetup.second);
    addedNestedNode = doc.allocate_node(node_element, "second");
    addedNestedNode->value(memoryPool.allocate_string(buffer, sizeof(buffer)));
    addedNode->append_node(addedNestedNode);

    string daysStr = "";
    for (int i = 0; i < alarmSetup.days.size(); i++) {
        char daysBuffer[1];
        sprintf(daysBuffer, "%d", alarmSetup.days[i]);
        daysStr += daysBuffer;
        if (i + 1 < alarmSetup.days.size()) {
            daysStr += ',';
        }
    }

    addedNestedNode = doc.allocate_node(node_element, "days");
    addedNestedNode->value(daysStr.c_str());
    addedNode->append_node(addedNestedNode);

    // finally add new created node
    rootNode->append_node(addedNode); // append an AlarmSetup xml tag
    ofstream file(CONFIG_FILENAME);
    if (file.is_open()) {
        string data;
        rapidxml::print(back_inserter(data), doc);
        file << "<?xml version=\"1.0\"?>" << endl;
        file << data;
        file.close();
    }
}
