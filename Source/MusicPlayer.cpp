//
// Created by ngrande on 12/9/15.
//

#include "MusicPlayer.h"
#include "FileHelper.h"
#include <irrKlang.h>
#include <dirent.h>
#include <iostream>

using namespace irrklang;

void MusicPlayer::playRandomSoundFile() const {
    ISoundEngine *engine = createIrrKlangDevice();


    engine->play2D("", true);


    engine->drop();
}

MusicPlayer::MusicPlayer() {
    soundFileMap;
}

void MusicPlayer::addSoundFilesFromDir(const char *dir) {
    auto *dirp = opendir(dir);

    while (true) {
        auto *direntp = readdir(dirp);
        if (direntp == nullptr)
            break;
        cout << direntp->d_name << endl;
        auto extension = FileHelper::extractFileExtension(direntp->d_name);
        if (extension.compare("mp3") == 0 || extension.compare("wav") == 0 || extension.compare("flac") == 0
            || extension.compare("ogg") == 0) {
            soundFileMap[direntp->d_name] = dir;
        }
    }
    closedir(dirp);

}

void MusicPlayer::addSoundFile(const char *filePath) {
    soundFileMap[FileHelper::extractFileName(filePath)] = FileHelper::extractFilePath(filePath);
}

void MusicPlayer::playSoundFile(string name) const {

}
