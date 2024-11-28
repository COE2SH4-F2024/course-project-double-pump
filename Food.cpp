#include "Food.h"


Food::Food()        // Constructor
{
    srand(time(NULL));

    foodPos.pos->x = (rand() % 18)+1;;
    foodPos.pos->y = (rand() % 8)+1;;
    foodPos.symbol = '$';
}

Food::~Food()
{
    delete foodPos.pos;
}

//need rule of 6?

Food::Food(const Food &other){
    foodPos.pos = new Pos;
    foodPos.pos->x = other.foodPos.pos->x;
    foodPos.pos->y = other.foodPos.pos->y;
    foodPos.symbol = other.foodPos.symbol;
}

Food& Food::operator=(const Food& other){
    delete foodPos.pos;

    foodPos.pos = new Pos;
    foodPos.pos->x = other.foodPos.pos->x;
    foodPos.pos->y = other.foodPos.pos->y;
    foodPos.symbol = other.foodPos.symbol;

    return *this;
}


objPos Food::getFoodPos() const
{
    return foodPos;
}

void Food::generateFood(objPos blockOff)
{   

    srand(time(NULL));

    int possible_x, possible_y;
    
    int numFlag = 1;
    while (numFlag == 1){

        numFlag = 0;
        possible_x = (rand() % 18)+1;
        possible_y = (rand() % 8)+1;

        if (possible_x == blockOff.pos->x && possible_y == blockOff.pos->y){
            numFlag = 1;
        }

        if (possible_y == foodPos.pos->y && possible_x == foodPos.pos->x){
            numFlag = 1;
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

