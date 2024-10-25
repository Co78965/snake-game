#ifndef _CONSOLERENDER_H_
#define _CONSOLERENDER_H_

#include "interface\IRender.h"
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>

class ConsoleRender : public IRender {
private:
    void gotoxy(int xpos, int ypos)
    {
        COORD scrn;    
        HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
        scrn.X = xpos; scrn.Y = ypos;
        SetConsoleCursorPosition(hOuput,scrn);
    }
public:
    void drawGame(const std::string& playerName, int score, int x, int y, const std::vector<IGameObject*>& objects, const int* tailX, const int* tailY, int tailLength) override {
        gotoxy(0, 0);
        for (int i = 0; i < 82; i++) std::cout << "-";
        std::cout << "\n";

        for (int i = 0; i < 20; i++) {
            for (int j = 0; j <= 80; j++) {
                if (j == 0 || j == 80) std::cout << "|";
                else if (i == y && j == x) std::cout << "O";
                else {
                    bool printed = false;

                    for (int k = 0; k < tailLength; k++) {
                        if (tailX[k] == j && tailY[k] == i) {
                            std::cout << "o";
                            printed = true;
                            break;
                        }
                    }

                    if (!printed) {
                        for (auto obj : objects) {
                            if (obj->getX() == j && obj->getY() == i) {
                                std::cout << obj->getSymbol();
                                printed = true;
                                break;
                            }
                        }
                    }

                    if (!printed) std::cout << " ";
                }
            }
            std::cout << "\n";
        }

        for (int i = 0; i < 82; i++) std::cout << "-";
        std::cout << "\n" << playerName << "'s Score: " << score << std::endl;
    }

    void endGame(int score) override{
        std::cout << "Game Over!\nYour score is " << score << std::endl;
        printf("Press any key...");
        Sleep(100);
        _getch();
        system("cls");
    }
};

#endif
