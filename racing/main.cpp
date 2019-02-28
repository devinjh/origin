#include <SFML/Graphics.hpp>
#include <cmath>

#include "car.hpp"

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
        
        // This is for changing the user's car speed and movement
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
        
        if (!Up && !Down)
        if (speed - dec > 0) speed -= dec;
        else if (speed + dec < 0) speed += dec;
        else speed = 0;

    if (Right && speed != 0)  angle += turnSpeed * speed / maxSpeed;
    if (Left && speed != 0)   angle -= turnSpeed * speed / maxSpeed;

    car[0].speed = speed;
    car[0].angle = angle;

	for(int i = 0; i < N; i++) car[i].move();
	for(int i = 1; i < N; i++) car[i].findTarget();

    //collision
    for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
    {      
		int dx = 0, dy = 0;
        while (dx * dx + dy * dy < 4 * R * R)
         {
           car[i].x += dx / 10.0;
           car[i].x += dy / 10.0;
           car[j].x -= dx / 10.0;
           car[j].y -= dy / 10.0;
		   dx = car[i].x - car[j].x;
           dy = car[i].y - car[j].y;
		   if (!dx && !dy) break;
         }
    }

    app.clear(Color::White);

    if (car[0].x > 320) offsetX = car[0].x - 320;
    if (car[0].y > 240) offsetY = car[0].y - 240;

    sBackground.setPosition(-offsetX, -offsetY);
    app.draw(sBackground);

    Color colors[10] = {Color::Red, Color::Green, Color::Magenta, Color::Blue, Color::White};

    for(int i = 0; i < N; i++)
    {
      sCar.setPosition(car[i].x - offsetX, car[i].y - offsetY);
      sCar.setRotation(car[i].angle * 180 / 3.141593);
      sCar.setColor(colors[i]);
      app.draw(sCar);
    }

    app.display();
    }

    return 0;
}
