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
    snake = new Player(game);  
    food = new Food();  

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
    } else if (input == '1'){
        game->incrementScore();
    } else if (input == 'l'){
        game->setLoseFlag();
    
    }
    snake->updatePlayerDir();
    snake->movePlayer();
    game->clearInput();
    if ((food->getFoodPos().pos->x == snake->getPlayerPos().pos->x)&&(food->getFoodPos().pos->y == snake->getPlayerPos().pos->y)){
        food->generateFood(snake->getPlayerPos());
    }

    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();    


    for(int i = 0; i < game->getBoardSizeY(); i++){
        for(int j = 0; j < game->getBoardSizeX(); j++){
            if(i == 0 || i == game->getBoardSizeY()-1|| j == 0 || j == game->getBoardSizeX()-1){
                MacUILib_printf("%c", '#');
            }
            else if (i == snake->getPlayerPos().pos->x && j == snake->getPlayerPos().pos->y){
                MacUILib_printf("%c", snake->getPlayerPos().getSymbol());
            }
            else if (i == food->getFoodPos().pos->x && j == food->getFoodPos().pos->y){
                MacUILib_printf("%c", food->getFoodPos().getSymbol());
            }
            else
            {
                
                MacUILib_printf("%c",' ');
            }
        }
        MacUILib_printf("\n");
    }
    MacUILib_printf("Score: %d", game->getScore());
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    game->clearInput();
    MacUILib_clearScreen();    

    if (game->getLoseFlagStatus() == true ){
        MacUILib_printf("Snake ate itself! Game over!");
    } else {
        MacUILib_printf("You Win!");
    }
        

    MacUILib_uninit();
}
