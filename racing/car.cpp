// This is the car.cpp file for the race game
// Devin Hopkins
// 4190350

#include "car.hpp"

Car::Car()
{
    // Setting all the variables to a something
    speed = 2;
    angle = 0;
    n = 0;
    x = 0;
    y = 0;
}

void Car::move()
{
    // Adjusting how fast and what angle the car is moving
    x += sin(angle) * speed;
    y -= cos(angle) * speed;
}

// This function tells the CPU cars where to go
void Car::findTarget()
{
    // Declaring the car's checkpoints
    int points[num][2] = {300, 610,
        1270,430,
        1380,2380,
        1900,2460,
        1970,1700,
        2550,1680,
        2560,3150,
        500, 3300};

    // Getting the correct checkpoint
    float tx = points[n][0];
    float ty = points[n][1];

    // For atan2():
    // This function returns the angle on the unit circle (starting at 0) form the position (x, y)
    // in which x and y are sent in via the function call
    //
    // For beta = angle - atan2():
    // This gets the difference in the angle between the car's current angle and the angle it needs
    // to be heading to hit its next checkpoint. Beta holds this variable
    float beta = angle - atan2(tx - x, -ty + y);

    // If the sin of beta is negative, that means the angle the car needs to be heading is greater
    // than the angle the car is currently heading. So, the angle is increased and the speed is set
    // to the car's proper speed
    if (sin(beta) < 0)
    {
        angle += 0.005 * speed;
    }
    // If the sin of beta is positive, the opposite is true and thus the opposite needs to happen
    else
    {
        angle -= 0.005 * speed;
    }

    // If the cars are within 625 pixels (both x and y distance sqaured combined), then the next
    // checkpoint is accesed by increasing n by 1. It's also made sure that n isn't increased
    // more than what the number of checkpoints is
    if ((x - tx) * (x - tx) + (y - ty) * (y - ty) < 25 * 25)
    {
        n = (n + 1) % num;
    }
}