// This is the effect.hpp file for the race game
// Devin Hopkins
// 4190350

#ifndef EFFECT_HPP
#define EFFECT_HPP

#include <cmath>
#include <SFML/Graphics.hpp>
//#include "car.hpp"
//#include "object.hpp"

struct Effect {

    // Variables necessary for the effects
    bool inEffect;
    std::string effectName;

    // Try and turn on the effect (only if it matches the name
    // of the effect)
    virtual void turnOnEffect(std::string effectToTurnOn) = 0;

    // Changes the soeed at which the car is moving
    virtual int getMaxSpeedChange() const = 0;

    // Gets whether or not the effect is on
    virtual bool getEffectStatus() { return inEffect; }
};

struct Mud : Effect {

    Mud()
    {
        inEffect = false;
        effectName = "mud";
    }

    void turnOnEffect(std::string effectToTurnOn)
    {
        if (effectToTurnOn.compare(effectName) == 0)
        {
            inEffect = true;
        }
    }

    // Changes the soeed at which the car is moving
    int getMaxSpeedChange() const { return -5; }
};

#endif //EFFECT_HPP