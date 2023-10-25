/*
*	Name: Ben Schiewe
*	Course: CS318 FA2023
*	Project: P02 Complex Numbers
*	File: complex.cpp
*
*	Project Description:
*
*	"The essence of this programming project is to build your understanding of the design of classes without regards to a
*
*	particular object-oriented language and to build your knowledge of C++ syntax and semantics, especially the use of C++
*
*	class semantics for building and representing classes. For this project you are required to implement a complex class
*
*	that is a simpler version of <complex>. You must build a similar interface and implementation according to the
*
*	specifications shown below. The class interface and bodies should be placed in files: “complex.h” and “complex.cpp."
*/


#pragma once
#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class complex {
public:
	complex();
	complex(double a);
	complex(double a, double b);

	complex(const complex& c);

	complex& operator=(const complex& rhs);

	complex& operator+=(const complex& z);
	complex& operator-=(const complex& z);
	complex& operator*=(const complex& z);
	complex& operator/=(const complex& z);

	complex& operator+=(const double x);
	complex& operator-=(const double x);
	complex& operator*=(const double x);
	complex& operator/=(const double x);

	double real() const;
	double imag() const;

	double magnitude() const;

private:
	double r;
	double i;
};

complex operator+(const complex& z1, const complex& z2);
complex operator-(const complex& z1, const complex& z2);
complex operator*(const complex& z1, const complex& z2);
complex operator/(const complex& z1, const complex& z2);

complex operator+(const complex& z, const double x);
complex operator-(const complex& z, const double x);
complex operator*(const complex& z, const double x);
complex operator/(const complex& z, const double x);

complex operator+(const double x, const complex& z);
complex operator-(const double x, const complex& z);
complex operator*(const double x, const complex& z);
complex operator/(const double x, const complex& z);

complex operator+(const complex& z);
complex operator-(const complex& z);

bool operator==(const complex& z1, const complex& z2);
bool operator!=(const complex& z1, const complex& z2);

std::istream& operator>>(std::istream& is, complex& z);
std::ostream& operator<<(std::ostream& os, const complex& z);

double magnitude(const complex& z);
double real(const complex& z);
double imag(const complex& z);

complex polar(const double r, const double theta);
complex polar(const double r);
complex conj(const complex& z);

double norm(const complex& z);
double arg(const complex& z);

#endif