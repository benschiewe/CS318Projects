// Circular_Buffer.h -- starter code
/*  REQUIREMENTS NOTES:

	Functions that need to be written have a comment above the function or constructor

	Do not add any additional instance variables

	You may include the implementation/definition of functions in this header file
		-- no need to create a separate .cpp file

*/

#ifndef _CIRCULAR_BUFFER_H
#define _CIRCULAR_BUFFER_H

#include <array>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

template<typename T, int cap, typename Container = std::array<T, cap> >
class CircularBuffer {
public:
	//type T will be the data type in the Container declared in the template
	using value_type = T;

	//COMPLETE CONSTRUCTOR BELOW
	CircularBuffer() { _head = 0, _tail = 0, _size = 0, _capacity = cap, _current = 0 };

	//COMPLETE THE FUNCTIONS BELOW USING THE FUNCTION PROTOTYPE GIVEN

	T& head() { return c[_head]; }
	T& tail() { return c[_tail]; }
	T const& head() const { return c[_head]; }
	T const& tail() const { return c[_tail]; }

	//COMPLETE THE push_back function -- circular buffer will overwrite
	//		oldest data if buffer is full.  This function must update
	//		appropriate instance variables
	void push_back(T val) noexcept {
		if (_current == _capacity) {	//If we are trying to write out of bounds...
			_current = 0;				//Set write position to 0
			_head = _current + 1;		//Update head to 1 after write position
		};
		c[_current] = val;				//Update value stored at current position
		_tail = _current;				//Update tail (newest element) to current
		_current++;						//Set write position to next element in arr
	}

	void pop() {
		if (_size <= 0) {
			throw std::underflow_error("pop(): empty buffer");
		}
		// COMPLETE THE REMAINDER OF THIS FUNCTION
		else {
			_current--;
			_size--;
		}
	}

	// COMPLETE THE FUNCTIONS BELOW
	int size() const noexcept { return _size; }

	int capacity() noexcept { return _capacity; }

	bool empty() const noexcept { return (_size == 0); } //returns true if buffer is empty

	bool full() const noexcept { return (_size == _capacity); }  //returns true if buffer is full

	typename Container::iterator begin() { return c.begin(); }

	typename Container::iterator end() { return c.end(); }

	// COMPLETE THE OVERLOADED << OPERATOR
	friend std::ostream& operator<<(std::ostream& os, CircularBuffer& buf) {
		std::cout << "Buffer Info: head: " << _head << ", tail: " << _tail <<
			", current: " << _current << ", capacity: " << _capacity << ", size: " << _size << "\n";
		std::cout << "Container: ";
		for (T el : c) {
			std::cout << " " << el;
		}
	}

private:
	Container c; // will be std::array<T, cap>
	int _head; //oldest item in buffer
	int _tail; //newest item in buffer
	int _size; //# of elem in buffer
	int _current; //next write position in buffer
	int _capacity;
};
#endif
