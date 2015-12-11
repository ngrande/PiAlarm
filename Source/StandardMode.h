//
// Created by ngrande on 12/11/15.
//

#ifndef PIALARM_STANDARDMODE_H
#define PIALARM_STANDARDMODE_H


#include "ISoundMode.h"
#include "MusicPlayer.h"

class StandardMode: public ISoundMode {
private:
    ISound* sound;
public:
    virtual void PlaySound(const MusicFile *musicFile) override;

    virtual void StopSound() override;
};


#endif //PIALARM_STANDARDMODE_H
