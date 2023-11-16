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
	
}

template<typename NumberType>
inline Polynomial<NumberType> Polynomial<NumberType>::operator+=(const Polynomial<NumberType>& rhs)
{
	
}

template<typename NumberType>
inline const Polynomial<NumberType> Polynomial<NumberType>::operator+(const Monomial<NumberType>& m) const
{
	
}

template<typename NumberType>
inline const Polynomial<NumberType> Polynomial<NumberType>::operator+(const Polynomial<NumberType>& rhs) const
{
	
}

template<typename NumberType>
inline Polynomial<NumberType> Polynomial<NumberType>::operator-=(const Monomial<NumberType>& m)
{
	
}

template<typename NumberType>
inline Polynomial<NumberType> Polynomial<NumberType>::operator-=(const Polynomial<NumberType>& rhs)
{
	
}


template<typename NumberType>
inline const Polynomial<NumberType> Polynomial<NumberType>::operator-(const Monomial<NumberType>& m) const
{
	
}

template<typename NumberType>
inline const Polynomial<NumberType> Polynomial<NumberType>::operator-(const Polynomial<NumberType>& rhs) const
{
	
}

template<typename NumberType>
inline Polynomial<NumberType> Polynomial<NumberType>::operator*=(const Monomial<NumberType>& m)
{
	for (auto it = term_list.begin(); it != term_list.end(); it++)
	{
		it->assign_coefficient(it->coefficient() * m.coefficient());
		it->assign_degree(it->degree() + m.degree());
	}
	return *this;
}

template<typename NumberType>
inline Polynomial<NumberType> Polynomial<NumberType>::operator*=(const Polynomial<NumberType>& rhs)
{
	for (auto it = term_list.begin(); it != term_list.end(); it++)
	{
		for (auto itRhs = rhs.term_list.begin(); itRhs != rhs.term_list.end(); itRhs++)
		{
			it->assign_coefficient(it->coefficient() * itRhs->coefficient());
			it->assign_degree(it->degree() + itRhs->degree());
		}
	}
	return *this;
}

template<typename NumberType>
inline const Polynomial<NumberType> Polynomial<NumberType>::operator*(const Monomial<NumberType>& m) const
{
	Polynomial<NumberType> newPoly = *this;
	newPoly *= m;
	return newPoly;
}

template<typename NumberType>
inline const Polynomial<NumberType> Polynomial<NumberType>::operator*(const Polynomial<NumberType>& rhs) const
{
	Polynomial<NumberType> newPoly = *this;
	newPoly *= rhs;
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
	return this->term_list == p.term_list;		//Overloaded in list class - first compares size, then each element
}

template<typename NumberType>
inline bool Polynomial<NumberType>::operator!=(const Polynomial<NumberType>& p) const
{
	return !(*this == p);
}

template<typename NumberType>
inline void Polynomial<NumberType>::read(std::istream& in)
{
	const std::streamsize MAX_SIZE = 256;
	int coeff, degree;
	std::size_t pos, pos2;

	std::string s;
	std::getline(in, s);

	while (true)
	{
		pos = s.find(" ");
		pos2 = s.find(" ", pos + 1);
		coeff = std::stoi(s.substr(0, pos));
		if (coeff == 0) return;
		degree = std::stoi(s.substr(pos + 1, pos2));
		insert_in_poly(*this, Monomial<NumberType>(coeff, degree));
		s.erase(0, pos2 + 1);
	}
}

template<typename NumberType>
inline void Polynomial<NumberType>::print(std::ostream& out) const
{
	auto it = term_list.begin();
	for (it; it != --(--term_list.end()); it++)
	{
		out << it->coefficient() << "x^" << it->degree() << " + ";
	}
	out << it->coefficient() << "x^" << it->degree() << "\n";
}

template<typename NumberType>
inline void Polynomial<NumberType>::insert_in_poly(Polynomial<NumberType>& p, const Monomial<NumberType>& m)
{
	auto it = p.term_list.begin();
	while (it->degree() > m.degree())
		it++;
	term_list.insert(it, m);
}

template<typename NumberType>
inline NumberType Polynomial<NumberType>::power(NumberType x, int n) const
{
	return NumberType(pow(x, n));
}
