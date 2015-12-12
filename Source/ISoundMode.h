//
// Created by ngrande on 12/11/15.
//

#ifndef PIALARM_ISOUNDMODE_H
#define PIALARM_ISOUNDMODE_H
#include <irrKlang.h>

struct MusicFile;

using namespace irrklang;


class ISoundMode {
public:
    virtual void playSound(const MusicFile *musicFile) = 0;

    virtual void stopSound() = 0;
};


#endif //PIALARM_ISOUNDMODE_H
