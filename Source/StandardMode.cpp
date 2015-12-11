//
// Created by ngrande on 12/11/15.
//

#include "StandardMode.h"

void StandardMode::PlaySound(const MusicFile *musicFile) {
    auto engine = createIrrKlangDevice();

    string path = musicFile->dir + "/" + musicFile->name;
    sound = engine->play2D(path.c_str(), true, true);
    if (sound) {
        sound->setIsPaused(false);
    }
}

void StandardMode::StopSound() {
    if (sound)
        sound->drop();
}
