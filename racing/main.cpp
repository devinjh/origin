// The main.cpp file for the racing game
// Devin Hopkins
// 4190350

#include <SFML/Graphics.hpp>
#include <cmath>

// Testing only
//#include <iostream>

#include "car.hpp"
#include "object.hpp"

using namespace sf;

int main()
{
    // Look into
    RenderWindow app(VideoMode(640, 480), "Car Racing Game!");
	app.setFramerateLimit(60);

    // Look into
    Texture t1,t2,t3;
    t1.loadFromFile("images/background.png");
    t2.loadFromFile("images/car.png");
    t1.setSmooth(true);
    t2.setSmooth(true);

    // Look into
    Sprite sBackground(t1), sCar(t2);
    sBackground.scale(2,2);

    // Look into
    sCar.setOrigin(22, 22);
    float R = 22;
    // This is for the test of R
    //float R = 44;

    // This is the number of cars
    const int N = 5;

    // Making an array to contain each car
    Car car[N];

    // Setting each car in their proper starting spot
    for(int i = 0; i < N; i++)
    {
        car[i].x = 300 + i * 50;
        car[i].y = 1700 + i * 80;
        car[i].speed = 7 + i;
    }
    
    // Setting all the variables for each car
    float speed = 0;
    float angle = 0;
    float maxSpeed = 12.0;
    float acc = 0.2;
    float dec = 0.3;
    float turnSpeed = 0.08;
    
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
        if (Up && speed < maxSpeed)
        {
            // If the car is going in the reverse direction (speed < 0), it must slow down before
            // going in the forward direction. Thus, the car is slowed down
            if (speed < 0) 
            {
                speed += dec;
            }
            // If the car is already going in the forward direction or isn't moving, then
            // the car is sped up
            else
            {
                speed += acc;
            }
        }
        
        // If the down arow key has been pressed and the speed of the car is greater than
        // the max speed in the reverse direction, then the car's speed in the reverse
        // direction changes
        if (Down && speed >- maxSpeed)
        {
            // If the car is going in the forward direction (speed > 0), then the car must
            // be slowed down before it can go in the reverse direction
            if (speed > 0)
            {
                speed -= dec;
            }
            // If the car is going in the reverse direction or isn't moving, then the car
            // is sped up in the reverse direction
            else
            {
                speed -= acc;
            }
        }
        
        // If neither the up or down arrow keys are being pressed, the car will slow down
        // until it comes to a complete stop
        if (!Up && !Down)
        {
            // If the car is moving in the forward direction
            if (speed - dec > 0)
            {
                speed -= dec;
            }
            // If the car is moving in the reverse direction
            else if (speed + dec < 0)
            {
                speed += dec;
            }
            // If the car is pretty muched stopped or is stopped, then the car is set/kept
            // at a standstill
            else
            {
                speed = 0;
            }
        }
        
        // This section is for changing the user's car's angle
        //
        // If the right arrow key is pressed and the car is moving, the car turns towards the
        // right at a rate relative to its speed
        if (Right && speed != 0) 
        {
            angle += (turnSpeed * speed) / maxSpeed;
        }
        // If the left arrow key is pressed and the car is moving, the car turns towards the
        // left at a rate relative to its speed
        if (Left && speed != 0)
        {
            angle -= (turnSpeed * speed) / maxSpeed;
        }
        
        // This is updating the user's car's variables
        car[0].speed = speed;
        car[0].angle = angle;
        
        // This is performing the actual moving of every single car
        for(int i = 0; i < N; i++)
        {
            car[i].move();
        }
        
        // This is telling the computer cars where their next target is and how they need to
        // adjust to get there
        for(int i = 1; i < N; i++)
        {
            car[i].findTarget();
        }
        
        // This section is for collision
        //
        // These loops compare each car with every other car
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
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

                    // TESTING ONLY
                    /*std::cout << "  i: " << i << std::endl;
                    std::cout << "  j: " << j << std::endl;
                    std::cout << " dx: " << dx << std::endl;
                    std::cout << "!dx: " << !dx << std::endl;
                    std::cout << " dy: " << dy << std::endl;
                    std::cout << "!dy: " << !dy << std::endl;
                    std::cout << "\n\n\n";*/

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
                        //std::cout << "BREAK" << std::endl;
                        break;
                    }
                }
            }
        }
        
        // Look into
        app.clear(Color::White);
        
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
        
        // This changes where the screen is so the user's car stays in the middle, so long as
        // the user isn't near the left or top edge by using the values obtained above
        sBackground.setPosition(-offsetX, -offsetY);
        app.draw(sBackground);
        
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
