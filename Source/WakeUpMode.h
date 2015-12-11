//
// Created by ngrande on 12/11/15.
//

#ifndef PIALARM_WAKEUPMODE_H
#define PIALARM_WAKEUPMODE_H

#include "ISoundMode.h"
#include "MusicPlayer.h"
#include <thread>

class WakeUpMode : public ISoundMode {
private:
    thread backgroundPlayer;
    bool stopSound;
    void PlayBackground(const MusicFile musicFile);

public:
    virtual void StopSound() override;

    virtual void PlaySound(const MusicFile *musicFile) override;

};


#endif //PIALARM_WAKEUPMODE_H
