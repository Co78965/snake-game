#ifndef _KEYBOARDINPUT_H_
#define _KEYBOARDINPUT_H_

#include <iostream>
#include "interface\IUserInput.h"
#include "string.h"
#include <conio.h>
#include <windows.h>

class KeyBoard : public IUserInput{
public:
        std::string userName() override{
            std::string playerName;
            std::cout << "Enter your name: ";
            std::cin >> playerName;
            return playerName;
        }

        char userMove() override{
            if (_kbhit()) { 
                char key = _getch();
                return key;
            }
        }
};
#endif