#include "Source/SoundPlayer.h"
#include "Source/Utils/Scheduler.h"
#include "Source/AlarmController.h"
#include <iostream>

class TaskImplementation : public ITask {
public:
    virtual void onTimeExceeded() override {
        time_t timerNow;
        time(&timerNow); // get current time
        struct tm timeNow;
        localtime_r(&timerNow, &timeNow); // get local time

        char buffer[80];
        strftime(buffer, sizeof(buffer), "Now it is %F %I:%M%p.", &timeNow);
        puts(buffer);
        cout << "I was waiting a few seconds..." << endl;
    };
};

int main(int argc, char *argv[]) {
    cout << "adding new task to the XML file" << endl;
    AlarmController alarmController;
    AlarmSetup alarmSetup;
    alarmSetup.name = "New added alarm";
    alarmSetup.hour = 19;
    alarmSetup.minute = 0;
    alarmSetup.second = 0;
    alarmSetup.soundPath = "/";
    alarmSetup.message = "Stand up as soon as you can!";
    vector<int> daysVector;
    daysVector.push_back(1);
    daysVector.push_back(2);
    alarmSetup.days = daysVector;
    alarmController.addAlarmSetup(alarmSetup);
    cout << "Press ENTER to exit." << endl;
    cin.ignore();
    return 0;
}
