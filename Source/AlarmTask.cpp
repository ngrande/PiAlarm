//
// Created by ngrande on 12/24/15.
//

#include "AlarmTask.h"

void AlarmTask::onTimeExceeded() {
    soundPlayer->playSoundFile(soundMode, soundPath.c_str());
}
