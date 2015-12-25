//
// Created by ngrande on 12/9/15.
//

#include "SoundPlayer.h"
#include "Utils/Helper.h"
#include <dirent.h>
#include <rapidxml.hpp>

using namespace rapidxml;

void SoundPlayer::playRandomSoundFile(ISoundMode *mode) {
    srand((uint) time(NULL));
    ulong rndNum = rand() % soundFileVector.size();
    auto musicFile = soundFileVector[rndNum];

    startPlayback(mode, musicFile);
}

SoundPlayer::SoundPlayer() {
//    soundFileVector = vector<SoundFile>();
    // loadAlarmSetups();
}

void SoundPlayer::addSoundFilesFromDir(const char *dir) {
    auto *p_dir = opendir(dir);

    while (true) {
        auto *p_dir_entry = readdir(p_dir);
        if (p_dir_entry == nullptr)
            break;
        auto extension = Helper::extractFileExtension(p_dir_entry->d_name);
        if (extension.compare("mp3") == 0 || extension.compare("wav") == 0 || extension.compare("flac") == 0) {
            SoundFile musicFile;
            musicFile.dir = dir;
            musicFile.name = p_dir_entry->d_name;
            soundFileVector.push_back(musicFile);
        }
    }
    closedir(p_dir);
}

void SoundPlayer::addSoundFile(const char *filePath) {
    SoundFile musicFile;
    musicFile.dir = Helper::extractFilePath(filePath);
    musicFile.name = Helper::extractFileName(filePath);
    soundFileVector.push_back(musicFile);
}

void SoundPlayer::playSoundFile(ISoundMode *mode, int index) {
    auto musicFile = soundFileVector[index];
    startPlayback(mode, musicFile);
}

SoundPlayer::~SoundPlayer() {
}

void SoundPlayer::stopPlayback() {
    if (currSoundMode)
        currSoundMode->stopPlayback();
}

void SoundPlayer::startPlayback(ISoundMode *soundMode, const SoundFile &musicFile) {
    currSoundMode = soundMode;
    currSoundMode->startPlayback(musicFile);
}

void SoundPlayer::playSoundFile(ISoundMode *mode, const char *filePath) {
    SoundFile musicFile;
    musicFile.dir = Helper::extractFilePath(filePath);
    musicFile.name = Helper::extractFileName(filePath);
    startPlayback(mode, musicFile);
}
