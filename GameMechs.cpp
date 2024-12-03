#include "GameMechs.h"
#include "MacUILib.h"
#include "Player.h"


//constructor
GameMechs::GameMechs()
{

    score = 0;
    input = 0;

    exitFlag = false;
    loseFlag = false;


    BoardLength = 30;
    BoardHeight = 15;

}
//additional constructor
GameMechs::GameMechs(int boardX, int boardY)
{

    score = 0;
    input = 0;

    exitFlag = false;
    loseFlag = false;


    BoardLength = boardX;
    BoardHeight = boardY;


}

// do you need a destructor?
GameMechs::~GameMechs()
{
    //theres nothing on heap so no
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

return BoardLength;

}

int GameMechs::getBoardSizeY() const
{

    return BoardHeight;

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


void GameMechs::generateFood(objPos blockedSpace)
{
    srand(time(NULL));
    bool ValidPos = false;
    
    // Keep generating food untill you find a valid position
    while (!ValidPos)
    {
        int randomX = rand() % (BoardLength - 2) + 1;
        int randomY = rand() % (BoardHeight - 2) + 1;
        
        // make sure food is not placed in the same place as a player 
        if (randomX == blockedSpace.pos->x && randomY == blockedSpace.pos->y)
        {
            continue;
        }

        //set the food position to random coords
        FoodPos.setObjPos(randomX, randomY, 'o');
        ValidPos = true;
    }
}

objPos GameMechs::getFoodPos() const
{
    return FoodPos;
}