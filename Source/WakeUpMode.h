//
// Created by ngrande on 12/11/15.
//

#ifndef PIALARM_WAKEUPMODE_H
#define PIALARM_WAKEUPMODE_H

#include "ISoundMode.h"
#include "SoundPlayer.h"
#include <thread>

class WakeUpMode : public ISoundMode {
private:
    thread backgroundPlayerThread;
    bool isStopping;

    void PlayBackground(const SoundFile musicFile);
public:
    virtual void stopSound() override;

    virtual void playSound(const SoundFile *musicFile) override;

};


#endif //PIALARM_WAKEUPMODE_H
