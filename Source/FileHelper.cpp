//
// Created by ngrande on 12/9/15.
//

#include "FileHelper.h"

string FileHelper::extractFileExtension(const string filename) {
    auto lastInd = filename.find_last_of(".");
    return filename.substr(lastInd + 1);
}

string FileHelper::extractFilePath(const string completeFilePath) {
    auto lastInd = completeFilePath.find_last_of("\\");
    return completeFilePath.substr(0, lastInd - 1);
}

string FileHelper::extractFileName(const string completeFilePath) {
    auto lastInd = completeFilePath.find_last_of("\\");
    return completeFilePath.substr(lastInd +1);
}
