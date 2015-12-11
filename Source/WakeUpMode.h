//
// Created by ngrande on 12/11/15.
//

#ifndef PIALARM_WAKEUPMODE_H
#define PIALARM_WAKEUPMODE_H

#include "ISoundMode.h"
#include "MusicPlayer.h"

class WakeUpMode : public ISoundMode {
private:
    bool stopSound;
    ISound *sound;
    const char* specialSoundPath = "falcon.wav";
public:
    virtual void StopSound() override;

    virtual void PlaySound(const MusicFile *musicFile) override;

};


#endif //PIALARM_WAKEUPMODE_H
