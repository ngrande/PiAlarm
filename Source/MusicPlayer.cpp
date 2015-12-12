//
// Created by ngrande on 12/9/15.
//

#include "MusicPlayer.h"
#include "FileHelper.h"
#include "WakeUpMode.h"
#include <dirent.h>

void MusicPlayer::playRandomSoundFile(ISoundMode *mode) {
    srand((uint) time(NULL));
    ulong rndNum = rand() % soundFileVector.size();
    auto musicFile = soundFileVector[rndNum];

    startPlayback(mode, &musicFile);
}

MusicPlayer::MusicPlayer() {
    soundFileVector = vector<MusicFile>();
}

void MusicPlayer::addSoundFilesFromDir(const char *dir) {
    auto *p_dir = opendir(dir);

    while (true) {
        auto *p_dir_entry = readdir(p_dir);
        if (p_dir_entry == nullptr)
            break;
        auto extension = FileHelper::extractFileExtension(p_dir_entry->d_name);
        if (extension.compare("mp3") == 0 || extension.compare("wav") == 0 || extension.compare("flac") == 0) {
            MusicFile musicFile;
            musicFile.dir = dir;
            musicFile.name = p_dir_entry->d_name;
            soundFileVector.push_back(musicFile);
        }
    }
    closedir(p_dir);
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
}

void MusicPlayer::stopPlayback() {
    if (currSoundMode)
        currSoundMode->stopSound();
}

void MusicPlayer::startPlayback(ISoundMode *soundMode, const MusicFile *musicFile) {
    currSoundMode = soundMode;
    currSoundMode->playSound(musicFile);
}
