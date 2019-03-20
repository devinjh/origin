// This is the object.hpp file for the race game
// Devin Hopkins
// 4190350

#include <cmath>
#include <SFML/Graphics.hpp>

struct Object {

    // Variables necessary for the objects
    float speedChangeX, speedChangeY;
    int xCoordinate, yCoordinate;
    std::string imageLink;


    // These are for changing the speed of the car
    virtual float changeXSpeed() const = 0;
    virtual float changeYSpeed() const = 0;

    // Gets the x and y coordinate of the object's location
    virtual int getXCoordinate() const = 0;
    virtual int getYCoordinate() const = 0;

    // Gets the image link of the object
    virtual std::string getImageLink() const = 0;
};

struct BoostPad : Object {

    // Constructor
    BoostPad(std::string nameOfImage, int xCoord, int yCoord)
    {
        speedChangeX = 0.5;
        speedChangeY = 0.5;
        imageLink = nameOfImage;
        xCoordinate = xCoord;
        yCoordinate = yCoord;
    }

    // Changing the x speed
    float changeXSpeed() const { return speedChangeX; }

    // Changing the y speed
    float changeYSpeed() const { return speedChangeY; }

    // Returning the path for the image
    std::string getImageLink() const { return imageLink; }

    // Returning the x coordinate of the boostpad
    int getXCoordinate() const { return xCoordinate; }

    // Returning the y coordinate of the boostpad
    int getYCoordinate() const { return yCoordinate; }
};