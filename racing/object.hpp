// This is the object.hpp file for the race game
// Devin Hopkins
// 4190350

#include <cmath>
#include <SFML/Graphics.hpp>

struct Object {

    // Variables necessary for the objects
    float speedChangeX, speedChangeY, xScale, yScale;
    int xCoordinate, yCoordinate, xPixels, yPixels;
    std::string imageLink;

    // These are for changing the speed of the car
    virtual float changeXSpeed() const = 0;
    virtual float changeYSpeed() const = 0;

    // Gets the x and y coordinate of the object's location
    virtual int getXCoordinate() const = 0;
    virtual int getYCoordinate() const = 0;

    // Gets the image link of the object
    virtual std::string getImageLink() const = 0;

    // Gets the x and y scale the texture needs to be scaled by
    virtual float getXScale() const = 0;
    virtual float getYScale() const = 0;

    // Gets the hitbox of the object
    virtual int getXHitbox() const = 0;
    virtual int getYHitbox() const = 0;
};

struct BoostPad : Object {

    // Constructor
    BoostPad(std::string nameOfImage, int xCoord, int yCoord)
    {
        // All of the variables required for struct Object
        speedChangeX = 0.5;
        speedChangeY = 0.5;
        imageLink = nameOfImage;
        xCoordinate = xCoord;
        yCoordinate = yCoord;
        xScale = 0.2;
        yScale = 0.2;
        xPixels = 256;
        yPixels = 256;
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

    // Gets the x scale the boostpad needs to be scaled by
    float getXScale() const { return xScale; }
    
    // Gets the y scale the boostpad needs to be scaled by
    float getYScale() const { return yScale; }

    // Gets the x pixel length for the hitbox
    int getXHitbox() const { return 0; }

    // Gets the y pixel length for the hitbox
    int getYHitbox() const { return 0; }
};