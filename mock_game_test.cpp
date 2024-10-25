#include "include\ConsoleRenderMock.h"
#include "include\Bot.h"
#include "include\Game.h"
#include <iostream>

int main() {
    // x = 40;
    // y = 10;
    std::vector<std::vector<int>> ways = {/*(16 == j && 45 == i)*/{'s','s','s','s','s','s','d','d','d', 'd'},{'w','d','d','s','s','a','a','s'},/*Тест на пересечение верхней границы*/{'w','w','w','w','w','w','w','w','w','w'},/*Тест на пересечение нижней границы*/{'s','s','s','s','s','s','s','s','s','s'}};
    
    std::vector<std::vector<std::vector<int>>> coords = {
        {{40,10},{40,11},{40,12},{40,13},{40,14},{40,15}, {41,15},{42,15},{43,15},{44,15},{46,15}},
        {{40,10}, {41,10},{42,10},{42,11},{42,12},{41,12}, {40,12},{40,13}, {40,14}},
        {{40,10}, {40,9},{40,8},{40,7},{40,6},{40,5},{40,4},{40,3},{40,2},{40,1},{40,0}},
        {{40,10}, {40,11},{40,12},{40,13},{40,14},{40,15},{40,16},{40,17},{40,18},{40,19}}
        };
    
    for(int i = 0; i < 4; i++){
        ConsoleRenderMock render;
        Bot input(ways[i]);
        
        Game game(&render, &input, 45, 15);

        std::string playerName = game.getUserName();
        
        while (!game.gameOver()) {
            game.renderGame(playerName);
            
            game.update_direction(game.getUserInput()); 
            
            game.update();
            Sleep(100); 
        }
        std::cout << "Correct coords" << std::endl;
        for(auto crd : coords[i]){
            std::cout << "coord: (" << crd[0] << "," << crd[1] << ")" << std::endl;
        }
        game.gameEnd();
    
    }
    return 0;
}