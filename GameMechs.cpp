#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{

    score = 0;
    input = 0;

    exitFlag = false;
    loseFlag = false;


    boardSizeX = 30;
    boardSizeY = 15;

}

GameMechs::GameMechs(int boardX, int boardY)
{

    score = 0;
    input = 0;

    exitFlag = false;
    loseFlag = false;


    boardSizeX = boardX;
    boardSizeY = boardY;


}

// do you need a destructor?
GameMechs::~GameMechs()
{
    //nothing on heap at the moment so no.
}

bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;

}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;

}
    
char GameMechs::getInput()
{
    if(MacUILib_hasChar())
    {
        input = MacUILib_getChar();
    }
    return input;
}

int GameMechs::getScore() const
{

return score;

}

void GameMechs::incrementScore()
{
    score++;
    
}

int GameMechs::getBoardSizeX() const
{

return boardSizeX;

}

int GameMechs::getBoardSizeY() const
{

    return boardSizeY;


}


void GameMechs::setExitTrue()
{
    exitFlag = true;

}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
    
}

void GameMechs::setInput(char this_input)
{

input = this_input;

}

void GameMechs::clearInput()
{

    input = 0;

}

void GameMechs::generateFood(objPos blockOff)
{

}

objPos GameMechs::getFoodPos() const
{
    return food;
}


// More methods should be added here