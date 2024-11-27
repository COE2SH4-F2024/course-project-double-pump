#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    playerPos.pos->x = 5;
    playerPos.pos->y = 10;
    playerPos.symbol = '*';

    // more actions to be included
}


Player::~Player()
{   
    delete playerPos.pos;
    delete mainGameMechsRef;
    // delete any heap members here
}

objPos Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPos;
}

void Player::updatePlayerDir()
{
        // PPA3 input processing logic
    char cmd = mainGameMechsRef->getInput();
    switch (myDir)
    {
    case LEFT:
        if (cmd == 'w')
        {
            myDir = UP;
        }
        if (cmd == 's')
        {
            myDir = DOWN;
        }
        break;
    case RIGHT:
        if (cmd == 'w')
        {
            myDir = UP;
        }
        if (cmd == 's')
        {
            myDir = DOWN;
        }
        break;
    case UP:
        if (cmd == 'a')
        {
            myDir = LEFT;
        }
        if (cmd == 'd')
        {
            myDir = RIGHT;
        }
        break;
    case DOWN:
        if (cmd == 'a')
        {
            myDir = LEFT;
        }
        if (cmd == 'd')
        {
            myDir = RIGHT;
        }
        break;

    default:
        if (cmd == 'a')
        {
            myDir = LEFT;
        }
        if (cmd == 'd')
        {
            myDir = RIGHT;
        }
        if (cmd == 'w')
        {
            myDir = UP;
        }
        if (cmd == 's')
        {
            myDir = DOWN;
        }
        break;
    }
          
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    switch (myDir)
    {
    case LEFT:
        playerPos.pos->y--;
        if (playerPos.pos->y < 1)
        {
            playerPos.pos->y = mainGameMechsRef->getBoardSizeX()-2;
        }
        break;
    case RIGHT:
        playerPos.pos->y++;
        if (playerPos.pos->y > mainGameMechsRef->getBoardSizeX()-2)
        {
           playerPos.pos->y = 1;
        }
        break;
    case UP:
        playerPos.pos->x--;
        if (playerPos.pos->x < 1)
        {
            playerPos.pos->x = mainGameMechsRef->getBoardSizeY()-2;
        }
        break;
    case DOWN:
        playerPos.pos->x++;
        if (playerPos.pos->x > mainGameMechsRef->getBoardSizeY()-2)
        {
            playerPos.pos->x = 1;
        }
        break;

    default:
        break;
    }
}

// More methods to be added