//
// Created by ngrande on 12/9/15.
//

#ifndef PIALARM_MUSICPLAYER_H
#define PIALARM_MUSICPLAYER_H

#include <vector>
#include <map>
#include <string>
#include <irrKlang.h>
#include <memory>
#include "ISoundMode.h"

using namespace std;
using namespace irrklang;

struct SoundFile {
    string name;
    string dir;
};

struct AlarmSetup {
    string description;
    int hour;
    int minute;
    vector<int> days; // 1 = Monday, 2 = Tuesday, ... 7 = Sunday.
};


class SoundPlayer {
private:
    const char *CONFIG_FILENAME = ".PiAlarm.xml";
    vector<SoundFile> soundFileVector;
    vector<AlarmSetup> alarmSetups;
    ISoundMode *currSoundMode;

    void startPlayback(ISoundMode *soundMode, const SoundFile &musicFile);

    void loadAlarmSetups();

public:
    SoundPlayer();

    ~SoundPlayer();

    void addSoundFilesFromDir(const char *dir);

    void addSoundFile(const char *filePath);

    void playRandomSoundFile(ISoundMode *mode);

    void playSoundFile(ISoundMode *mode, int index);

    void playSoundFile(ISoundMode *mode, const char *filePath);

    void stopPlayback();
};


#endif //PIALARM_MUSICPLAYER_H
