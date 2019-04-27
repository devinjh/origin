// This is the game.hpp file for the race game
// Devin Hopkins
// 4190350

#ifndef GAMEEVENTS_HPP
#define GAMEEVENTS_HPP

#include <cmath>
#include <SFML/Graphics.hpp>
#include "car.hpp"
#include "object.hpp"

using namespace sf;

struct event_listener
{
  // Window events
  //virtual void on_close() { }
  //virtual void on_resize(sf::Event::SizeEvent e) { }

  // Keyboard events
  virtual void on_key_pressed(sf::Event::KeyEvent e) { }
};

struct event_source
{
    // Variables
    //
    // Window of the game
    sf::Window* window;
    // A vector to store all of the event listeners
    std::vector<event_listener*> listeners;

    // Construstor
    event_source(sf::Window& w);

    // If there's an event, this picks it up and stores it in the listeners vector
    void listen(event_listener& l);

    // This sees if there's any events going on
    void poll();

    // This processes any event that's going on and specifies what it is
    void process(sf::Event const& e);

    // ???
    template <typename T>
    void notify(T fn) { for (event_listener* l : listeners) fn(l); }
};

struct race_track
{
    // Variables
    //
    // Keeping track of the textures so the game doesn't put white bozes in place of them
    Texture t1, t2;
    // Making two parallel vectors to contain all of the race track's objects
    std::vector<Object*> objects;
    std::vector<Sprite> sprites;
    std::vector<Texture> textures;
    // These are the offset values from where the car is to where the origin is
    int offsetX;
    int offsetY;

    // Constructor
    race_track();

    // Draws the race track
    void draw(RenderWindow& wind, std::vector<Car*>& car);
};

// The actual application
struct racing_game : event_listener
{
    // Variables
    race_track raceTrack{};
    sf::RenderWindow window;
    // Making an array to contain each car
    std::vector<Car*> car;

    // Constructor
    racing_game();

    // Returns true if the window is still open, false otherwise
    bool is_open();

    // Moves the cars
    void move_cars();

    // Add effects to cars
    void change_effects();

    // Draws the game
    void draw();

    // Changes the speed of the user's car if a key is pressed
    void on_key_pressed(sf::Event::KeyEvent e) override;
};



#endif