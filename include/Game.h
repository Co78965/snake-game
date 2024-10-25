#ifndef _GAME_H_
#define _GAME_H_

#include "Snake.h"
#include "interface\IRender.h"
#include "interface\IUserInput.h"
#include "Food.h"
#include "Obstacle.h"
#include <vector>

class Game {
private:
    Snake snake;
    IRender* render;
    IUserInput* input;
    std::vector<IGameObject*> objects;
    int score;
    bool isGameOver;

public:
    Game(IRender* render, IUserInput* input, int xx = rand() % 80, int yy = rand() % 20) : snake(40, 10), render(render), score(0), input(input), isGameOver(false) {
        // std::cout << xx << " " << yy << std::endl;
        
        objects.push_back(new Food(xx, yy));
        objects.push_back(new Obstacle(rand() % 80, rand() % 20));
        objects.push_back(new Obstacle(rand() % 80, rand() % 20));
    }

    ~Game() {
        for (auto obj : objects) {
            delete obj;
        }
    }

    std::string getUserName(){
        return input->userName();
    }

    char getUserInput(){
        return input->userMove();
    }

    void update_direction(char direction){
         switch (direction) {
            case 'a': snake.setDirection(Snake::LEFT); break;
            case 'd': snake.setDirection(Snake::RIGHT); break;
            case 'w': snake.setDirection(Snake::UP); break;
            case 's': snake.setDirection(Snake::DOWN); break;
            case 'x': isGameOver = true; break;
        }
    }
    
    void update() {  
        snake.move();
        for (auto obj : objects) {
            Food* food = dynamic_cast<Food*>(obj);
            if (food && snake.getX() == food->getX() && snake.getY() == food->getY()) {
                score += 10;
                food->regenerate(80, 20);
                snake.grow();
                snake.move();
            }
        }

        for (auto obj : objects) {
            Obstacle* obstacle = dynamic_cast<Obstacle*>(obj);
            if (obstacle && snake.getX() == obstacle->getX() && snake.getY() == obstacle->getY()) {
                isGameOver = true;
            }
        }

        if (snake.checkCollision(80, 20)) {
            isGameOver = true;
        }
    }

    void renderGame(const std::string& playerName) {
        render->drawGame(playerName, score, snake.getX(), snake.getY(), objects, snake.getTailX(), snake.getTailY(), snake.getTailLength());
    }

    bool gameOver() const {
        return isGameOver;
    }

    int getScore(){
        return score;
    }

    void gameEnd(){
        isGameOver = false;
        render->endGame(score);
        snake.reload();
        score = 0;
    }
};

#endif