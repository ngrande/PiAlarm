//
// Created by ngrande on 12/11/15.
//

#include "StandardMode.h"

void StandardMode::startPlayback(const SoundFile &musicFile) {
    engine = createIrrKlangDevice();

    string path = musicFile.dir + "/" + musicFile.name;
    sound = engine->play2D(path.c_str(), true, true);
    if (sound) {
        sound->setIsPaused(false);
    }
}

void StandardMode::stopPlayback() {
    if (sound)
        sound->drop();

    if (engine)
        engine->drop();
}
