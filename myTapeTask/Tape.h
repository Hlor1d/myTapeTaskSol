#pragma once

class Tape {
public:
    virtual int readNumber() = 0;
    virtual void writeNumber(int) = 0;
    virtual bool moveRight() = 0;
    virtual bool moveLeft() = 0;
    virtual bool changepos(int) = 0;
protected:
    int pos;
    int size;
};

