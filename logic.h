#ifndef LOGIC_H
#define LOGIC_H

#include <math.h>

class logic
{
public:
    logic();
    void setLeftNum(double var){leftNum=var;}
    void setRightNum(double var){rightNum=var;}
    void setDelimiter(char var){delimiter=var;}
    double getLeftNum(){return leftNum;}
    double getResult(){return result;}
    char getDelimiter(){return delimiter;}
    void calc();

private:
    double leftNum;
    double rightNum;
    char delimiter;
    double result;
};

#endif // LOGIC_H
