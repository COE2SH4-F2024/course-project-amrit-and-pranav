#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"


using namespace std;

#define DELAY_CONST 100000


//pointers for reference
GameMechs *MyGame;
Player *MyPlayer;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);


int main(void)
{

    Initialize();

    while(MyGame->getLoseFlagStatus() == false) 
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();

    }
        CleanUp();     //if player loses, run clean up function.
    }

void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    MyGame = new GameMechs(); //create instance of game

    MyPlayer=new Player(MyGame); //create instant of player
    
    MyGame->generateFood(MyPlayer->getPlayerPos()); 
}

void GetInput(void)
{
    MyPlayer->updatePlayerDir(); //ppa2 input collection
   
}

void RunLogic(void)
{
    MyPlayer->movePlayer();


    objPos playerPos = MyPlayer->getPlayerPos();
    objPos foodPos = MyGame->getFoodPos();


    // check for player and food collision.
    if (playerPos.isPosEqual(&foodPos))
    {
        //increment the score and generate new food
        MyGame->incrementScore();
        MyPlayer->growSnake();  

        MyGame->generateFood(playerPos);  //playerPos is blocked off from food placement
    
    }
}

void DrawScreen(void)
{
    MacUILib_clearScreen();   

    objPos playerPos = MyPlayer->getPlayerPos(); 
    objPos foodPos = MyGame->getFoodPos();

    int boardX = MyGame->getBoardSizeX();
    int boardY = MyGame->getBoardSizeY();

    // Draw the game board and snake's body
    for(int y = 0; y < boardY; y++)
    {
        for(int x = 0; x < boardX; x++)
        {
            if(y == 0 || y == boardY - 1 || x == 0 || x == boardX - 1 )
            {
                MacUILib_printf("%c", '#');  // Draw borders
            }
            else if(x == foodPos.pos->x && y == foodPos.pos->y)
            {
                MacUILib_printf("%c", foodPos.symbol);  //place food
            }
            else
            {
                // Check if any part of the snake occupies this position
                bool drawn = false;
                const objPosArrayList& bodyList = MyPlayer->getBodyList();
                
                for(int i = 0; i < bodyList.getSize(); i++) {

                    objPos bodySegment = bodyList.getElement(i); //getting coords for snake body

                    //checking if any part of the snake is at the coords
                    if(x == bodySegment.pos->x && y == bodySegment.pos->y) { 

                        MacUILib_printf("%c", bodySegment.symbol);  // Draw the snake body
                        drawn = true;
                        break;
                    }
                }
                if (!drawn) {
                    MacUILib_printf(" ");  // Empty space
                }
            }
        }
        MacUILib_printf("\n");
    }

    //display player's score 
    MacUILib_printf("Score: %d\n", MyGame->getScore());
}


void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    int final_score = MyGame->getScore(); //save score before value is removed off memory
    delete MyGame;
    delete MyPlayer; 
    MacUILib_clearScreen();  
    MacUILib_printf("Game Over!\n");  
    MacUILib_printf("Score: %d\n", final_score); //print score to end game
    MacUILib_uninit();
}