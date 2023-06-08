#pragma once

#include "Tape.h"
#include <iostream>
#include <fstream>
#include <string> 
#include <vector>
#include <windows.h>
#include <algorithm>

class myTape : Tape {
public:
    myTape(std::string filestring, std::string settingsstring);
    int readNumber();
    void writeNumber(int myNumber);
    bool moveRight();
    bool moveLeft();
    bool changepos(int mypos);
    int getsize();
private:
    std::string fileName;
    std::string settingName;
    int readdelay = 0;
    int writedelay = 0;
    int changeposdelay = 0;
    int pos = 0;
    int size = 0;
};
