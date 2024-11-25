#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    playerPos.pos->x = 5;
    playerPos.pos->y = 10;

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
        break;
    case RIGHT:
        playerPos.pos->y++;
        break;
    case UP:
        playerPos.pos->x--;
        break;
    case DOWN:
        playerPos.pos->x++;
        break;

    default:
        break;
    }
}

// More methods to be added