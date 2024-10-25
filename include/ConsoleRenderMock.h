#ifndef _CONSOLERENDERMOCK_H_
#define _CONSOLERENDERMOCK_H_

#include "interface\IRender.h"
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>

class ConsoleRenderMock : public IRender {
private:
    std::vector<std::vector<int>> coord;
public:
    void gotoxy(int xpos, int ypos)
    {
        COORD scrn;    
        HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
        scrn.X = xpos; scrn.Y = ypos;
        SetConsoleCursorPosition(hOuput,scrn);
    }

    void drawGame(const std::string& playerName, int score, int x, int y, const std::vector<IGameObject*>& objects, const int* tailX, const int* tailY, int tailLength) override {
        gotoxy(0, 0);
        for (int i = 0; i < 82; i++) std::cout << "-";
        std::cout << "\n";

        for (int i = 0; i < 20; i++) {
            for (int j = 0; j <= 80; j++) {
                if (j == 0 || j == 80) std::cout << "|";
                else if (i == y && j == x){
                    std::cout << "O";
                    std::vector<int> temp;
                    temp.push_back(x);
                    temp.push_back(y);
                    coord.push_back(temp);
                }
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
        std::cout << "Coords" << std::endl;
        
        for(auto crd : coord){
            std::cout << "coord: (" << crd[0] << "," << crd[1] << ")" << std::endl;
        }
        coord.clear();
        std::cout << "Game Over!\nYour score is " << score << std::endl;
        printf("Press any key...\n");
        Sleep(100);
        _getch();
        system("cls");
    }
};

#endif
