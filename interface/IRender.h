#ifndef _IRENDER_H_
#define _IRENDER_H_

#include <string>
#include <vector>
#include "IGameObject.h"

class IRender {
public:
    virtual ~IRender() = default;
    virtual void endGame(int score) = 0;
    virtual void drawGame(const std::string& playerName, int score, int x, int y, const std::vector<IGameObject*>& objects, const int* tailX, const int* tailY, int tailLength) = 0;
};

#endif
