// This is the car.hpp file for the race game
// Devin Hopkins
// 4190350

#include <cmath>
#include <SFML/Graphics.hpp>

using namespace sf;

class Car {
    private:
        const int num = 8; // checkpoints
        int** points; // spots of the checkpoints

    public:
        float x, y, speed, angle;

        int n;

        Car();

        void move();

        // This function tells the CPU cars where to go
        void findTarget();
};