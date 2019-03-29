// This is the object.hpp file for the race game
// Devin Hopkins
// 4190350

#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <cmath>
#include <SFML/Graphics.hpp>
#include "car.hpp"
//#include "effect.hpp"

struct Object {

    // Variables necessary for the objects
    float speedChangeX, speedChangeY, xScale, yScale;
    int xCoordinate, yCoordinate, xPixels, yPixels, maxSpeedChange;
    std::string imageLink;

    // These are for changing the speed of the car
    virtual float changeXSpeed(Car const& c) const = 0;
    virtual float changeYSpeed(Car const& c) const = 0;

    // Gets the x and y coordinate of the object's location
    virtual int getXCoordinate() const = 0;
    virtual int getYCoordinate() const = 0;

    // Gets the image link of the object
    virtual std::string getImageLink() const = 0;

    // Gets the max speed change of the object
    virtual int getMaxSpeedChange() const = 0;

    // Gets the x and y scale the texture needs to be scaled by
    virtual float getXScale() const = 0;
    virtual float getYScale() const = 0;

    // Gets the hitbox of the object
    virtual int getXHitbox() const = 0;
    virtual int getYHitbox() const = 0;

    // Gets the center of the object
    virtual int getXCenter() const = 0;
    virtual int getYCenter() const = 0;

    // If an effect needs to be put on the car, then this returns the name
    // If there's no effect, returns ""
    virtual std::string getEffectName() const = 0;
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
        xScale = 0.25;
        yScale = 0.25;
        xPixels = 256;
        yPixels = 256;
        maxSpeedChange = 7;
    }

    // Changing the x speed
    float changeXSpeed(Car const& c) const { return (sin(c.angle) * c.speed) / (3 * c.maxSpeed); }

    // Changing the y speed
    float changeYSpeed(Car const& c) const { return (cos(c.angle) * c.speed) / (0 - 3 * c.maxSpeed); }

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
    int getXHitbox() const { return (xPixels * xScale); }

    // Gets the y pixel length for the hitbox
    int getYHitbox() const { return (yPixels * yScale); }

    // Gets the x coordinate of the center of the object
    int getXCenter() const { return (xCoordinate + ((xPixels * xScale) / 2)); }
    
    // Gets the y coordinate of the center of the object
    int getYCenter() const { return (yCoordinate + ((yPixels * yScale) / 2)); }

    // Gets the max speed change of the object
    int getMaxSpeedChange() const { return maxSpeedChange; }

    // If an effect needs to be put on the car, then this returns the name
    // If there's no effect, returns ""
    std::string getEffectName() const { return ""; }
};

struct MudPit : Object {

    // Constructor
    MudPit(std::string nameOfImage, int xCoord, int yCoord)
    {
        // All of the variables required for struct Object
        speedChangeX = 0.5;
        speedChangeY = 0.5;
        imageLink = nameOfImage;
        xCoordinate = xCoord;
        yCoordinate = yCoord;
        xScale = 0.25;
        yScale = 0.25;
        xPixels = 234;
        yPixels = 215;
        maxSpeedChange = -5;
    }

    // Changing the x speed
    float changeXSpeed(Car const& c) const { return (sin(c.angle) * c.speed) / (c.maxSpeed); }

    // Changing the y speed
    float changeYSpeed(Car const& c) const { return (cos(c.angle) * c.speed) / (0 - c.maxSpeed); }

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
    int getXHitbox() const { return (xPixels * xScale); }

    // Gets the y pixel length for the hitbox
    int getYHitbox() const { return (yPixels * yScale); }

    // Gets the x coordinate of the center of the object
    int getXCenter() const { return (xCoordinate + ((xPixels * xScale) / 2)); }
    
    // Gets the y coordinate of the center of the object
    int getYCenter() const { return (yCoordinate + ((yPixels * yScale) / 2)); }

    // Gets the max speed change of the object
    int getMaxSpeedChange() const { return maxSpeedChange; }

    // If an effect needs to be put on the car, then this returns the name
    // If there's no effect, returns ""
    std::string getEffectName() const { return "mud"; }
};

#endif // OBJECT_HPP