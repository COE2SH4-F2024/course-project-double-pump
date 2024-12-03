#ifndef FOOD_H
#define FOOD_H

// #include "GameMechs.h"
#include "objPos.h"
#include <time.h>
#include <stdlib.h>
#include "objPosArrayList.h"

class Food
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    
    public:

        Food();
        ~Food();
        // Food(const Food &other);
        // Food& operator=(const Food& other);

        objPos getFoodPos() const; // Upgrade this in iteration 3. 
        objPos getBombPos() const;      
        void generateFood(objPosArrayList* blockOff);
        void generateBomb(objPosArrayList* blockOff);

        // More methods to be added here

    private:
        objPos foodPos; // Upgrade this in iteration 3.  
        objPos bombPos;     

};

#endif