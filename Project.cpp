#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"
#include "Food.h"
#include "objPosArrayList.h"

using namespace std;

#define DELAY_CONST 100000


Player *snake;
GameMechs *game;
Food *food;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(game->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();
    game = new GameMechs();
    food = new Food();  
    snake = new Player(game,food);    
    

}

void GetInput(void)
{
   int input = MacUILib_hasChar();
   if (input != 0)
    {
        game->setInput(MacUILib_getChar());
    }
}

void RunLogic(void)
{   

    char input = game->getInput();

    if(input == 27){
        game->setExitTrue();
    } 
    else if (snake->checkSelfCollision()){
        game->setLoseFlag();
        game->setExitTrue();
    
    }
    snake->updatePlayerDir();
    snake->movePlayer();
    game->clearInput();
    if ((food->getFoodPos().pos->x == snake->getPlayerPos()->getHeadElement().pos->x)&&(food->getFoodPos().pos->y == snake->getPlayerPos()->getHeadElement().pos->y)){
        
        food->generateFood(snake->getPlayerPos());
        food->generateBomb(snake->getPlayerPos());
        
        
    }
    if ((food->getBombPos().pos->x == snake->getPlayerPos()->getHeadElement().pos->x)&&(food->getBombPos().pos->y == snake->getPlayerPos()->getHeadElement().pos->y)){
        game->setLoseFlag();
        game->setExitTrue();
    }

    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();    


    for(int i = 0; i < game->getBoardSizeY(); i++){
        for(int j = 0; j < game->getBoardSizeX(); j++){
            if((i == 0 || i == game->getBoardSizeY()-1||j == 0 || j == game->getBoardSizeX()-1)){
                MacUILib_printf("#");
            }
            
            // else if (i == snake->getPlayerPos()->getHeadElement().pos->x && j == snake->getPlayerPos()->getHeadElement().pos->y){
            //     MacUILib_printf("%c", snake->getPlayerPos()->getHeadElement().getSymbol());
            // }
            else if (i == food->getFoodPos().pos->x && j == food->getFoodPos().pos->y){
                MacUILib_printf("%c", food->getFoodPos().getSymbol());
            }

            else if (i == food->getBombPos().pos->x && j == food->getBombPos().pos->y){
                MacUILib_printf("%c", food->getBombPos().getSymbol());
            }

            else
            {
                
                int flag = 0;
                for (int k = 0; k < snake->getPlayerPos()->getSize(); k++){
                    flag = 0;

                    objPos currentpos = snake->getPlayerPos()->getElement(k);

                    if (i == currentpos.pos->x && j == currentpos.pos->y){
                        MacUILib_printf("%c", currentpos.symbol);
                        flag = 1;
                        break;
                    }            
                }

                if (flag == 0){

                    MacUILib_printf("%c", ' ');
                }
                
                
            }
        }
        MacUILib_printf("\n");
    }
    MacUILib_printf("Score: %d \n", game->getScore());
    
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    game->clearInput();
    MacUILib_clearScreen();    
    delete snake;
    delete game;
    delete food;   

    if (game->getLoseFlagStatus() == true ){
        MacUILib_printf("Snake ate itself! Game over!");
    }else {
         MacUILib_printf("Game exited");
    }
        

    MacUILib_uninit();
}
