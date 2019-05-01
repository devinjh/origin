// This is the effect.hpp file for the race game
// Devin Hopkins
// 4190350

#ifndef EFFECT_HPP
#define EFFECT_HPP

#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>

// Effect struct
struct Effect {

    // Variables necessary for the effects
    bool inEffect;
    std::string effectName;
    time_t start;
    double effectTime;

    // Try and turn on the effect (only if it matches the name
    // of the effect)
    virtual void turnOnEffect(std::string effectToTurnOn) = 0;

    // Changes the speed at which the car is moving
    virtual int getMaxSpeedChange() const = 0;
    
    // Changes the lap count of the car
    virtual int getLapChange() const = 0;

    // Tell whether the effect should be turned off or not based on time
    virtual void timeOut()
    {
        // If the difference in the time from when the car came under the effect
        // is equal to the time the ffect should last, then it's turned off
        time_t end = time(0);
        if (difftime(end, start) >= effectTime)
        {
            inEffect = false;
        }
    }

    // Gets whether or not the effect is on
    virtual bool getEffectStatus() const { return inEffect; }
};

// Mud struct
struct Mud : Effect {

    // Constructor
    Mud()
    {
        inEffect = false;
        effectName = "mud";
        effectTime = 2;
    }

    // This turns on the effect and starts the time for how long the effect lasts
    void turnOnEffect(std::string effectToTurnOn)
    {
        // If the effect name matches this effect's name, then it's turned on
        if (effectToTurnOn.compare(effectName) == 0)
        {
            inEffect = true;
            start = time(0);
        }
    }

    // Changes the speed at which the car is moving
    int getMaxSpeedChange() const { return -5; }

    // Changes the lap count of the car
    int getLapChange() const { return 0; }
};

// Finish struct
struct Finish : Effect {

    // Constructor
    Finish()
    {
        inEffect = false;
        effectName = "finish";
        effectTime = 2;
    }
    
    // This turns on the effect and starts the time for how long the effect lasts
    void turnOnEffect(std::string effectToTurnOn)
    {
        // If the effect name matches this effect's name, then it's turned on
        if (effectToTurnOn.compare(effectName) == 0)
        {
            inEffect = true;
            start = time(0);
        }
    }

    // Changes the speed at which the car is moving
    int getMaxSpeedChange() const { return 0; }

    // Changes the lap count of the car
    int getLapChange() const { return 1; }
};

#endif //EFFECT_HPP