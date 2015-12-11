//
// Created by ngrande on 12/9/15.
//

#include "MusicPlayer.h"
#include "FileHelper.h"
#include <dirent.h>

void MusicPlayer::playRandomSoundFile() {
    srand(time(NULL));
    ulong rndNum = rand() % soundFileVector.size();
    auto musicFile = soundFileVector[rndNum];
    playback(&musicFile);
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

void MusicPlayer::playSoundFile(int index) {
    auto musicFile = soundFileVector[index];
    playback(&musicFile);
}

void MusicPlayer::playback(const MusicFile *musicFile) {
    string path = musicFile->dir + "/" + musicFile->name;
    sound = engine->play2D(path.c_str(), true, true);
    if (sound) {
        sound->setIsPaused(false);
    }
}

MusicPlayer::~MusicPlayer() {
    if (engine)
        engine->drop();
}

void MusicPlayer::stopPlayback() {
    if (sound)
        sound->drop();
}
