//
// Created by ngrande on 12/24/15.
//

#ifndef PIALARM_ALARMTASK_H
#define PIALARM_ALARMTASK_H


#include "Utils/ITask.h"
#include "SoundPlayer.h"
#include "StandardMode.h"
#include <string>
#include <condition_variable>

using namespace std;

class AlarmTask : public ITask {
private:
    string name;
    string message;
    string soundPath;
    SoundPlayer *soundPlayer;
    ISoundMode *soundMode;

public:
    AlarmTask(SoundPlayer *soundPlayer, ISoundMode *soundMode, string name, string message, string soundPath)
            : soundPlayer(soundPlayer), soundMode(soundMode), name(name), message(message), soundPath(soundPath) { };

    virtual void onTimeExceeded() override;
};


#endif //PIALARM_ALARMTASK_H
