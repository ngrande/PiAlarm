//
// Created by ngrande on 12/11/15.
//

#include "StandardMode.h"

void StandardMode::playSound(const MusicFile *musicFile) {
    engine = createIrrKlangDevice();

    string path = musicFile->dir + "/" + musicFile->name;
    sound = engine->play2D(path.c_str(), true, true);
    if (sound) {
        sound->setIsPaused(false);
    }
}

void StandardMode::stopSound() {
    if (sound)
        sound->drop();

    if (engine)
        engine->drop();
}
