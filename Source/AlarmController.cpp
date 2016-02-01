//
// Created by ngrande on 12/23/15.
//

#include <rapidxml_utils.hpp>
#include <rapidxml_print.hpp>
#include "Utils/Helper.h"
#include "AlarmTask.h"
#include "AlarmController.h"

void AlarmController::readAlarmSetups(vector<AlarmSetup> &buffer) {
    xml_document<> doc;
    loadXmlConfigDoc(doc);

    auto rootNode = doc.first_node();
    rootNode = rootNode->first_node("AlarmSetups");

    for (xml_node<> *valueNode = rootNode->first_node("AlarmSetup"); valueNode; valueNode = valueNode->next_sibling()) {
        AlarmSetup alarmSetup;
        alarmSetup.name = valueNode->first_node("name")->value();
        alarmSetup.message = valueNode->first_node("message")->value();
        alarmSetup.soundPath = valueNode->first_node("sound-path")->value();
        alarmSetup.hour = stoi(valueNode->first_node("hour")->value());
        alarmSetup.minute = stoi(valueNode->first_node("minute")->value());
        alarmSetup.second = stoi(valueNode->first_node("second")->value());
        alarmSetup.id = stoi(valueNode->first_node("id")->value());
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

void AlarmController::addAlarmSetup(AlarmSetup &alarmSetup) {
    xml_document<> doc;
    loadXmlConfigDoc(doc);

    auto rootNode = doc.first_node();
    auto name = rootNode->name();
    rootNode = rootNode->first_node("AlarmSetups");

    // create node to add
    auto addedNode = doc.allocate_node(node_element, "AlarmSetup");

    // add node attributes
    appendNode(doc, addedNode, "name", alarmSetup.name);

    appendNode(doc, addedNode, "message", alarmSetup.message);

    appendNode(doc, addedNode, "sound-path", alarmSetup.soundPath);

    char buffer[10];
    sprintf(buffer, "%d", alarmSetup.hour);
    appendNode(doc, addedNode, "hour", buffer, sizeof(buffer));

    sprintf(buffer, "%d", alarmSetup.minute);
    appendNode(doc, addedNode, "minute", buffer, sizeof(buffer));

    sprintf(buffer, "%d", alarmSetup.second);
    appendNode(doc, addedNode, "second", buffer, sizeof(buffer));

    sprintf(buffer, "%d", generateAlarmSetupId());
    appendNode(doc, addedNode, "id", buffer, sizeof(buffer));

    string daysStr = "";
    for (int i = 0; i < alarmSetup.days.size(); i++) {
        char daysBuffer[1];
        sprintf(daysBuffer, "%d", alarmSetup.days[i]);
        daysStr += daysBuffer;
        if (i + 1 < alarmSetup.days.size()) {
            daysStr += ',';
        }
    }

    appendNode(doc, addedNode, "days", daysStr);

    // finally add new created node
    rootNode->append_node(addedNode); // append an AlarmSetup xml tag

    string data;
    rapidxml::print(back_inserter(data), doc);
    saveXmlConfigDoc(data);
}

int AlarmController::generateAlarmSetupId() {
    // current date time
    time_t timerNow;
    time(&timerNow); // get current time
    struct tm y0;
    y0.tm_hour = 0;
    y0.tm_min = 0;
    y0.tm_sec = 0;
    y0.tm_year = 116;
    y0.tm_mon = 0;
    y0.tm_mday = 1;
    double seconds = difftime(timerNow, mktime(&y0));
    return (int) seconds;
}

void AlarmController::deleteAlarmSetup(int id) {
    xml_document<> doc;
    loadXmlConfigDoc(doc);

    auto rootNode = doc.first_node();
    rootNode = rootNode->first_node("AlarmSetups");

    for (xml_node<> *valueNode = rootNode->first_node("AlarmSetup"); valueNode; valueNode = valueNode->next_sibling()) {
        if (stoi(valueNode->first_node("id")->value()) == id) {
            rootNode->remove_node(valueNode);
            break;
        }
    }

    string data;
    rapidxml::print(back_inserter(data), doc);
    saveXmlConfigDoc(data);
}

void AlarmController::loadXmlConfigDoc(xml_document<> &doc) {
    // todo: there is a bug - when creating the file and then using the modification methods like add and delete
    if (!Helper::fileExists(CONFIG_FILENAME)) {
        createXmlConfigFile();
    }
    file<> xmlFile(CONFIG_FILENAME);
    doc.parse<0>(xmlFile.data());
}

void AlarmController::saveXmlConfigDoc(string &data) {
    // not possible to use the xml_document<> as a parameter -> the xml data is broken then and copy constructor is deleted
    ofstream file(CONFIG_FILENAME);
    if (file.is_open()) {
        file << "<?xml version=\"1.0\"?>" << endl;
        file << data;
        file.close();
    }
}

void AlarmController::createXmlConfigFile() {
    xml_document<> doc;
    auto rootNode = doc.allocate_node(node_element, "PiAlarm");
    auto alarmsNode = doc.allocate_node(node_element, "AlarmSetups");
    rootNode->append_node(alarmsNode);
    doc.append_node(rootNode);

    string data;
    rapidxml::print(back_inserter(data), doc);
    saveXmlConfigDoc(data);
}

void AlarmController::appendNode(xml_document<> &doc, xml_node<> *nodeParent, string name, char *value,
                                 size_t valueSize) {
    auto addedNestedNode = doc.allocate_node(node_element, doc.allocate_string(name.c_str(), name.size()));
    addedNestedNode->value(doc.allocate_string(value, valueSize));
    nodeParent->append_node(addedNestedNode);
}

void AlarmController::appendNode(xml_document<> &doc, xml_node<> *nodeParent, string name, string &value) {
    appendNode(doc, nodeParent, name, (char *) value.c_str(), value.size());
}
