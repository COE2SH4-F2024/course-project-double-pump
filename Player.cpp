#include "Player.h"

Player::Player(GameMechs *thisGMRef, Food *thisFood)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    playerPosList = new objPosArrayList;
    objPos headpos(5, 10, 254);
    playerPosList->insertHead(headpos);
    food = thisFood;

    // playerPos.pos->y = 10;
    // playerPos.symbol = '*';

    // more actions to be included
    // starting coords (5,10)
}

Player::~Player()
{
    delete playerPosList;
    // delete mainGameMechsRef;
    // delete any heap members here
}

objPosArrayList *Player::getPlayerPos() const
{
    // return the reference to the playerPos array list
    return playerPosList;
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
    objPos playerHead = playerPosList->getHeadElement();

    switch (myDir)
    {
    case LEFT:
        // playerPos.pos->y--;
        playerHead.pos->y--;

        if (playerHead.pos->y < 1)
        {
            playerHead.pos->y = mainGameMechsRef->getBoardSizeX() - 2;
        }
        playerPosList->insertHead(playerHead);
        if (checkFoodConsumption())
        {
            playerPosList->removeTail();
        }  else {
            mainGameMechsRef->incrementScore();
        }
        break;
    case RIGHT:
        playerHead.pos->y++;

        if (playerHead.pos->y > mainGameMechsRef->getBoardSizeX() - 2)
        {
            playerHead.pos->y = 1;
        }
        playerPosList->insertHead(playerHead);
        if (checkFoodConsumption())
        {
            playerPosList->removeTail();
        } else {
            mainGameMechsRef->incrementScore();
        }
        break;

    case UP:
        playerHead.pos->x--;

        if (playerHead.pos->x < 1)
        {
            playerHead.pos->x = mainGameMechsRef->getBoardSizeY() - 2;
        } 
        playerPosList->insertHead(playerHead);
        if (checkFoodConsumption())
        {
            playerPosList->removeTail();
        } else {
            mainGameMechsRef->incrementScore();
        }
        break;
    case DOWN:
        playerHead.pos->x++;
        if(checkSelfCollision()){
            mainGameMechsRef->setLoseFlag();
            mainGameMechsRef->setExitTrue();
        }

        if (playerHead.pos->x > mainGameMechsRef->getBoardSizeY() - 2)
        {
            playerHead.pos->x = 1;
        }
        playerPosList->insertHead(playerHead);
        if (checkFoodConsumption())
        {
            playerPosList->removeTail();
        } else {
            mainGameMechsRef->incrementScore();
        }
        break;

    default:
        break;
    }
    // More methods to be added

}
bool Player::checkFoodConsumption(){
    objPos playerHead = playerPosList->getHeadElement();
    if (playerHead.pos->x == food->getFoodPos().pos->x && playerHead.pos->y == food->getFoodPos().pos->y){
        return false;
    } else {
        
        return true;
    }
}

bool Player::checkSelfCollision(){
    objPos playerHead = playerPosList->getHeadElement();
    for(int i = 1; i < playerPosList->getSize(); i++){
        if (playerHead.pos->x == playerPosList->getElement(i).getObjPos().pos->x && playerHead.pos->y ==  playerPosList->getElement(i).getObjPos().pos->y){
        return true;
        } 
    }
    return false;
}


