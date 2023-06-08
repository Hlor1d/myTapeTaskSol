#include "myTape.h"

myTape::myTape(std::string filestring, std::string settingsstring)
{
    fileName = filestring;
    settingName = settingsstring;
    std::fstream input(fileName, std::ios::in | std::ios::binary);
    if (input.is_open())
    {
        input.seekg(0, std::ios::end);
        size = input.tellg() / sizeof(int);
    }
    pos = 0;
    input.close();
    std::fstream inputset(settingsstring, std::ios::in | std::ios::binary);
    if (inputset.is_open())
    {
        inputset.read(reinterpret_cast<char*>(&readdelay), sizeof(int));
        inputset.read(reinterpret_cast<char*>(&writedelay), sizeof(writedelay));
        inputset.read(reinterpret_cast<char*>(&changeposdelay), sizeof(changeposdelay));
    }
    inputset.close();
}

int myTape::readNumber() {
    std::fstream input(fileName, std::ios::in | std::ios::binary);
    uint32_t a=0;
    if (input.is_open())
    {
        input.seekg(pos * sizeof(int), std::ios_base::beg);
        input.read(reinterpret_cast<char*>(&a), sizeof(a));
        input.close();
    }
    Sleep(readdelay);
    return a;
}

void myTape::writeNumber(int myNumber) {
    std::fstream output(fileName, std::ios::out | std::ios::in | std::ios::binary);
    if (output.is_open())
    {
        output.seekp(pos * sizeof(myNumber), std::ios_base::beg);
        output.write((char*)&myNumber, sizeof(myNumber));
        output.close();
    }
    Sleep(writedelay);
}

bool myTape::moveRight() {
    if (pos == size - 1) return false;
    pos++;
    Sleep(changeposdelay);
    return true;
}

bool myTape::moveLeft() {
    if (pos == 0) return false;
    pos--;
    Sleep(changeposdelay);
    return true;
}

bool myTape::changepos(int mypos) {
    bool mybool = false;
    if ((mypos >= 0) && (mypos < size))
    {
        for (int i = 0; i < abs(pos - mypos); i++) {
            Sleep(changeposdelay);
        }
        pos = mypos;
        mybool = true;
    }
    return mybool;
}

int myTape::getsize() {
    return size;
}