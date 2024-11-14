/*
Name: Ben Schiewe
Course: CS318
Project: P01 Random Walks
File: Walk.cpp - Implements logic for the Walk class

Project Description:

"For this project, you are to write a program that produces what is known as a “random walks.”

To clarify, each walk will start at the origin (x=0, y=0),
and will move some random distance in some random direction (in a straight line) to a new point (x1, y1).

When you get to this point, you again move some random distance in some random direction to another
new point, (x2,y2). Repeat this procedure N times to create a random walk.

Each time you move to a new point, update the coordinates of the new point and the cumulative distance traveled for this walk.
You will end at the final point (xN,yN)."
*/

#define _USE_MATH_DEFINES

#include "Walk.h"
#include <cstdlib>
#include <cmath>

Walk::Walk()
{
    x = 0;
    y = 0;
    distance = 0;
}

double Walk::getX() const
{
    return x;
}

double Walk::getY() const
{
    return y;
}

double Walk::getDistance() const
{
    return distance;
}

void Walk::setX(double x)
{
    this->x = x;
}

void Walk::setY(double y)
{
    this->y = y;
}

void Walk::setDistance(double distance)
{
    this->distance = distance;
}

int Walk::generateAngle() const
{
    return (rand() % 359) + 1;
}

int Walk::generateLength() const
{
    return (rand() % 100) + 1;
}

double Walk::convertToRadians(double degree) const
{
    return degree * (M_PI / 180);
}

void Walk::step()
{
    int length = generateLength();
    double angle = convertToRadians(generateAngle());
    x += length * cos(angle);
    y += length * sin(angle);
    distance += length;
}