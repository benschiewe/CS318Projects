/*
Name: Ben Schiewe
Course: CS318
Project: P01 Random Walks
File: Source.cpp - Driver file to create a vector<Walk> and test functionality of the class

Project Description:

"For this project, you are to write a program that produces what is known as a “random walks.”

To clarify, each walk will start at the origin (x=0, y=0),
and will move some random distance in some random direction (in a straight line) to a new point (x1, y1).

When you get to this point, you again move some random distance in some random direction to another
new point, (x2,y2). Repeat this procedure N times to create a random walk.

Each time you move to a new point, update the coordinates of the new point and the cumulative distance traveled for this walk.
You will end at the final point (xN,yN)."
*/

#include "Walk.h"
#include <vector>
#include <algorithm>
#include <iomanip>
#include <iostream>

std::ostream& operator<<(std::ostream& os, const Walk& walk);

int main()
{
	int pts, walks;
	srand(time(0));

	std::cout << std::fixed << std::showpoint;
	std::cout << std::setprecision(2);

	std::cout << "*** Random Walks ***\n\n";
	std::cout << "This program generates a number of random walks.\n\n";

	std::cout << "Enter a number of points for each walk: ";
	std::cin >> pts;

	std::cout << "\nEnter a number of random walks to generate: ";
	std::cin >> walks;
	std::cout << "\n\n";

	std::vector<Walk> vec;
	vec.reserve(walks);

	for (int i = 0; i < walks; i++)
	{
		Walk curr;
		for (int j = 0; j < pts; j++)
		{
			curr.step();
			std::cout << "Walk/Step: " << i + 1 << "/" << j + 1 << ":  " << curr << "\n";
		}
		vec.push_back(curr);
		std::cout << "\n";
	}

	std::sort(vec.begin(), vec.end(), [](Walk& lhs, Walk& rhs) {
		return lhs.getDistance() < rhs.getDistance();
		});

	std::cout << "Walks Sorted:\n";

	double acc = 0;
	for (const auto& el : vec)
	{
		std::cout << "\tPoint: " << el.getX() << ", " << el.getY() << "   Distance: " << el.getDistance() << "\n";
		acc += el.getDistance();
	}

	std::cout << "\nAverage Distance: " << acc / walks << "\n";
	std::cout << "\nShortest Distance/Walk: " << vec.at(0).getDistance();

	double median = 0;
	if (vec.size() % 2 == 0)
		median = (vec.at(vec.size() / 2).getDistance() + vec.at(vec.size() / 2 - 1).getDistance()) / 2;
	else
		median = vec.at(vec.size() / 2).getDistance();

	std::cout << "\nMedian Distance/Walk: " << median;
	std::cout << "\nLongest Distance/Walk: " << vec.at(vec.size() - 1).getDistance();
	std::cout << "\n\n\n";

	return 0;
}

std::ostream& operator<<(std::ostream& os, const Walk& walk)
{
	std::cout << "Point: " << walk.getX() << ", " << walk.getY() << " Distance: " << walk.getDistance();
	return os;
}