//
// Created by ngrande on 12/9/15.
//

#ifndef PIALARM_MUSICPLAYER_H
#define PIALARM_MUSICPLAYER_H
#include <vector>
#include <map>
#include <string>
#include <irrKlang.h>
#include "ISoundMode.h"

using namespace std;
using namespace irrklang;

struct MusicFile {
    string name;
    string dir;
};


class MusicPlayer {
private:
    vector<MusicFile> soundFileVector;
    ISoundMode *currSoundMode;
    void startPlayback(ISoundMode *soundMode, const MusicFile *musicFile);
public:
    MusicPlayer();
    ~MusicPlayer();
    void addSoundFilesFromDir(const char *dir);
    void addSoundFile(const char *filePath);
    void playRandomSoundFile(ISoundMode *mode);
    void playSoundFile(ISoundMode *mode, int index);
    void stopPlayback();
};


#endif //PIALARM_MUSICPLAYER_H
