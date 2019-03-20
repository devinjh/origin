// This is the object.hpp file for the race game
// Devin Hopkins
// 4190350

#include <cmath>
#include <SFML/Graphics.hpp>

struct Object {
    // These are for changing the speed of the car
    virtual float changeXSpeed() const = 0;
    virtual float changeYSpeed() const = 0;

    // Gets the image link of the object
    virtual std::string getImageLink() const = 0;
};

struct BoostPad : Object {

    BoostPad()
    {
        // Empty
    }

    // Changing the x speed
    float changeXSpeed() const
    {
        return 0.5;
    }

    // Changing the y speed
    float changeYSpeed() const
    {
        return 0.5;
    }

    std::string getImageLink() const
    {
        return "images/boostpad.png";
    }
};