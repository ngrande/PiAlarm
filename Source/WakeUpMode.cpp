//
// Created by ngrande on 12/11/15.
//

#include <chrono>
#include "WakeUpMode.h"

void WakeUpMode::playSound(const SoundFile *musicFile) {
    isStopping = false;
    SoundFile musicFileCopy;
    musicFileCopy.dir = musicFile->dir;
    musicFileCopy.name = musicFile->name;
    backgroundPlayerThread = thread(&WakeUpMode::PlayBackground, this, musicFileCopy);
}

void WakeUpMode::stopSound() {
    isStopping = true;
    backgroundPlayerThread.join();
}

void WakeUpMode::PlayBackground(const SoundFile musicFile) {
    auto engine = createIrrKlangDevice();

    string path = musicFile.dir + "/" + musicFile.name;
    auto sound = engine->play3D(path.c_str(), vec3df(0, 0, 0), true, false, true);
    if (sound) {
        sound->setMinDistance(5.0f);
        float posOnCircle = 0;
        const float radius = 5;
        srand((uint) time(NULL));

        while (!isStopping) {
            posOnCircle += 0.04f;
            vec3df pos3d(radius * cosf(posOnCircle), 0, radius * sinf(posOnCircle * 0.5f));

            engine->setListenerPosition(vec3df(0, 0, 0), vec3df(0, 0, 1));

            sound->setPosition(pos3d);

            vec3df pos(fmodf((float) rand(), radius * 2) - radius, 0, 0);

            engine->play3D("falcon.wav", pos);

            //TODO: I do not like the following lines of code... try to change.
            long sleepMs = rand() % 90000 + 30000; // sleep between 30 sec. and 2 min.
            long sleptCounter = 0;
            while (sleepMs > sleptCounter && !isStopping) {
                this_thread::sleep_for(chrono::milliseconds(10));
                sleptCounter += 10;
            }
        }
    }

    engine->stopAllSounds();

    if (sound)
        sound->drop();
    engine->drop();
}
