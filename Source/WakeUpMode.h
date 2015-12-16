//
// Created by ngrande on 12/11/15.
//

#ifndef PIALARM_WAKEUPMODE_H
#define PIALARM_WAKEUPMODE_H

#include "ISoundMode.h"
#include "SoundPlayer.h"
#include <thread>
#include <condition_variable>

using namespace std;

class WakeUpMode : public ISoundMode {
private:
    thread backgroundPlayerThread;
    bool isStopping;
    condition_variable cv; // used to synchronize / block other threads
    mutex cv_m; // used to protect shared data

    void PlayBackground(const SoundFile &musicFile);

public:
    virtual void stopPlayback() override;

    virtual void startPlayback(const SoundFile &musicFile) override;

};


#endif //PIALARM_WAKEUPMODE_H
