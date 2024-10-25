#pragma once
#include "..\interface\IGameObject.h"

class Obstacle : public IGameObject {
private:
    int x, y;
    char symbol;

public:
    Obstacle(int startX, int startY) : x(startX), y(startY), symbol('|') {}

    void move() override {}

    int getX() const override {
        return x;
    }

    int getY() const override {
        return y;
    }

    char getSymbol() const override {
        return symbol;
    }
};