// The main.cpp file for the race game
// Devin Hopkins
// 4190350

#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>

#include "gameEvents.hpp"

using namespace sf;

int main()
{
    // Creating the racing game
    racing_game app{};

    // Creating a way to gather events that go on in the window
    event_source events{app.window};

    // Making sure the event_source object can listen to the events from the app
    // (the app listens for events, and this allows them to be read)
    events.listen(app);

    // Goes on while the app is open
    while(app.is_open())
    {
        events.poll(); // Get all of the events
        app.change_effects(); // Modify the cars based on the effects on them
        app.move_computer_cars(); // Move the computer cars
        app.move_user_car(); // Move the user's car
        app.detect_car_collision(); // Detects if there's any collision between two cars
        app.detect_object_collision(); // Detects if there's any collision between a car and an object
        app.draw(); // Draw and update the game based on the changes
    }
}