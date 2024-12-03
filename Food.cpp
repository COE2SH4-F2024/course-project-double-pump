#include "Food.h"
#include "objPosArrayList.h"


Food::Food()        // Constructor
{
    srand(time(NULL));

    foodPos.pos->x = (rand() % 8)+1;;
    foodPos.pos->y = (rand() % 18)+1;;
    foodPos.symbol = '@';

    bombPos.pos->x = (rand() % 8)+1;;
    bombPos.pos->y = (rand() % 18) + 1;;
    bombPos.symbol = 'B';

}

Food::~Food()
{
    delete foodPos.pos;
}

//need rule of 6?

// Food::Food(const Food &other){
//     foodPos.pos = new Pos;
//     foodPos.pos->x = other.foodPos.pos->x;
//     foodPos.pos->y = other.foodPos.pos->y;
//     foodPos.symbol = other.foodPos.symbol;
// }

// Food& Food::operator=(const Food& other){
//     delete foodPos.pos;

//     foodPos.pos = new Pos;
//     foodPos.pos->x = other.foodPos.pos->x;
//     foodPos.pos->y = other.foodPos.pos->y;
//     foodPos.symbol = other.foodPos.symbol;

//     return *this;
// }


objPos Food::getFoodPos() const
{
    return foodPos;
}

objPos Food::getBombPos() const
{
    return bombPos;
}

void Food::generateFood(objPosArrayList* blockOff)
{   

    srand(time(NULL));

    int possible_x, possible_y;
    
    int numFlag = 1;
    while (numFlag == 1){

        numFlag = 0;
        possible_x = (rand() % 8)+1;
        possible_y = (rand() % 18)+1;
        for(int i = 0; i < blockOff->getSize(); i++){
            if (possible_x == blockOff->getElement(i).pos->x && possible_y == blockOff->getElement(i).pos->y){
                numFlag = 1;
            }

            if (possible_y == foodPos.pos->y && possible_x == foodPos.pos->x){
                numFlag = 1;
            }
        }

        if (numFlag == 0){
            foodPos.pos->x = possible_x;
            foodPos.pos->y = possible_y;
        }

        else{
            numFlag = 1;
        }

    }

}
void Food::generateBomb(objPosArrayList* blockOff)
{   

    srand(time(NULL));

    int p_x, p_y;
    
    int Flag = 1;
    while (Flag == 1){

        Flag = 0;
        p_x = (rand() % 8)+1;
        p_y = (rand() % 18)+1;
        for(int i = 0; i < blockOff->getSize(); i++){
            if (p_x == blockOff->getElement(i).pos->x && p_y == blockOff->getElement(i).pos->y){
                Flag = 1;
            }

            if (p_y == foodPos.pos->y && p_x == foodPos.pos->x){
                Flag = 1;
            }
        }
        
        if (p_y == bombPos.pos->y && p_x == bombPos.pos->x){
            Flag = 1;
        }

        if (Flag == 0){
            bombPos.pos->x = p_x;
            bombPos.pos->y = p_y;
        }

        else{
            Flag = 1;
        }

    }

}

