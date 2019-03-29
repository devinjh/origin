// This is the object.hpp file for the race game
// Devin Hopkins
// 4190350

#ifndef EFFECT_HPP
#define EFFECT_HPP

#include <cmath>
#include <SFML/Graphics.hpp>
#include "car.hpp"

struct Effect {

    // Variables necessary for the effects
    bool inEffect;
    std::string effectName;

    // Try and turn on the effect (only if it matches the name
    // of the effect)
    void turnOnEffect(std::string effectToTurnOn);

    // Gets whether or not the effect is on
    bool getEffectStatus() { return inEffect; }
};

#endif //EFFECT_HPP