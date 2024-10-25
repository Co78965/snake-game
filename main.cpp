#include "include\ConsoleRender.h"
#include "include\KeyBoardInput.h"
#include "include\Game.h"
#include <iostream>

int main() {
    ConsoleRender render;
    
    while(1){
        KeyBoard input;
        Game game(&render, &input);
        std::string playerName = game.getUserName();
        while (!game.gameOver()) {
            game.renderGame(playerName);
            
            game.update_direction(game.getUserInput()); 
            
            game.update();
            Sleep(100); 
        }
        game.gameEnd();
    }
    return 0;
}
