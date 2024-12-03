#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h" 

class Player
{
    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP}; //direction states

        Player(GameMechs* thisGMRef);
        ~Player(); // destructor

        objPos getPlayerPos() const;

        void updatePlayerDir();
        void movePlayer();
        void growSnake(); 
        const objPosArrayList& getBodyList() const;

    private:
        objPos playerPos; 
        enum Dir myDir;  
        GameMechs* mainGameMechsRef; //ref to main game mechanisms
        objPosArrayList bodyList; 
};

#endif