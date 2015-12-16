//
// Created by ngrande on 12/11/15.
//

#ifndef PIALARM_STANDARDMODE_H
#define PIALARM_STANDARDMODE_H


#include "ISoundMode.h"
#include "SoundPlayer.h"

class StandardMode : public ISoundMode {
private:
    ISound *sound;
    ISoundEngine *engine;
public:
    virtual void startPlayback(const SoundFile &musicFile) override;

    virtual void stopPlayback() override;
};


#endif //PIALARM_STANDARDMODE_H
