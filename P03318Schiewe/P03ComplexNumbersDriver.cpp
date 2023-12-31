/*
*	Name: Ben Schiewe
*	Course: CS318 FA2023
*	Project: P02 Complex Numbers
*	File: P03ComplexNumbersDriver.cpp
* 
*	SAMPLE TEST SUITE structure. YOU MUST COMPLETE MANY MORE TESTS
*	Test Suite for complex number class
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
*	specifications shown below. The class interface and bodies should be placed in files: �complex.h� and �complex.cpp."
*/


#include <iostream>
#include <cmath>
#include <assert.h>
#include "complex.h"
using namespace std;

// test function that drives multiple infix operators over complex and double arguments
complex f(const complex& z) {
	return z * z * z - 3 * z * z + 4 * z - 2;
}

//approx_value is used for testing equivalent values of type double
inline bool approx_value(double x, double y) {
	return (y - .0001 <= x && x <= y + .0001);
}

bool assertx(bool expr, unsigned line) {
	if (!expr) cerr << "Error at line " << line << endl; return expr;
}

int main()
{
	const double PI = 3.141592653589793;
	const complex i(0, 1); // complex number i = 0 +1i
	complex z1, z2, z3;
	complex z4 = complex(1, 2);
	complex complex_number[] = { complex(2,3),  complex(-1,1), complex(1,1),
							  complex(1,-1), complex(1,0) };
	complex sum = 0.0;
	double x1;
	double y1;
	// for use with polar tests
	complex z8;
	double r_z8;
	double arg_z8;

	complex z5;
	cout << "\nTesting >>: input a complex number (3, -2): ";
	cin >> z5;
	assertx(z5.real() == 3.0, __LINE__);
	assertx(z5.imag() == -2.0, __LINE__);

	cout << "\nTesting <<: output a complex number(3, -2): " << z5;

	cout << "\n\nTesting Assignment Operator";
	z1 = complex(3, 2);
	z2 = complex(-4, 3);
	z4 = z3;

	cout << "\n\nTesting Complex Math Operators with Object";
	z3 += z2;
	assertx(z3 == z2, __LINE__);
	z3 -= z2;
	assertx(z4 == z3, __LINE__);
	z3 *= z2;

	z3 /= z2;
	assertx(z3 == z4, __LINE__);

	cout << "\n\nTesting Complex Math Operators with Constants";
	x1 = z3.real();

	y1 = z3.imag();
	const double C = 3.0;
	z3 += C;
	assertx((z3.real() == (x1 + C)) && (z3.imag() == y1), __LINE__);
	z3 -= C;
	assertx((z3.real() == x1) && (z3.imag() == y1), __LINE__);
	z3 *= C;
	assertx((z3.real() == (x1 * C)) && (z3.imag() == (y1 * C)), __LINE__);
	z3 /= C;
	assertx((z3.real() == x1) && (z3.imag() == y1), __LINE__);

	cout << "\n\nTesting Complex Infix Operators with Objects";
	assertx(z1 == complex(3, 2), __LINE__);
	assertx(z2 == complex(-4, 3), __LINE__);
	assertx((z1 + z2) == complex(-1, 5), __LINE__);
	assertx((z1 - z2) == complex(7, -1), __LINE__);
	assertx((z1 * z2) == complex(-18, 1), __LINE__);
	assertx((z1 / z2) == complex(-0.24, -0.68), __LINE__);

	cout << "\n\nTesting Polar Magnitude Calculation";
	z1 = complex(2, 3);  //note change of value bound to z1
	assertx(z1.real() == 2.0, __LINE__);
	assertx(z1.imag() == 3.0, __LINE__);
	assertx(real(z1) == 2.0, __LINE__);
	assertx(imag(z1) == 3.0, __LINE__);
	assertx(z1.magnitude() == sqrt(z1.real() * z1.real() + z1.imag() * z1.imag()), __LINE__);

	cout << "\n\nTesting Polar Arg Calculation";
	assertx(arg(complex(1., 0.)) == 0.0, __LINE__);
	assertx(approx_value(arg(complex(0, 1)), PI / 2.0), __LINE__);
	assertx(approx_value(arg(complex(-1, 0)), PI), __LINE__);

	cout << "\n\nTesting Coordinate to Polar";
	z8 = complex{ .5, 4.0 };
	r_z8 = magnitude(z8);
	arg_z8 = arg(complex(z8));
	//cout << "\nPolar arguments: r=" << r_z8 << "  arg=" << arg_z8;
	assertx(approx_value(polar(r_z8, arg_z8).real(), .5), __LINE__);
	assertx(approx_value(polar(r_z8, arg_z8).imag(), 4.0), __LINE__);

	z8 = complex{ -3.0, 7.0 };
	r_z8 = magnitude(z8);
	arg_z8 = arg(complex(z8));
	//cout << "\n\nPolar arguments: r=" << r_z8 << "  arg=" << arg_z8;
	assertx(approx_value(polar(r_z8, arg_z8).real(), -3.0), __LINE__);
	assertx(approx_value(polar(7.61577, 1.97569).imag(), 7.0), __LINE__);

	cout << "\n\nTesting Chained Calculations";
	// evaluate f(z), z = 2+3i, -1+i, 1+i, 1-i, 1+0i -- chaining
	assertx(f(complex_number[0]) == complex(-25, -15), __LINE__);
	assertx(f(complex_number[1]) == complex(-4, 12), __LINE__);
	assertx(f(complex_number[2]) == complex(0, 0), __LINE__);
	assertx(f(complex_number[3]) == complex(0, 0), __LINE__);
	assertx(f(complex_number[4]) == complex(0, 0), __LINE__);

	// ************************* STUDENTS SHOULD ADD AT LEAST 10 ADDITIONAL TESTS HERE **************************

	cout << "\n\nTesting Math Operators - Constant (op) Complex";
	complex z9;
	z3 = { -4, 3 };
	x1 = z3.real();
	y1 = z3.imag();

	z9 = C + z3;
	assertx((z9.real() == (x1 + C)) && (z9.imag() == y1), __LINE__);
	z9 = C - z3;
	assertx((z9.real() == C - x1) && (z9.imag() == -y1), __LINE__);
	z9 = C * z3;
	assertx((z9.real() == (x1 * C)) && (z9.imag() == (y1 * C)), __LINE__);
	z9 = C / z3;
	assertx((z9.real() == (C * x1) / (pow(x1, 2) + pow(y1, 2))) && (z9.imag() == (-C * y1) / (pow(x1, 2) + pow(y1, 2))), __LINE__);

	cout << "\n\nTesting Complex x Complex Operations - Large Numbers";

	z3 = { 10000, 1000 };
	z4 = { 1000, 27 };

	z9 = z3 + z4;
	assertx((z9.real() == z3.real() + z4.real()) && (z9.imag() == z3.imag() + z4.imag()), __LINE__);
	z9 = z3 - z4;
	assertx((z9.real() == z3.real() - z4.real()) && (z9.imag() == z3.imag() - z4.imag()), __LINE__);
	z9 = z3 * z4;
	assertx(approx_value(z9.real(), 9973000) && approx_value(z9.imag(), 1270000), __LINE__);
	z9 = z3 / z4;
	assertx(approx_value(z9.real(), 10.0196956419) && approx_value(z9.imag(), 0.72946821766), __LINE__);


	cout << "\n\nTesting Unary Operators";

	z3 = { 5, 5 };

	z4 = +z3;
	assertx((z4.real() == z3.real()) && (z4.imag() == z3.imag()), __LINE__);
	z9 = -z3;
	assertx((z9.real() == z3.real() * -1) && (z9.imag() == z3.imag() * -1), __LINE__);


	cout << "\n\nPASSED TESTS\n";

	return 0;
} //end main
