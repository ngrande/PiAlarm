//
// Created by ngrande on 12/11/15.
//

#ifndef PIALARM_STANDARDMODE_H
#define PIALARM_STANDARDMODE_H


#include "ISoundMode.h"
#include "MusicPlayer.h"

class StandardMode : public ISoundMode {
private:
    ISound *sound;
    ISoundEngine *engine;
public:
    virtual void playSound(const MusicFile *musicFile) override;

    virtual void stopSound() override;
};


#endif //PIALARM_STANDARDMODE_H
