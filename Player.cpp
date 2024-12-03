#include "Player.h"

Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // Initialize player's position in center of board
    playerPos.pos->x = mainGameMechsRef->getBoardSizeX() / 2;
    playerPos.pos->y = mainGameMechsRef->getBoardSizeY() / 2;
    playerPos.symbol = '@';

    // Add player's head to body list (just the head to begin with)
    bodyList.insertHead(playerPos); 

}

void Player::movePlayer()
{
    // Calculate new position for the head of snake
    objPos newHead = playerPos; 

    // Move the head according to current direction
    switch(myDir) {
        case LEFT:
            newHead.pos->x--;  // Move left
            if(newHead.pos->x < 1) {

                newHead.pos->x = mainGameMechsRef->getBoardSizeX() - 2;  // right side wrap-around
            }
            break;
        case RIGHT:
            newHead.pos->x++;  // Move right
            if(newHead.pos->x >= mainGameMechsRef->getBoardSizeX() - 1) {

                newHead.pos->x = 1;  // left side wrap-around
            }
            break;
        case UP:
            newHead.pos->y--;  // Move up
            if(newHead.pos->y < 1) {

                newHead.pos->y = mainGameMechsRef->getBoardSizeY() - 2;  // bottom side wrap-around
            }
            break;
        case DOWN:
            newHead.pos->y++;  // Move down
            if(newHead.pos->y >= mainGameMechsRef->getBoardSizeY() - 1) {

                newHead.pos->y = 1;  //top side wrap-around
            }
            break;
        default:
            break;
    }


    // Check if head position matches any body segment
for (int i = 1; i < bodyList.getSize(); i++) {

        objPos bodySegment = bodyList.getElement(i);

        if (newHead.isPosEqual(&bodySegment)) {

             //If collision detected set lose flag to true in game mechs
            mainGameMechsRef->setLoseFlag();  // Stops game
            return;
        }
    }

    // Insert new head at front of body list
    bodyList.insertHead(newHead);

    bodyList.removeTail();

    // Update players position to new head position
    playerPos = bodyList.getHeadElement();
}


void Player::growSnake()
{
    // add new body element to tail
    objPos newTail = bodyList.getTailElement();

    bodyList.insertTail(newTail); 
}



Player::~Player()
{
    // delete any heap members here
}

objPos Player::getPlayerPos() const
{
    return playerPos;
    // return the reference to the playerPos arrray list
}


void Player::updatePlayerDir()
{
    //ppa3
    char input= mainGameMechsRef->getInput();
    
    switch(input)
         {
        case 'w':
        case 'W':
            if(myDir != UP && myDir != DOWN)
                myDir=UP;
            break;
        case 'a':
        case 'A':
            if(myDir!=LEFT && myDir!=RIGHT)
                myDir=LEFT;
            break;
        case 's':
        case 'S':
            if(myDir!=UP&&myDir!=DOWN)
                myDir=DOWN;
            break;
        case 'd':
        case 'D':
            if(myDir!=LEFT&&myDir!=RIGHT)
            myDir=RIGHT;
            break;
        default:
            break;
    }       
    input=0;   
}

const objPosArrayList& Player::getBodyList() const
{
    return bodyList;  // Return a const reference to bodyList
}