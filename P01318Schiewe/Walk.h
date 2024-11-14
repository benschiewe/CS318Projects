/*
Name: Ben Schiewe
Course: CS318
Project: P01 Random Walks
File: Walk.h - Defines function prototypes for the Walk class

Project Description:

"For this project, you are to write a program that produces what is known as a “random walks.”

To clarify, each walk will start at the origin (x=0, y=0),
and will move some random distance in some random direction (in a straight line) to a new point (x1, y1).

When you get to this point, you again move some random distance in some random direction to another
new point, (x2,y2). Repeat this procedure N times to create a random walk.

Each time you move to a new point, update the coordinates of the new point and the cumulative distance traveled for this walk.
You will end at the final point (xN,yN)."
*/

#pragma once

#ifndef _WALK_H_
#define _WALK_H_

class Walk
{
private:
	double x;
	double y;
	double distance;
public:
	Walk();
	double getX() const;
	double getY() const;
	double getDistance() const;
	void setX(double x);
	void setY(double y);
	void setDistance(double distance);
	int generateAngle() const;
	int generateLength() const;
	double convertToRadians(double degree) const;
	void step();
};

#endif