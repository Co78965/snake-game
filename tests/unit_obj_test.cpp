#include <iostream>
#include "..\include\Food.h"
#include "..\include\Obstacle.h"

int main(){
    // ТЕСТ 1: проверка инициализации объекта
    int arr_x[4] = {1,5,14,77};
    int arr_y[4] = {18, 15, 4, 2};

    bool flag_food;
    bool flag_obst;

    for(int i = 0; i < 4; i++){
        Food apple(arr_x[i], arr_y[i]);
        flag_food = apple.getX() == arr_x[i] && arr_y[i] == apple.getY() ? true : false;
    } 
    flag_food ? printf("\x1B[32mFood Initialization: Passed\033[0m\n") : printf("\x1B[31mFood Initialization: Not passed\033[0m\n");
    
    for(int i = 0; i < 4; i++){
        Obstacle obstacle(arr_x[i], arr_y[i]);
        flag_obst = obstacle.getX() == arr_x[i] && arr_y[i] == obstacle.getY() ? true : false;
    } 
    flag_obst ? printf("\x1B[32mObstacle Initialization: Passed\033[0m\n") : printf("\x1B[31mObstacle Initialization: Not passed\033[0m\n");
    
}