//
// Created by ngrande on 12/9/15.
//

#ifndef PIALARM_FILEHELPER_H
#define PIALARM_FILEHELPER_H
#include <string>
using namespace std;

class FileHelper {
public:
    static string extractFileExtension(const string filename);
    static string extractFilePath(const string completeFilePath);
    static string extractFileName(const string completeFilePath);
};


#endif //PIALARM_FILEHELPER_H
