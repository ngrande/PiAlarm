//
// Created by ngrande on 12/11/15.
//

#include <chrono>
#include "WakeUpMode.h"

void WakeUpMode::PlaySound(const MusicFile *musicFile) {
    stopSound = false;
    MusicFile musicFileCopy;
    musicFileCopy.dir = musicFile->dir;
    musicFileCopy.name = musicFile->name;
    backgroundPlayer = thread(&WakeUpMode::PlayBackground, this, musicFileCopy);
}

void WakeUpMode::StopSound() {
    stopSound = true;
}

void WakeUpMode::PlayBackground(const MusicFile musicFile) {
    auto engine = createIrrKlangDevice();

    string path = musicFile.dir + "/" + musicFile.name;
    auto sound = engine->play3D(path.c_str(), vec3df(0, 0, 0), true, false, true);
    if (sound) {
        sound->setMinDistance(5.0f);
        float posOnCircle = 0;
        const float radius = 5;
        srand(time(NULL));

        while (!stopSound) {
            posOnCircle += 0.04f;
            vec3df pos3d(radius * cosf(posOnCircle), 0, radius * sinf(posOnCircle * 0.5f));

            engine->setListenerPosition(vec3df(0, 0, 0), vec3df(0, 0, 1));

            sound->setPosition(pos3d);


            int playPos = sound->getPlayPosition();


            vec3df pos(fmodf((float) rand(), radius * 2) - radius, 0, 0);

            engine->play3D("falcon.wav", pos);
            long sleepMs = rand() % 120000 + 30000; // between 2 min and 30 sec.
            this_thread::sleep_for(chrono::milliseconds(sleepMs));
        }
    }

    if (sound)
        sound->drop();
}
