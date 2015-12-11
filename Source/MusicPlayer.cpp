//
// Created by ngrande on 12/9/15.
//

#include "MusicPlayer.h"
#include "FileHelper.h"
#include "WakeUpMode.h"
#include <dirent.h>

void MusicPlayer::playRandomSoundFile(ISoundMode *mode) {
    srand(time(NULL));
    ulong rndNum = rand() % soundFileVector.size();
    auto musicFile = soundFileVector[rndNum];

    startPlayback(mode, &musicFile);
}

MusicPlayer::MusicPlayer() {
    soundFileVector = vector<MusicFile>();
    engine = createIrrKlangDevice();
}

void MusicPlayer::addSoundFilesFromDir(const char *dir) {
    auto *dirp = opendir(dir);

    while (true) {
        auto *direntp = readdir(dirp);
        if (direntp == nullptr)
            break;
        auto extension = FileHelper::extractFileExtension(direntp->d_name);
        if (extension.compare("mp3") == 0 || extension.compare("wav") == 0 || extension.compare("flac") == 0) {
            MusicFile musicFile;
            musicFile.dir = dir;
            musicFile.name = direntp->d_name;
            soundFileVector.push_back(musicFile);
        }
    }
    closedir(dirp);

}

void MusicPlayer::addSoundFile(const char *filePath) {
    MusicFile musicFile;
    musicFile.dir = FileHelper::extractFilePath(filePath);
    musicFile.name = FileHelper::extractFileName(filePath);
    soundFileVector.push_back(musicFile);
}

void MusicPlayer::playSoundFile(ISoundMode *mode, int index) {
    auto musicFile = soundFileVector[index];
    startPlayback(mode, &musicFile);
}

MusicPlayer::~MusicPlayer() {
    if (engine)
        engine->drop();
}

void MusicPlayer::stopPlayback() {
    if (currSoundMode)
        currSoundMode->StopSound();
}

void MusicPlayer::startPlayback(ISoundMode *soundMode, const MusicFile *musicFile) {
    currSoundMode = soundMode;
    currSoundMode->PlaySound(musicFile);
}
