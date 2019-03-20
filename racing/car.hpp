// This is the car.hpp file for the race game
// Devin Hopkins
// 4190350

#include <cmath>
#include <SFML/Graphics.hpp>

class Car {
    private:
        const int num = 8; // checkpoints

        // Would like this to be here, but can't get it working :(
        //int points; // spots of the checkpoints

    public:
        float x, y, speed, angle, maxSpeed;

        int n;

        // Constructor
        Car();

        // Moving the car
        void move();

        // This function tells the CPU cars where to go
        void findTarget();
};