//
// Created by ngrande on 12/9/15.
//

#ifndef PIALARM_MUSICPLAYER_H
#define PIALARM_MUSICPLAYER_H
#include <vector>
#include <map>
#include <string>
using namespace std;

class MusicPlayer {
private:
    map<string, string> soundFileMap;
public:
    MusicPlayer();
    void addSoundFilesFromDir(const char *dir);
    void addSoundFile(const char *filePath);
    void playRandomSoundFile() const;
    void playSoundFile(string name) const;
};


#endif //PIALARM_MUSICPLAYER_H
