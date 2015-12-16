//
// Created by ngrande on 12/9/15.
//

#ifndef PIALARM_FILEHELPER_H
#define PIALARM_FILEHELPER_H

#include <string>

using namespace std;

class Helper {
public:
    static string extractFileExtension(const string &filename);

    static string extractFilePath(const string &completeFilePath);

    static string extractFileName(const string &completeFilePath);

    static void separate(string *buffer, const string &input, char separator);

    static int countAppearance(const string &input, char searchChar);
};


#endif //PIALARM_FILEHELPER_H
