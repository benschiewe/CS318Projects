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


#include "complex.h"
#include <cmath>

complex::complex() : r(0), i(0) {}

complex::complex(double a) : r(a), i(0) {}

complex::complex(double a, double b) : r(a), i(b) {}

complex::complex(const complex& c) : r(c.r), i(c.i) {}

complex& complex::operator=(const complex& rhs)
{
	r = rhs.r;
	i = rhs.i;
	return *this;
}

complex& complex::operator+=(const complex& z)
{
	r += z.r;
	i += z.i;
	return *this;
}

complex& complex::operator-=(const complex& z)
{
	r -= z.r;
	i -= z.i;
	return *this;
}

complex& complex::operator*=(const complex& z)
{
	double realPart = r * z.r - i * z.i;
	double imagPart = r * z.i + i * z.r;
	r = realPart, i = imagPart;
	return *this;
}

complex& complex::operator/=(const complex& z)
{
	double realPart = (r * z.r + i * z.i) / (pow(z.r, 2) + pow(z.i, 2));
	double imagPart = (i * z.r - r * z.i) / (pow(z.r, 2) + pow(z.i, 2));
	r = realPart, i = imagPart;
	return *this;
}

complex& complex::operator+=(const double x)
{
	r += x;
	return *this;
}

complex& complex::operator-=(const double x)
{
	r -= x;
	return *this;
}

complex& complex::operator*=(const double x)
{
	r *= x;
	i *= x;
	return *this;
}

complex& complex::operator/=(const double x)
{
	r /= x;
	i /= x;
	return *this;
}

double complex::real() const
{
	return r;
}

double complex::imag() const
{
	return i;
}

double complex::magnitude() const
{
	return sqrt(pow(r, 2) + pow(i, 2));
}

complex operator+(const complex& z1, const complex& z2)
{
	double realPart = z1.real() + z2.real();
	double imagPart = z1.imag() + z2.imag();
	return complex(realPart, imagPart);
}

complex operator-(const complex& z1, const complex& z2)
{
	double realPart = z1.real() - z2.real();
	double imagPart = z1.imag() - z2.imag();
	return complex(realPart, imagPart);
}

complex operator*(const complex& z1, const complex& z2)
{
	double realPart = z1.real() * z2.real() - z1.imag() * z2.imag();
	double imagPart = z1.real() * z2.imag() + z1.imag() * z2.real();
	return complex(realPart, imagPart);
}

complex operator/(const complex& z1, const complex& z2)
{
	double realPart = (z1.real() * z2.real() + z1.imag() * z2.imag()) / (pow(z2.real(), 2) + pow(z2.imag(), 2));
	double imagPart = (z1.imag() * z2.real() - z1.real() * z2.imag()) / (pow(z2.real(), 2) + pow(z2.imag(), 2));
	return complex(realPart, imagPart);
}

complex operator+(const complex& z, const double x)
{
	return complex(x + z.real(), z.imag());
}

complex operator-(const complex& z, const double x)
{
	return complex(z.real() - x, z.imag());
}

complex operator*(const complex& z, const double x)
{
	return complex(x * z.real(), x * z.imag());
}

complex operator/(const complex& z, const double x)
{
	return complex(z.real() / x, z.imag() / x);
}

complex operator+(const double x, const complex& z)
{
	return complex(x + z.real(), z.imag());
}

complex operator-(const double x, const complex& z)
{
	return complex(x - z.real(), -z.imag());
}

complex operator*(const double x, const complex& z)
{
	return complex(x * z.real(), x * z.imag());
}

complex operator/(const double x, const complex& z)
{
	double realPart = (x * z.real()) / (pow(z.real(), 2) * pow(z.imag(), 2));
	double imagPart = (-x * z.imag()) / (pow(z.real(), 2) * pow(z.imag(), 2));
	return complex(realPart, imagPart);
}

complex operator+(const complex& z)
{
	return (complex(z) *= 1);
}

complex operator-(const complex& z)
{
	return (complex(z) *= -1);
}

bool operator==(const complex& z1, const complex& z2)
{
	return !(z1 != z2);
}

bool operator!=(const complex& z1, const complex& z2)
{
	if (z1.real() != z2.real() || z1.imag() != z2.imag())	return true;
	else	return false;
}

std::istream& operator>>(std::istream& is, complex& z)
{
	double r, i;
	char discard;
	is >> discard;
	is >> r;
	is >> discard;
	is >> i;
	is >> discard;
	z = complex(r, i);
	return is;
}

std::ostream& operator<<(std::ostream& os, const complex& z)
{
	return os << "(" << z.real() << ", " << z.imag() << ")";
}

double magnitude(const complex& z)
{
	return sqrt(pow(z.real(), 2) + pow(z.imag(), 2));
}

double real(const complex& z)
{
	return z.real();
}

double imag(const complex& z)
{
	return z.imag();
}

complex polar(const double r, const double theta)
{
	return complex(r * cos(theta), r * sin(theta));
}

complex polar(const double r)
{
	return complex(r);
}

complex conj(const complex& z)
{
	return complex(z.real(), -z.imag());
}

double norm(const complex& z)
{
	return pow(z.magnitude(), 2);
}

double arg(const complex& z)
{
	return atan2f(z.imag(), z.real()); //TODO modify return here after figuring out wtf is going on
}