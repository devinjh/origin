// This is the gameEvents.cpp file for the race game
// Devin Hopkins
// 4190350

#include "gameEvents.hpp"




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

    //float R = 22;
    offsetX = 0;
    offsetY = 0;
}

// Draws the game
void race_track::draw(RenderWindow& wind, std::vector<Car*>& car)
{
    wind.clear(Color::White);

    // This makes the images into sprites
    Sprite sBackground(t1), sCar(t2);

    // Setting the scale of the images
    //
    // The first number is how much it's stretched on the x coordinate and
    // the second number is how much it's stretched on the y coordinate
    sBackground.scale(2,2); // Makes pixel measurement to be 2880x3648

    // If the user's car goes to far from the left edge, then the screen must move to keep up with
    // the user's car. This gets the x coordinate of where the center of the screen should be
    if (car[0]->x > 320)
    {
        offsetX = car[0]->x - 320;
    }
    // If the user's car goes too far from the top edge, then the screen must move to keep up
    // with the user's car. This gets the y coordinate of where the center of the screen should
    // be
    if (car[0]->y > 240)
    {
        offsetY = car[0]->y - 240;
    }

    // Look into
    sCar.setOrigin(22, 22);
    
    // This changes where the screen is so the user's car stays in the middle, so long as
    // the user isn't near the left or top edge by using the values obtained above
    sBackground.setPosition(-offsetX, -offsetY);
    wind.draw(sBackground);
    
    // This makes sure each of the sprites stays in its proper position
    std::vector<Sprite>::iterator sIter = sprites.begin();
    for (std::vector<Object*>::iterator vIter = objects.begin(); vIter != objects.end(); ++vIter)
    {
        (*sIter).setPosition(-offsetX + (*vIter)->getXCoordinate(), -offsetY + (*vIter)->getYCoordinate());
        wind.draw((*sIter));
        ++sIter;
    }
    
    // These are the colors of the car
    Color colors[10] = {Color::Red, Color::Green, Color::Magenta, Color::Blue, Color::White};
    
    // After setting up the car variables, this draws each car in their correct location
    for(int i = 0; i < car.size(); i++)
    {
        sCar.setPosition(car[i]->x - offsetX, car[i]->y - offsetY);
        sCar.setRotation(car[i]->angle * 180 / 3.141593);
        sCar.setColor(colors[i]);
        wind.draw(sCar);
    }
    
    // Look into
    wind.display();
}






// RACING GAME STRUCT

// Constructor
racing_game::racing_game() : window(VideoMode(640, 480), "Car Racing Game!")
{
    window.setFramerateLimit(60);

    // This is the number of cars in the game
    const int N = 5; // This is for the actual game
    //const int N = 1; // This is for testing

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
}

bool racing_game::is_open()
{
    return window.isOpen();
}

void racing_game::on_key_pressed(sf::Event::KeyEvent e)
{
    switch(e.code){
        case 74 : // This is for DOWN
            return;
        case 73 : // This is for UP
            return;
        case 72 : // This is for RIGHT
            return;
        case 71 : // This is for LEFT
            return;
        default : // No other keys do anything right now, but can easily be added in the future
            return;
    }
}

// Moves the computer cars
void racing_game::move_computer_cars()
{
    // Going through each step of having the computer cars move
    for (int i = 1; i < car.size(); ++i)
    {
        // This is telling the computer cars where their next target is and how they need to
        // adjust to get there
        car[i]->findTarget();

        // If a computer car is going above its maximum speed (meaning it just came off a boostpad)
        // then it needs to slow down
        if (car[i]->speed > car[i]->maxSpeed)
        {
            car[i]->speed -= (car[i]->dec / 4.0);
        }

        // This section checks to see if a computer car is going slower than their max speed
        // If they are, they must be sped up
        if (car[i]->speed < car[i]->maxSpeed)
        {
            car[i]->speed += car[i]->acc;
        }

        // This is performing the actual moving of every single computer car
        car[i]->move();
    }
}

// Add effects to cars
void racing_game::change_effects()
{
    // This loop checks for any effects on the cars and applies them appropriately
    for (int i = 0; i < car.size(); ++i)
    {
        // This creates a vector with all of the effects in it
        std::vector<Effect*> effects = car[i]->getEffects();
        for (std::vector<Effect*>::iterator eIter = effects.begin(); eIter != effects.end(); ++eIter)
        {
            // This checks for any effects
            if ((*eIter)->getEffectStatus())
            {
                // Adjusting the car's speed as it needs to be adjusted based on the effect
                car[i]->speed = car[i]->maxSpeed + (*eIter)->getMaxSpeedChange();

                // Adjusting the lap count of the car
                car[i]->lap += (*eIter)->getLapChange();

                // This checks to see if the effect needs to be turned off
                (*eIter)->timeOut();
            }
        }
    }
}

void racing_game::draw()
{
    // Drawing the 
    raceTrack.draw(window, car);
}

void racing_game::detect_car_collision()
{
    // The square root of the collision box
    const int R = 22;

    // These loops compare each car with every other car
    for (int i = 0; i < car.size(); i++)
    {
        for (int j = 0; j < car.size(); j++)
        {      
            // dx is the difference in pixels between car i and car j in the x axis
            int dx = 0;
            // dy is the difference in pixels between car i and car j in the y axis
            int dy = 0;

            // This loop goes while the difference in pixels squared between car i
            // and car j is less than 4 times the R value squared
            // (The R value is declared in the beginning of this function)
            while (dx * dx + dy * dy < 4 * R * R)
            {
                // This moves car i's x coordinate to the right
                car[i]->x += dy / 10.0;
                car[i]->x += dx / 10.0;
                // This moves car j's x coordinate to the left
                car[j]->x -= dx / 10.0;
                // This moves car j's y coordinate down
                car[j]->y -= dy / 10.0;
                // This calculates the difference in the x and y coordinates of both cars
                dx = car[i]->x - car[j]->x;
                dy = car[i]->y - car[j]->y;
                // If the dx and dy are 0 (zero), then the loop breaks. This is to make
                // there's not an infinite loop by judging the distance between the same
                // car (ex: i = j)
                //
                // A different way to explain: If dx = 0, then !dx = true
                //                                dy = 0, then !dy = true
                //
                // A different way to explain: If dx != 0, then !dx = false
                //                                dy != 0, then !dy = false
                if (!dx && !dy)
                {
                    break;
                }
            }
        }
    }
}