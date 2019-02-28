// This is the car.cpp file for the race game
// Devin Hopkins
// 4190350

#include "car.hpp"
#include <iostream>

Car::Car()
{
    speed = 2;
    angle = 0;
    n = 0;
    x = 0;
    y = 0;

    // private data members
    int points[num][2] = {300, 610,
        1270,430,
        1380,2380,
        1900,2460,
        1970,1700,
        2550,1680,
        2560,3150,
        500, 3300};
    /*
    int points[num][2];
    points[0][0] = 300;
    points[0][1] = 610;
    */

    std::cout << "HERE abcxyz" << std::endl;

    for (int xx = 0; xx < num; ++xx)
    {
        for (int yy = 0; yy < 2; ++yy)
        {
            std::cout << "[" << xx << "][" << yy << "]: " << points[xx][yy] << std::endl;
        }
    }

    std::cout << "n:" << n << std::endl;
}

void Car::move()
{
    x += sin(angle) * speed;
    y -= cos(angle) * speed;
}

// This function tells the CPU cars where to go
void Car::findTarget()
{
    std::cout << "HERE xyz1" << std::endl;
    std::cout << "num:" << num << std::endl;
    std::cout << "n:" << n << std::endl;

    for (int xx = 0; xx < num; ++xx)
    {
        for (int yy = 0; yy < 2; ++yy)
        {
            std::cout << "[" << xx << "][" << yy << "]: " << points[xx][yy] << std::endl;
        }
    }

    std::cout << "n:" << n << std::endl;
    float tx = points[n][0];
    std::cout << "HERE xyz1b" << std::endl;
    float ty = points[n][1];
    std::cout << "HERE xyz1c" << std::endl;
    float beta = angle - atan2(tx - x, -ty + y);

    std::cout << "HERE xyz2" << std::endl;

    if (sin(beta) < 0)
    {
        angle += 0.005 * speed;
    }
    else
    {
        angle -= 0.005 * speed;
    }

    std::cout << "HERE xyz3" << std::endl;

    if ((x - tx) * (x - tx) + (y - ty) * (y - ty) < 25 * 25)
    {
        n = (n + 1) % num;
    }

    std::cout << "HERE xyz4" << std::endl;
}