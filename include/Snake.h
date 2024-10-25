#ifndef _SNAKE_H_
#define _SNAKE_H_

#include <vector>

class Snake {
private:
    int x, y;
    std::vector<int> tailX, tailY;
    int tailLength;
    char symbol;

public:
    enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN } dir;
    
    Snake(int startX, int startY) : x(startX), y(startY), tailLength(0), dir(STOP), symbol('O') {}

    void setDirection(Direction newDir) { dir = newDir; }

    void grow() {
        tailLength++;
        tailX.push_back(x);
        tailY.push_back(y);
    }

    void update_tail(){
        if(tailLength){       
            int prevX = tailX[0];
            int prevY = tailY[0];
            int prev2X, prev2Y;
            tailX[0] = x;
            tailY[0] = y;
            
            for (int i = 1; i < tailLength; i++) {
                prev2X = tailX[i];
                prev2Y = tailY[i];
                tailX[i] = prevX;
                tailY[i] = prevY;
                prevX = prev2X;
                prevY = prev2Y;
            }
        }
    }

    bool checkCollision(int width, int height) const {
        if (x >= width || x <= 0 || y >= height || y < 0) return true;
        
        for (int i = 0; i < tailLength; i++) {
            if (tailX[i] == x && tailY[i] == y)
            {
                return true;
            }
        }
        return false;
    }

    int getX() const { return x; }
    int getY() const { return y; }
    const int* getTailX(){ return tailX.data(); }
    const int* getTailY(){ return tailY.data(); }
    char getSymbol() const  { return symbol; }
    int getTailLength() const { return tailLength; }

    void move() {
        update_tail();
        if (dir == Direction::LEFT) x--;
        else if (dir == Direction::RIGHT) x++;
        else if (dir == Direction::UP) y--;
        else if (dir == Direction::DOWN) y++;
    }

    void reload(){
        x = 40;
        y = 10;
        tailLength = 0;
        tailX.erase(tailX.begin(), tailX.end());
        tailY.erase(tailY.begin(), tailY.end());
        dir = Direction::STOP;
    }
};

#endif
