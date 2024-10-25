#include "interface/IUserInput.h"
#include <vector>

class Bot : public IUserInput{
private:
    int indexEnd;
    int indexStart;
    std::vector<int>move;
public:
    Bot(std::vector<int>move) : move(move), indexStart(0), indexEnd(move.size()) {}

    std::string userName() override{
        return "Bot";
    }
    
    char userMove() override{
        switch (indexEnd == indexStart){
            case true:{
                return 'x';
            }
            case false:{
                ++indexStart;
                return move[indexStart];
            }
        }
    }

    void reload(){
        indexStart = 0;
    }
};