// The main.cpp file for the racing game
// Devin Hopkins
// 4190350

#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>

// Testing only
#include <iostream>
// Remove when done

#include "car.hpp"
#include "object.hpp"
//#include "effect.hpp"
//#include "car.hpp"

using namespace sf;

int main()
{
    // Look into
    RenderWindow app(VideoMode(640, 480), "Car Racing Game!");
	app.setFramerateLimit(60);

    // Look into
    Texture t1, t2;
    t1.loadFromFile("images/background.png");
    t2.loadFromFile("images/car.png");
    t1.setSmooth(true);
    t2.setSmooth(true);

    // Making two parallel vectors to contain all of the race track's objects
    std::vector<Object*> objects;
    std::vector<Sprite> sprites;

    // Creating objects in the race course and putting them into the objects vector
    //
    // Boostpads
    //objects.push_back(new BoostPad("images/boostpad.png", 250, 900));
    objects.push_back(new BoostPad("images/boostpad.png", 1290, 1500));
    objects.push_back(new BoostPad("images/boostpad.png", 1290, 3300));
    //
    // Mudpits
    objects.push_back(new MudPit("images/mud.jpg", 250, 900));
    

    // Creating sprites and putting them into their appropriate places to correlate with the objects
    //
    // Original dimensions of object textures:
    //
    // Background: 1440x1824
    // Car: 43x45
    // Boostpad: 256x256
    Texture t;
    for (std::vector<Object*>::iterator vIter = objects.begin(); vIter != objects.end(); ++vIter)
    {
        // Putting an image with the texture and making it smooth
        t.loadFromFile((*vIter)->getImageLink());
        t.setSmooth(true);

        // Setting the sprite wuth the texture
        Sprite st(t);

        // Making the sprite the same scale as the object
        st.scale((*vIter)->getXScale(), (*vIter)->getYScale());

        // Pushing the sprite onto the vector
        sprites.push_back(st);
    }

    // This makes the images into sprites
    Sprite sBackground(t1), sCar(t2);
    //Sprite sBoostPad1(t3);

    // Setting the scale of the images
    //
    // The first number is how much it's stretched on the x coordinate and
    // the second number is how much it's stretched on the y coordinate
    sBackground.scale(2,2); // Makes pixel measurement to be 2880x3648

    // Look into
    sCar.setOrigin(22, 22);
    float R = 22;

    // This is the number of cars
    // Normal amount is 5 cars
    const int N = 5;

    // Making an array to contain each car
    Car car[N];

    // Setting each computer car in their proper starting spot
    for(int i = 0; i < N; i++)
    {
        car[i].x = 300 + i * 50;
        car[i].y = 1700 + i * 80;
        car[i].speed = 7 + i;
        car[i].maxSpeed = 7 + i;
    }
    
    // Setting all the variables for the user's car
    car[0].maxSpeed = 12.0;
    car[0].speed = 0;
    
    // Look into
    int offsetX = 0;
    int offsetY = 0;

    // This loop runs for as long as the window is open
    while (app.isOpen())
    {
        // Look into
        Event e;

        // Look into
        while (app.pollEvent(e))
        {
            if (e.type == Event::Closed)
            {
                app.close();
            }
        }
        
        // These keep track if an arrow key is pressed or (starts off as no)
        bool Up = 0;
        bool Right = 0;
        bool Down = 0;
        bool Left = 0;
        
        // If the respective arrow key is pressed, then the variable is turned on
        //
        // Up arrow key
        if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            Up = 1;
        }
        // Right arrow key
        if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            Right = 1;
        }
        // Down arrow key
        if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            Down = 1;
        }
        // Left arow key
        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            Left = 1;
        }
        
        // This section is for changing the user's car speed
        //
        // If the up arow key has been pressed and the speed of the car is less than
        // the max speed in the forward direction, then the car's speed in the forward
        // direction changes
        if (Up && car[0].speed < car[0].maxSpeed)
        {
            // If the car is going in the reverse direction (speed < 0), it must slow down before
            // going in the forward direction. Thus, the car is slowed down
            if (car[0].speed < 0) 
            {
                car[0].speed += car[0].dec;
            }
            // If the car is already going in the forward direction or isn't moving, then
            // the car is sped up
            else
            {
                car[0].speed += car[0].acc;
            }
        }
        
        // If the down arow key has been pressed and the speed of the car is greater than
        // the max speed in the reverse direction, then the car's speed in the reverse
        // direction changes
        if (Down && car[0].speed > -car[0].maxSpeed)
        {
            // If the car is going in the forward direction (speed > 0), then the car must
            // be slowed down before it can go in the reverse direction
            if (car[0].speed > 0)
            {
                car[0].speed -= car[0].dec;
            }
            // If the car is going in the reverse direction or isn't moving, then the car
            // is sped up in the reverse direction
            else
            {
                car[0].speed -= car[0].acc;
            }
        }
        
        // If neither the up or down arrow keys are being pressed, the car will slow down
        // until it comes to a complete stop
        if (!Up && !Down)
        {
            // If the car is moving in the forward direction
            if (car[0].speed - car[0].dec > 0)
            {
                car[0].speed -= car[0].dec;
            }
            // If the car is moving in the reverse direction
            else if (car[0].speed + car[0].dec < 0)
            {
                car[0].speed += car[0].dec;
            }
            // If the car is pretty muched stopped or is stopped, then the car is set/kept
            // at a standstill
            else
            {
                car[0].speed = 0;
            }
        }

        // If a car is going above its maximum speed (meaning it just came off a boostpad)
        // then it needs to slow down
        for (int i = 0; i < N; ++i)
        {
            if (car[i].speed > car[i].maxSpeed)
            {
                car[i].speed -= (car[i].dec / 4.0);
            }
        }

        // This section checks to see if a computer car is going slower than their max speed
        // If they are, they must be sped up
        for (int x = 1; x < N; ++x)
        {
            if (car[x].speed < car[x].maxSpeed)
            {
                car[x].speed += car[x].acc;
            }
        }
        
        // This section is for changing the user's car's angle
        //
        // If the right arrow key is pressed and the car is moving, the car turns towards the
        // right at a rate relative to its speed
        if (Right && car[0].speed != 0) 
        {
            car[0].angle += (car[0].turnSpeed * car[0].speed) / car[0].maxSpeed;
        }
        // If the left arrow key is pressed and the car is moving, the car turns towards the
        // left at a rate relative to its speed
        if (Left && car[0].speed != 0)
        {
            car[0].angle -= (car[0].turnSpeed * car[0].speed) / car[0].maxSpeed;
        }
        
        // This is performing the actual moving of every single car
        for (int i = 0; i < N; i++)
        {
            car[i].move();
        }
        
        // This is telling the computer cars where their next target is and how they need to
        // adjust to get there
        for (int i = 1; i < N; i++)
        {
            car[i].findTarget();
        }
        
        // This section is for collision with other cars
        //
        // These loops compare each car with every other car
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {      
                // dx is the difference in pixels between car i and car j in the x axis
                int dx = 0;
                // dy is the difference in pixels between car i and car j in the y axis
                int dy = 0;

                // This loop goes while the difference in pixels squared between car i
                // and car j is less than 4 times the R value squared
                // (The R value is declared in the beginning of main)
                while (dx * dx + dy * dy < 4 * R * R)
                {
                    // This moves car i's x coordinate to the right
                    car[i].x += dy / 10.0;
                    car[i].x += dx / 10.0;
                    // This moves car j's x coordinate to the left
                    car[j].x -= dx / 10.0;
                    // This moves car j's y coordinate down
                    car[j].y -= dy / 10.0;
                    // This calculates the difference in the x and y coordinates of both cars
                    dx = car[i].x - car[j].x;
                    dy = car[i].y - car[j].y;

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

        // If the user's car goes to far from the left edge, then the screen must move to keep up with
        // the user's car. This gets the x coordinate of where the center of the screen should be
        if (car[0].x > 320)
        {
            offsetX = car[0].x - 320;
        }
        // If the user's car goes too far from the top edge, then the screen must move to keep up
        // with the user's car. This gets the y coordinate of where the center of the screen should
        // be
        if (car[0].y > 240)
        {
            offsetY = car[0].y - 240;
        }

        // This section is for collision with objects
        //
        // This loops compare each car with the objects
        for (std::vector<Object*>::iterator oIter = objects.begin(); oIter != objects.end(); ++oIter)
        {
            for (int i = 0; i < N; i++)
            {
                // This calculates the difference in the x and y coordinates of the car
                // and the object
                int dx = car[i].x - (*oIter)->getXCenter();
                int dy = car[i].y - (*oIter)->getYCenter();

                // This loop goes while the difference the car is within the hitbox of the object.
                // The variables are just to store the range of the hitboxes in both the x and the
                // y direction
                int xHitboxRange = (*oIter)->getXHitbox();
                int yHitboxRange = (*oIter)->getYHitbox();
                while (dx * dx < xHitboxRange * xHitboxRange && dy * dy < yHitboxRange * yHitboxRange)
                {
                    // This calculates the difference in the x and y coordinates of the car
                    // and the object
                    dx = car[i].x - (*oIter)->getXCenter();
                    dy = car[i].y - (*oIter)->getYCenter();

                    // If the object changes the car's speed, it's done here
                    car[i].x += (*oIter)->changeXSpeed(car[i]);
                    car[i].y += (*oIter)->changeYSpeed(car[i]);

                    // Adjusting the car's max speed
                    car[i].speed = car[i].maxSpeed + (*oIter)->getMaxSpeedChange();

                    // Making sure the car's speed is greater than 0
                    if (car[i].speed < 0)
                    {
                        car[i].speed = 0.5;
                    }

                    // Seeing the object has an effect and, if so, adding it to the car
                    if ((*oIter)->getEffectName().length() != 0)
                    {
                        std::vector<Effect*> effects = car[i].getEffects();
                        std::string effectTitle = (*oIter)->getEffectName();
                        for (std::vector<Effect*>::iterator eIter = effects.begin(); eIter != effects.end(); ++eIter)
                        {
                            // This attempts to turn on the status effect
                            (*eIter)->turnOnEffect(effectTitle);
                        }
                    }
                }
            }
        }

        // This loop checks for any effects on the cars and applies them appropriately
        for (int i = 0; i < N; ++i)
        {
            std::vector<Effect*> effects = car[i].getEffects();
            for (std::vector<Effect*>::iterator eIter = effects.begin(); eIter != effects.end(); ++eIter)
            {
                // This checks for any effects
                if ((*eIter)->getEffectStatus())
                {
                    // Adjusitng the car's speed as it needs to be adjusted based on the effect
                    std::cout << "EFFECT IS ON!" << std::endl;
                    car[i].speed = car[i].maxSpeed + (*eIter)->getMaxSpeedChange();
                }
            }
        }
        
        // Look into
        app.clear(Color::White);
        
        // This changes where the screen is so the user's car stays in the middle, so long as
        // the user isn't near the left or top edge by using the values obtained above
        sBackground.setPosition(-offsetX, -offsetY);
        app.draw(sBackground);

        // This makes sure each of the sprites stays in its proper position
        std::vector<Sprite>::iterator sIter = sprites.begin();
        for (std::vector<Object*>::iterator vIter = objects.begin(); vIter != objects.end(); ++vIter)
        {
            (*sIter).setPosition(-offsetX + (*vIter)->getXCoordinate(), -offsetY + (*vIter)->getYCoordinate());
            app.draw((*sIter));

            ++sIter;
        }
        
        // These are the colors of the car
        Color colors[10] = {Color::Red, Color::Green, Color::Magenta, Color::Blue, Color::White};
        
        // After setting up the car variables, this draws each car in their correct location
        for(int i = 0; i < N; i++)
        {
            sCar.setPosition(car[i].x - offsetX, car[i].y - offsetY);
            sCar.setRotation(car[i].angle * 180 / 3.141593);
            sCar.setColor(colors[i]);
            app.draw(sCar);
        }
        
        // Look into
        app.display();
    }

    return 0;
}
