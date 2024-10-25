#include <iostream>
#include "..\include\Snake.h"

int main(){
    // ТЕСТ 1: проверка инициализации объекта
    int arr_x[4] = {1,5,14,77};
    int arr_y[4] = {18, 15, 4, 2};

    bool flag;

    for(int i = 0; i < 4; i++){
        Snake snake(arr_x[i], arr_y[i]);
        flag = snake.getX() == arr_x[i] && arr_y[i] == snake.getY() ? true : false;
    } 
    flag ? printf("\x1B[32mSnake Initialization: Passed\033[0m\n") : printf("\x1B[31mSnake Initialization: Not passed\033[0m\n");
    
    // ТЕСТ 2: проверка столкновения со стенкой
    Snake s1(20, 10);
    int flag_true = s1.checkCollision(20, 10);

    Snake s2(5, 1);
    int flag_false = s2.checkCollision(15, 10);

    (!flag_false &&  flag_true) ? printf("\x1B[32mSnake Check Collision: Passed\033[0m\n") : printf("\x1B[31mSnake Check Collision: Not passed\033[0m\n");
    

    // ТЕСТ 3: проверка роста змеи

    Snake s_len(20, 10);
    int cor_len = 1000;
    int save_len = s_len.getTailLength();
    
    for(int i = 0; i < cor_len; i++){
        s_len.grow();
    }

    (save_len == 0 &&  s_len.getTailLength() == cor_len) ? printf("\x1B[32mSnake Grow: Passed\033[0m\n") : printf("\x1B[31mSnake Grow: Not passed\033[0m\n");
    
    // ТЕСТ 4: проверка работы движение змеи

    Snake s3(20, 10);
    bool falg4;

    s3.setDirection(Snake::LEFT);
    s3.move();
    s3.grow();
    s3.getX() == 19 && s3.getY() == 10 ? printf("\x1B[32mSnake Move LEFT: Passed\033[0m\n") : printf("\x1B[31mSnake Move LEFT: Not passed\033[0m\n");

    s3.setDirection(Snake::UP);
    s3.move();
    s3.grow();
    s3.getX() == 19 && s3.getY() == 9 ? printf("\x1B[32mSnake Move UP: Passed\033[0m\n") : printf("\x1B[31mSnake Move UP: Not passed\033[0m\n");
    
    s3.setDirection(Snake::RIGHT);
    s3.move();
    s3.grow();
    s3.getX() == 20 && s3.getY() == 9 ? printf("\x1B[32mSnake Move RIGHT: Passed\033[0m\n") : printf("\x1B[31mSnake Move RIGHT: Not passed\033[0m\n");

    s3.setDirection(Snake::DOWN);
    s3.move();
    s3.grow();
    s3.getX() == 20 && s3.getY() == 10 ? printf("\x1B[32mSnake Move DOWN: Passed\033[0m\n") : printf("\x1B[31mSnake Move DOWN: Not passed\033[0m\n");;

    s3.setDirection(Snake::STOP);
    s3.move();
    s3.getX() == 20 && s3.getY() == 10 ? printf("\x1B[32mSnake Move STOP: Passed\033[0m\n") : printf("\x1B[31mSnake Move STOP: Not passed\033[0m\n");;
    

    // ТЕСТ 5: обработка тела змеи
    for(int i = 0; i < 4; i++){
        s3.setDirection(Snake::LEFT);
        s3.move();
        s3.grow();
    }

    for(int i = 3; i >= 0; i--){
        falg4 = s3.getTailX()[i] == 17 + i && s3.getTailY()[i] == 10 ? true : false;
    }

    falg4 ? printf("\x1B[32mSnake update tail: Passed\033[0m\n") : printf("\x1B[31mSnake update tail: Not passed\033[0m\n");;
    return 0;
}