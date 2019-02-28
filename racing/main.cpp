#include <SFML/Graphics.hpp>
#include <cmath>

// TESTING ONLY!!!!!
#include <iostream>

#include "car.hpp"

using namespace sf;

int main()
{
    std::cout << "HERE 1" << std::endl;
    RenderWindow app(VideoMode(640, 480), "Car Racing Game!");
    std::cout << "HERE 2" << std::endl;
	app.setFramerateLimit(60);

    Texture t1,t2,t3;
    t1.loadFromFile("images/background.png");
    t2.loadFromFile("images/car.png");
    t1.setSmooth(true);
    t2.setSmooth(true);

    Sprite sBackground(t1), sCar(t2);
    sBackground.scale(2,2);

    sCar.setOrigin(22, 22);
    float R = 22;

    const int N = 5;
    Car car[N];

    std::cout << "HERE 3" << std::endl;

    for(int i = 0; i < N; i++)
    {
      car[i].x = 300 + i * 50;
      car[i].y = 1700 + i * 80;
      car[i].speed = 7 + i;
    }

   float speed = 0, angle = 0;
   float maxSpeed = 12.0;
   float acc = 0.2, dec = 0.3;
   float turnSpeed = 0.08;

   std::cout << "car[0].x:" << car[0].x << std::endl;
   car[0].x += 300;
   std::cout << "300 + car[0].x:" << car[0].x << std::endl;

   int offsetX = 0, offsetY = 0;

   std::cout << "HERE abc" << std::endl;

    while (app.isOpen())
    {
        std::cout << "HERE abc2" << std::endl;
        Event e;
        while (app.pollEvent(e))
        {
            std::cout << "HERE abc3" << std::endl;
            if (e.type == Event::Closed)
                app.close();
        }

        std::cout << "HERE abc4" << std::endl;

    bool Up = 0, Right = 0, Down = 0, Left = 0;

    if (Keyboard::isKeyPressed(Keyboard::Up))
    {
        Up = 1;
    }

    if (Keyboard::isKeyPressed(Keyboard::Right))
    {
        Right = 1;
    }

    if (Keyboard::isKeyPressed(Keyboard::Down))
    {
        Down = 1;
    }

    if (Keyboard::isKeyPressed(Keyboard::Left))
    {
        Left = 1;
    }

    std::cout << "HERE abc5" << std::endl;

    //car movement
    if (Up && speed < maxSpeed)
        if (speed < 0)  speed += dec;
        else  speed += acc;

    if (Down && speed >- maxSpeed)
        if (speed > 0) speed -= dec;
        else  speed -= acc;

    if (!Up && !Down)
        if (speed - dec > 0) speed -= dec;
        else if (speed + dec < 0) speed += dec;
        else speed = 0;

    if (Right && speed != 0)  angle += turnSpeed * speed / maxSpeed;
    if (Left && speed != 0)   angle -= turnSpeed * speed / maxSpeed;

    car[0].speed = speed;
    car[0].angle = angle;

    std::cout << "HERE abc6" << std::endl;

	for(int i = 0; i < N; i++) car[i].move();
    std::cout << "HERE abc6b" << std::endl;
	for(int i = 1; i < N; i++) car[i].findTarget();

    //collision
    std::cout << "HERE abc7" << std::endl;
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

    std::cout << "HERE abc9" << std::endl;
    app.clear(Color::White);

    if (car[0].x > 320) offsetX = car[0].x - 320;
    if (car[0].y > 240) offsetY = car[0].y - 240;

    sBackground.setPosition(-offsetX, -offsetY);
    app.draw(sBackground);

    Color colors[10] = {Color::Red, Color::Green, Color::Magenta, Color::Blue, Color::White};

    std::cout << "HERE abc10" << std::endl;
    for(int i = 0; i < N; i++)
    {
      sCar.setPosition(car[i].x - offsetX, car[i].y - offsetY);
      sCar.setRotation(car[i].angle * 180 / 3.141593);
      sCar.setColor(colors[i]);
      app.draw(sCar);
    }

    std::cout << "HERE 4" << std::endl;

    app.display();

    std::cout << "HERE 5" << std::endl;
    }

    return 0;
}
