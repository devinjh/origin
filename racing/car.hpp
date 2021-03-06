// This is the car.hpp file for the race game
// Devin Hopkins
// 4190350

#ifndef CAR_HPP
#define CAR_HPP

#include <cmath>
#include <vector>
#include <SFML/Graphics.hpp>
#include "effect.hpp"

// Class Car
class Car {
    private:
        const int num = 8; // checkpoints

        // Would like this to be here, but can't get it working :(
        //int points; // spots of the checkpoints

    public:
        float x, y, speed, angle, maxSpeed, turnSpeed, acc, dec;
        bool checkOne, checkTwo, checkThree;
        int n, lap;

        // This is to keep track of any effects the car might have
        // on itself
        std::vector<Effect*> effects{};

        // Constructor
        Car();

        // Returning the lap the car is on
        int getLaps() { return lap; }

        // Moving the car
        void move();

        // This function tells the CPU cars where to go
        void findTarget();

        // Getting the effects
        std::vector<Effect*> getEffects();
};

#endif //CAR_HPP