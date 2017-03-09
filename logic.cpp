#include "logic.h"

logic::logic()
{

}


void logic::calc(){

    switch(delimiter){
            case '+': result=leftNum + rightNum;
            break;
            case '-': result=leftNum - rightNum;
            break;
            case '*': result=leftNum * rightNum;
            break;
            case '/': result=leftNum / rightNum;
            break;
            case 's': result=sin(rightNum*(M_PI/180.0f));
            break;
            case 'c': result=cos(rightNum*(M_PI/180.0f));
            break;
            case 'q': result=sqrt(rightNum);
            break;
            case '^': result=pow(leftNum,rightNum);
            break;
        }
}
