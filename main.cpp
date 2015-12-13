#include "Source/SoundPlayer.h"
#include "Source/WakeUpMode.h"
#include <iostream>

int main(int argc, char* argv[]) {
    SoundPlayer mc;
    mc.addSoundFilesFromDir(argv[1]);
    WakeUpMode wakeUpMode;
    mc.playRandomSoundFile(&wakeUpMode);

    cout << "Press <ENTER> to stop" << endl;
    cin.ignore();

    mc.stopPlayback();

    cout << "Playback stopped." << endl;

    int seconds = 0;
    cout << "Waiting " << seconds << " seconds before exit." << endl;
    this_thread::sleep_for(chrono::seconds(seconds));
    return 0;
}