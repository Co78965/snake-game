#ifndef _FOOD_H_
#define _FOOD_H_

#include "..\interface\IGameObject.h"

class Food : public IGameObject {
private:
    int x, y;
    char symbol;

public:
    Food(int width, int height) {
        x = width;
        y = height;
        symbol = '*';
    }

    void move() override {
        // Еда не движется, так что обновлять ничего не нужно
    }

    int getX() const override {
        return x;
    }

    int getY() const override {
        return y;
    }

    char getSymbol() const override {
        return symbol;
    }

    void regenerate(int width, int height) {
        x = rand() % width;
        y = rand() % height;
    }
};

#endif