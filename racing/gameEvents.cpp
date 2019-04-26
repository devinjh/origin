// This is the gameEvents.cpp file for the race game
// Devin Hopkins
// 4190350

#include "gameEvents.hpp"

// RACING GAME STRUCT

// Constructor
racing_game::racing_game() : window(VideoMode(640, 480), "Car Racing Game!")
{
    window.setFramerateLimit(60);
}




// EVENT SOURCE STRUCT

// Constructor
event_source::event_source(sf::Window& w) : window(&w)
{
    // Empty constructor
}

// If there's an event, this picks it up and stores it in the listeners vector
void event_source::listen(event_listener& l)
{
    listeners.push_back(&l);
}

// This sees if there's any events going on
void event_source::poll()
{
    sf::Event e;
    while (window->pollEvent(e))
    {
        process(e);
    }
}

// This processes any event that's going on and specifies what it is
void event_source::process(sf::Event const& e)
{
    switch(e.type){
        case Event::KeyPressed:
            return notify([e](event_listener* l) { l->on_key_pressed(e.key); } );
        default:
            break;
    }
}




// RACE TRACK STRUCT

// Constructor
race_track::race_track()
{
    t1.loadFromFile("images/background.png");
    t2.loadFromFile("images/car.png");
    t1.setSmooth(true);
    t2.setSmooth(true);
    // This is the number of cars in the game
    //const int N = 5; // This is for the actual game
    const int N = 1; // This is for testing
    // Creating objects in the race course and putting them into the objects vector
    //
    // Boostpads
    objects.push_back(new BoostPad("images/boostpad.png", 250, 900)); // By start/finish line
    objects.push_back(new BoostPad("images/boostpad.png", 1290, 1500)); // In long corridor between the two
                                                                        // outside parts of the track
    objects.push_back(new BoostPad("images/boostpad.png", 1290, 3300)); // In the last long corridor before
                                                                        // the start/finish line
    //
    // Mudpits
    objects.push_back(new MudPit("images/mud.jpg", 253, 840));
    //
    // Finish Line
    objects.push_back(new Finish_Line("images/finish_line.jpg", 207, 1350));
    // Creating sprites and putting them into their appropriate places to correlate with the objects
    //
    // Original dimensions of object textures:
    //
    // Background: 1440x1824
    // Car: 43x45
    // Boostpad: 256x256
    //
    // This makes sure each object has their own texture
    for (int x = 0; x < objects.size(); ++x)
    {
        Texture t;
        textures.push_back(t);
    }

    // Creating iterators for each of the vectors
    std::vector<Object*>::iterator vIter = objects.begin();
    std::vector<Texture>::iterator tIter = textures.begin();

    // Looping through making sure each object gets their appropriate texture and sprite
    while (vIter != objects.end() && tIter != textures.end())
    {
        // Putting an image with the texture and making it smooth
        (*tIter).loadFromFile((*vIter)->getImageLink());
        (*tIter).setSmooth(true);
        // Setting the sprite wuth the texture
        Sprite st((*tIter));
        // Making the sprite the same scale as the object
        st.scale((*vIter)->getXScale(), (*vIter)->getYScale());
        // Pushing the sprite onto the vector
        sprites.push_back(st);
        // Making sure both iterators get iterated
        ++vIter;
        ++tIter;
    }

    // This makes the images into sprites
    Sprite sBackground(t1), sCar(t2);
    // Setting the scale of the images
    //
    // The first number is how much it's stretched on the x coordinate and
    // the second number is how much it's stretched on the y coordinate
    sBackground.scale(2,2); // Makes pixel measurement to be 2880x3648
    // Look into
    sCar.setOrigin(22, 22);
    float R = 22;
    // This is the number of cars
    for (int x = 0; x < N; ++x)
    {
        car.push_back(new Car{});
    }
    // Setting each computer car in their proper starting spot
    for(int i = 0; i < N; i++)
    {
        car[i]->x = 300 + i * 50;
        car[i]->y = 1700 + i * 80;
        car[i]->speed = 7 + i;
        car[i]->maxSpeed = 7 + i;
    }
    // Setting all the variables for the user's car
    car[0]->maxSpeed = 12.0;
    car[0]->speed = 0;
    offsetX = 0;
    offsetY = 0;
}

bool racing_game::is_open()
{
    return window.isOpen();
}

void racing_game::on_key_pressed(sf::Event::KeyEvent e)
{
    switch(e.code){
        //case Keyboard::Right :
            //std::cout << "RIGHT\n";
            //return;
        default :
            std::cout << "code: " << e.code << "\n";
            return;
    }
}