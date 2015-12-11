#include "Source/MusicPlayer.h"
#include "Source/WakeUpMode.h"
#include <iostream>

int main(int argc, char* argv[]) {
    MusicPlayer mc;
    mc.addSoundFilesFromDir(argv[1]);
    WakeUpMode wakeUpMode;
    mc.playRandomSoundFile(&wakeUpMode);

    cout << "Any input + ENTER to stop" << endl;
    string input;
    cin >> input;
    return 0;
}