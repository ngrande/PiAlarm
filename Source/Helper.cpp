//
// Created by ngrande on 12/9/15.
//

#include "Helper.h"

string Helper::extractFileExtension(const string filename) {
    auto lastInd = filename.find_last_of(".");
    return filename.substr(lastInd + 1);
}

string Helper::extractFilePath(const string completeFilePath) {
    auto lastInd = completeFilePath.find_last_of("\\");
    return completeFilePath.substr(0, lastInd - 1);
}

string Helper::extractFileName(const string completeFilePath) {
    auto lastInd = completeFilePath.find_last_of("\\");
    return completeFilePath.substr(lastInd + 1);
}

void Helper::separate(string *buffer, const string input, char separator) {
//    int appearanceCount = countAppearance(input, ',');

    int ind = 0;
    string temp;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] != separator) {
            temp += input[i];
        }
        else {
            buffer++[0] = temp;
            temp = "";
        }
    }

    buffer[0] = temp;
}

int Helper::countAppearance(const string input, char searchChar) {
    int count = 0;

//    for_each(0, size - 1, [](char c) { if (c == searchChar) { count++; }});
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == searchChar) {
            count++;
        }
    }
    return count;
}
