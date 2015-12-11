#include "Source/MusicPlayer.h"
#include <iostream>

int main(int argc, char* argv[]) {
    MusicPlayer mc;
    mc.addSoundFilesFromDir(argv[1]);
    mc.playRandomSoundFile();

    cout << "Any input + ENTER to stop" << endl;
    string input;
    cin >> input;
    return 0;
}