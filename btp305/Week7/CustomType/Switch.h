//Switch.h - declarations for a switch

#ifndef _SWITCH_H_
#define _SWITCH_H_

enum class StateType
{
    boolean,//true
    character,//'O'
    number//1
};

typedef struct
{
    char name[20];
    StateType sType;
    union
    {
        bool stateAsBool;
        char stateAsChar;
        int stateAsNum;
    } sState;
} Switch;

#endif// _SWITCH_H_
