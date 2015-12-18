#include "Source/SoundPlayer.h"
#include "Source/Utils/Scheduler.h"
#include <iostream>

class TaskImplementation : public ITask {
public:
    virtual void onTimeExceeded() const override {
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
//    SoundPlayer mc;
//    mc.addSoundFilesFromDir(argv[1]);
//    WakeUpMode wakeUpMode;
//    mc.playRandomSoundFile(&wakeUpMode);
//
//    cout << "Press <ENTER> to stop" << endl;
//    cin.ignore();
//
//    mc.stopPlayback();
//
//    cout << "Playback stopped." << endl;


    Scheduler scheduler;
    TaskImplementation taskImplementationPtr;

    scheduler.addTask(&taskImplementationPtr, 7, 0, 0, 0, true);
    cout << "Task added to scheduler..." << endl;
    cout << "Starting scheduler..." << endl;
    scheduler.start();
    cout << "Press ENTER to exit." << endl;
    cin.ignore();
    scheduler.stop();
    return 0;
}