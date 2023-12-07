// Polynomial.h -- starter code
#ifndef __POLYNOMIAL_H_
#define __POLYNOMIAL_H_
#include <iostream>
#include <list>
#include <cmath>
#include <algorithm>
#include <ctype.h>
#include <string>

///////////////////////////////////////////////////////// Monomial Class
// Monomial - class that creates the terms that get inserted in a Polynomial
//	-- DO NOT MODIFY
template <typename NumT>
class Monomial {
public:
	Monomial<NumT>(NumT c = 0, int d = 0) : coeff(c), expo(d) { };
	NumT coefficient(void) const { return coeff; };
	int degree(void) const { return expo; };
	void assign_coefficient(const NumT c) { coeff = c; };
	void assign_degree(const int d) { expo = d; };

	bool operator==(const Monomial<NumT>& m) const {
		return (coeff == m.coeff && expo == m.expo);
	}

	bool operator!=(const Monomial<NumT>& m) const {
		return (coeff != m.coeff || expo != m.expo);
	}
private:
	NumT coeff; // in our case this will be an int
	int	expo;
};

//////////////////////////////////////////////////////Polynomial Class
template <typename NumberType>
class Polynomial
{
public:
	// Default constructor -- DO NOT MODIFY
	Polynomial<NumberType>(NumberType c = 0, int d = 0) {
		const Monomial<NumberType> m(c, d);
		term_list.push_back(m); //creates at least one monomial
		number_of_terms = 1;
		highest_degree = d;
	}

	// Type conversion construct -- DO NOT MODIFY
	Polynomial<NumberType>(const Monomial<NumberType>& m) {
		term_list.push_back(m);
		number_of_terms = 1;
		highest_degree = m.degree();
	}

	// Destructor - use default destructors and list's destructor -- DO NOT MODIFY
	~Polynomial<NumberType>() { term_list.clear(); }

	// Copy Constructor -- DO NOT MODIFY
	Polynomial<NumberType>(const Polynomial<NumberType>& rhs)
		: term_list(rhs.term_list),
		number_of_terms(rhs.number_of_terms),
		highest_degree(rhs.highest_degree) {}

	int gethighestdegree() const { return highest_degree; }

	// COMPLETE ALL OF THE FOLLOWING
	const Polynomial<NumberType>& operator=(const Polynomial<NumberType>& rhs); // copy assignment
	const Polynomial<NumberType>& operator=(Polynomial<NumberType>&& rhs);// move assignment

	// ADDITION
	Polynomial<NumberType> operator+=(const Monomial<NumberType>& m); //1
	Polynomial<NumberType> operator+=(const Polynomial<NumberType>& rhs); //2
	const Polynomial<NumberType> operator+ (const Monomial<NumberType>& m)const;//3
	const Polynomial<NumberType> operator+ (const Polynomial<NumberType>& rhs) const;//4

	// SUBTRACTION
	Polynomial<NumberType> operator-=(const Monomial<NumberType>& m);
	Polynomial<NumberType> operator-=(const Polynomial<NumberType>& rhs);
	const Polynomial<NumberType> operator- (const Monomial<NumberType>& m)const;
	const Polynomial<NumberType> operator- (const Polynomial<NumberType>& rhs) const;

	// MULTIPLICATION
	Polynomial<NumberType> operator*=(const Monomial<NumberType>& m);
	Polynomial<NumberType> operator*=(const Polynomial<NumberType>& rhs);
	const Polynomial<NumberType> operator*(const Monomial<NumberType>& m) const;
	const Polynomial<NumberType> operator*(const Polynomial<NumberType>& rhs)const;

	// EVALUATION POLYNOMIAL
	const NumberType evaluate(NumberType x) const;

	// EQUALITY TESTS
	bool operator==(const Polynomial<NumberType>& p) const;
	bool operator!=(const Polynomial<NumberType>& p) const;

	// CALLED FROM ISTREAM AND OSTREAM OVERLOADS
	// read() function has responsibility for getting input, creating Monomial object,
	//			and inserting into Polynomial object
	void read(std::istream& in = cin);

	// print() function -- make sure you look back at requirements for this
	void print(std::ostream& out = cout) const;

private:
	std::list<Monomial<NumberType> > term_list; //SORTED BY DECREASING DEGREES
	int number_of_terms;
	int highest_degree;

	//private helper member function -- review notes below function prototype
	void insert_in_poly(Polynomial<NumberType>& p, const Monomial<NumberType>& m);

	// Used in evaluate member function
	NumberType power(NumberType x, int n) const;
};

// DO NOT MODIFY
template<typename NumberType>
std::istream& operator>>(std::istream& in, Polynomial<NumberType>& rhs) {
	rhs.read();
	return in;
}

// DO NOT MODIFY
template<typename NumberType>
std::ostream& operator<<(std::ostream& out, const  Polynomial<NumberType>& rhs) {
	rhs.print();
	return out;
}

#endif

template<typename NumberType>
inline const Polynomial<NumberType>& Polynomial<NumberType>::operator=(const Polynomial<NumberType>& rhs)
{
	term_list = rhs.term_list;
	number_of_terms = rhs.number_of_terms;
	highest_degree = rhs.highest_degree;
	return *this;
}

template<typename NumberType>
inline const Polynomial<NumberType>& Polynomial<NumberType>::operator=(Polynomial<NumberType>&& rhs)
{
	term_list = move(rhs.term_list);
	number_of_terms = rhs.number_of_terms;
	highest_degree = rhs.highest_degree;
	return *this;
}

template<typename NumberType>
inline Polynomial<NumberType> Polynomial<NumberType>::operator+=(const Monomial<NumberType>& m)
{
	insert_in_poly(*this, m);
	return *this;
}

template<typename NumberType>
inline Polynomial<NumberType> Polynomial<NumberType>::operator+=(const Polynomial<NumberType>& rhs)
{
	for (auto it = rhs.term_list.begin(); it != rhs.term_list.end(); it++)
	{
		*this += *it;
	}
	return *this;
}

template<typename NumberType>
inline const Polynomial<NumberType> Polynomial<NumberType>::operator+(const Monomial<NumberType>& m) const
{
	auto newPoly = *this;
	newPoly += m;
	return newPoly;
}

template<typename NumberType>
inline const Polynomial<NumberType> Polynomial<NumberType>::operator+(const Polynomial<NumberType>& rhs) const
{
	auto newPoly = *this;
	newPoly += rhs;
	return newPoly;
}

template<typename NumberType>
inline Polynomial<NumberType> Polynomial<NumberType>::operator-=(const Monomial<NumberType>& m)
{
	insert_in_poly(*this, Monomial<NumberType>(-m.coefficient(), -m.degree()));
	return *this;
}

template<typename NumberType>
inline Polynomial<NumberType> Polynomial<NumberType>::operator-=(const Polynomial<NumberType>& rhs)
{
	for (auto it = rhs.term_list.begin(); it != rhs.term_list.end(); it++)
	{
		*this -= *it;
	}
	return *this;
}


template<typename NumberType>
inline const Polynomial<NumberType> Polynomial<NumberType>::operator-(const Monomial<NumberType>& m) const
{
	auto newPoly = *this;
	newPoly -= m;
	return newPoly;
}

template<typename NumberType>
inline const Polynomial<NumberType> Polynomial<NumberType>::operator-(const Polynomial<NumberType>& rhs) const
{
	auto newPoly = *this;
	newPoly -= rhs;
	return newPoly;
}

template<typename NumberType>
inline Polynomial<NumberType> Polynomial<NumberType>::operator*=(const Monomial<NumberType>& m)
{
	*this = *this * m;
	return *this;
}

template<typename NumberType>
inline Polynomial<NumberType> Polynomial<NumberType>::operator*=(const Polynomial<NumberType>& rhs)
{
	*this = *this * rhs;
	return *this;
}

template<typename NumberType>
inline const Polynomial<NumberType> Polynomial<NumberType>::operator*(const Monomial<NumberType>& m) const
{
	Polynomial<NumberType> newPoly = Polynomial<NumberType>();

	for (auto it = term_list.begin(); it != term_list.end(); it++)
	{
		newPoly.insert_in_poly(newPoly, Monomial<NumberType>(it->coefficient() * m.coefficient(), it->degree() + m.degree()));
	}
	return newPoly;
}

template<typename NumberType>
inline const Polynomial<NumberType> Polynomial<NumberType>::operator*(const Polynomial<NumberType>& rhs) const
{
	Polynomial<NumberType> newPoly = Polynomial<NumberType>();

	for (auto it = term_list.begin(); it != term_list.end(); it++)
	{
		newPoly += rhs * *it;
	}

	return newPoly;
}

template<typename NumberType>
inline const NumberType Polynomial<NumberType>::evaluate(NumberType x) const
{
	NumberType acc = NumberType();
	for (auto it = term_list.begin(); it != term_list.end(); it++)
	{
		acc += it->coefficient() * power(x, it->degree());
	}
	return acc;
}

template<typename NumberType>
inline bool Polynomial<NumberType>::operator==(const Polynomial<NumberType>& p) const
{
	return this->term_list == p.term_list;								//Overloaded in list class - first compares size, then each element
}

template<typename NumberType>
inline bool Polynomial<NumberType>::operator!=(const Polynomial<NumberType>& p) const
{
	return !(*this == p);
}

template<typename NumberType>
inline void Polynomial<NumberType>::read(std::istream& in)
{
	int coeff = 1, degree = 1;
	std::size_t pos, pos2;

	std::string s;
	std::getline(in, s);

	while (true)														//Clearly the right way to write a loop
	{
		pos = s.find(" ");												//Find 1st and 2nd spaces, store them in size_t vars
		pos2 = s.find(" ", pos + 1);
		coeff = std::stoi(s.substr(0, pos));							//Substring containing first integer
		if (coeff == 0) return;											//If we find coefficient of 0, return and break "infinite" loop
		degree = std::stoi(s.substr(pos + 1, pos2));					//Second integer
		insert_in_poly(*this, Monomial<NumberType>(coeff, degree));		//Create a Monomial, insert into Polynomial
		s.erase(0, pos2 + 1);											//Erase the portion of string we just looked at
	}
}

template<typename NumberType>
inline void Polynomial<NumberType>::print(std::ostream& out) const		//Absolutely disgusting, but it works
{																		//Seriously, what the fuck
	out << "\nNumber terms " << this->number_of_terms << "\n";

	for (auto it = term_list.begin(); it != term_list.end(); it++)
	{
		if (it->coefficient() == 0) continue;


		if (it != term_list.begin())									//If we aren't on term #1... check sign of the monomial to see if we need to print + or -
		{
			if (it->coefficient() > 0)
				out << " + ";
			else
				out << " - ";
		}

		NumberType degree = it->degree();											//Local vars for if/else blocks
		NumberType coefficient = it->coefficient();


		if (coefficient < 0)											//If coeff is negative, make it positive
		{
			coefficient = abs(coefficient);
			if (it == term_list.begin()) out << "-";					//If we are on first term + is negative, print a negative, rather than minus
		}

		if (degree == 0)												//If degree is 0, just print coeff
			out << coefficient;
		else if (degree == 1 && coefficient == 1)						//If degree = 1 and coeff = 1, just print x
			out << "x";
		else if (degree == 1)											//If degree is 1, again, do not print exponent
			out << coefficient << "x";
		else if (coefficient == 1)										//If coefficient = 1, do not print coeff
			out << "x^" << degree;
		else															//Otherwise in general case, print Cx^d
			out << coefficient << "x^" << degree;
	}
	out << "\n";
}

template<typename NumberType>
inline void Polynomial<NumberType>::insert_in_poly(Polynomial<NumberType>& p, const Monomial<NumberType>& m)
{
	auto it = term_list.begin();

	if (m.degree() == 0 && m.coefficient() == 0)						//If someone tries to insert 0x^0, don't
		return;

	if (it->degree() == 0 && it->coefficient() == 0)					//Check list for empty first element (typically in case of new Polynomial)
	{
		it = term_list.erase(it);										//If so, remove the term
		number_of_terms--;
	}

	number_of_terms++;													//Increment number of terms, since we are now adding something

	if (it == term_list.end())											//If adding to empty list, special logic so iterator doesn't over increment
	{
		term_list.push_back(m);
		highest_degree = m.degree();
		return;															//Since term has been added, return
	}
	
	it++;																//After above check, can increment iterator

	if (m.degree() > gethighestdegree())								//If we are trying to add new highest degree,
	{
		term_list.push_front(m);										//Push to front, update highest_degree, return
		highest_degree = m.degree();
		return;
	}

	for (it; it != term_list.end(); it++)								//If not highest term, iterate over list
	{
		if (m.degree() > it->degree())									//If we are greater degree than term we are currently looking at,
		{
			term_list.insert(it, m);									//Insert and return
			return;
		}
		else if (m.degree() == it->degree())							//Otherwise, if the two terms are equal in degree, just update the coeff
		{
			it->assign_coefficient(it->coefficient() + m.coefficient());
			return;
		}
	}																	//Finally, if we aren't greater than or equal to any term, 
	term_list.push_back(m);												//Push to back, since Monomial has smallest degree in list
}

template<typename NumberType>
inline NumberType Polynomial<NumberType>::power(NumberType x, int n) const
{
	return NumberType(pow(x, n));
}
