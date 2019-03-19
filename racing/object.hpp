// This is the object.hpp file for the race game
// Devin Hopkins
// 4190350

#include <cmath>
#include <SFML/Graphics.hpp>

struct Object {
    // These are for changing the speed of the car
    virtual float changeXSpeed() const = 0;
    virtual float changeYSpeed() const = 0;
};

struct BoostPad : Object {
    // Changing the x speed
    float changeXSpeed()
    {
        return 1;
    }

    // Changing the y speed
    float changeYSpeed()
    {
        return 1;
    }
};