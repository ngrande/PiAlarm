#include "Source/SoundPlayer.h"
#include "Source/Utils/Scheduler.h"
#include <iostream>

class TaskImplementation : public ITask {
public:
    virtual void onTimeExceeded() const override { cout << "I was waiting a few seconds..." << endl; };
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
    shared_ptr<TaskImplementation> taskImplementationPtr(new TaskImplementation);
    shared_ptr<ScheduleTime> timePtr(new ScheduleTime(3, 21, 0, 0));
    scheduler.addTask(taskImplementationPtr, timePtr);
    cout << "Task added to scheduler..." << endl;
    cout << "Starting scheduler..." << endl;
    scheduler.start();
    cin.ignore();
    scheduler.stop();
    return 0;
}