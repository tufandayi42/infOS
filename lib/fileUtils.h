#ifndef FILEUTILS_H
#define FILEUTILS_H

#include "infLib.h"

using namespace std;

string readFile(string fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "[ERR] Could not open file " << fileName << endl;
    }
    ostringstream oss;
    oss << file.rdbuf();
    return oss.str();
}

void writeFile(string fileName, string content) {
    ofstream file(fileName);
    if (!file.is_open()) {
        cout << "[ERR] Could not open file " << fileName << endl;
    }
    file << content;
}

string readLine(string fileName, int line) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "[ERR] Could not open file " << fileName << endl;
        return "";
    }

    string lineContent;
    for (int i = 0; i < line; ++i) {
        if (!getline(file, lineContent)) {
            cout << "[ERR] Reached end of file before reaching line " << line << endl;
            return "";
        }
    }

    return lineContent;
}

void writeLine(string filename, int line, string text) {
    ifstream infile(filename);
    vector<string> lines;
    string currentLine;
    int currentLineNumber = 1;

    while (getline(infile, currentLine)) {
        lines.push_back(currentLine);
    }
    infile.close();

    if (line > 0 && line <= lines.size()) {
        lines[line - 1] = text;
    } else if (line == lines.size() + 1) {
        lines.push_back(text);
    } else {
         cout << "[ERR] Reached end of file before reaching line " << line << endl;
        return;
    }

    ofstream outfile(filename);
    for (const auto& outLine : lines) {
        outfile << outLine << endl;
    }
}


#endif