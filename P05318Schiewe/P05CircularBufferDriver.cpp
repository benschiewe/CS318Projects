// P05CircularBufferDriver.cpp -- starter code

/*  REQUIREMENTS NOTES:

    Fill in the remainder of this driver program.
    Replicate exactly the sample run provided with project's specs.
    Use a capacity of 5

*/
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include "circular_buffer.h"
#include "dog.h"

using namespace std;

int main() {
    cout << "\n*************** <int> Circular Buffer Demo ******************\n";
    //  FINISH THIS SECTION
	cout << "\n\n";
	CircularBuffer<int, 5> buff = CircularBuffer<int, 5>();

	cout << "Initial state\n";
	cout << buff;
	cout << "\n\n";

	buff.push_back(0);
	cout << "Pushing 0\n";
	cout << buff;
	cout << "\n\n";

	buff.push_back(10);
	cout << "Pushing 10\n";
	cout << buff;
	cout << "\n\n";

	buff.push_back(20);
	cout << "Pushing 20\n";
	cout << buff;
	cout << "\n\n";

	buff.push_back(30);
	cout << "Pushing 30\n";
	cout << buff;
	cout << "\n\n";

	buff.push_back(40);
	cout << "Pushing 40\n";
	cout << buff;
	cout << "\n\n";

	buff.push_back(50);
	cout << "Pushing 50\n";
	cout << buff;
	cout << "\n\n";

	buff.push_back(60);
	cout << "Pushing 60\n";
	cout << buff;
	cout << "\n\n";

	buff.push_back(70);
	cout << "Pushing 70\n";
	cout << buff;
	cout << "\n\n";

	buff.pop();
	cout << "Popping: 30\n";
	cout << buff;
	cout << "\n\n";

	buff.pop();
	cout << "Popping: 40\n";
	cout << buff;
	cout << "\n\n";

	buff.pop();
	cout << "Popping: 50\n";
	cout << buff;
	cout << "\n\n";

	buff.pop();
	cout << "Popping: 60\n";
	cout << buff;
	cout << "\n\n";

	buff.pop();
	cout << "Popping: 70\n";
	cout << buff;
	cout << "\n\n";

	/* ____________________________________________________________________________________
	
	
								<string> CIRCULAR BUFFER DEMO
	
	
	_______________________________________________________________________________________*/

    cout << "\n*************** <string> Circular Buffer Demo ******************\n";
	cout << "\n\n";

	CircularBuffer<string, 5> buff2 = CircularBuffer<string, 5>();

	cout << "Initial state\n";
	cout << buff2;
	cout << "\n\n";

    //  FINISH THIS SECTION --
    // create a vector of words
    // use back_insert_iterator to fill the buffer
	vector<string> vec = { "of", "oz", "the", "wonderful", "world" };
	back_insert_iterator<CircularBuffer<string, 5>> back_it = back_inserter(buff2);

	copy(vec.begin(), vec.end(), back_it);

	cout << "After using back_insert_iterator\n";
	cout << buff2;
	cout << "\n\n";

	buff2.pop();
	cout << "Popping: the\n";
	cout << buff2;
	cout << "\n\n";

	buff2.pop();
	cout << "Popping: wonderful\n";
	cout << buff2;
	cout << "\n\n";

	buff2.pop();
	cout << "Popping: world\n";
	cout << buff2;
	cout << "\n\n";

	buff2.pop();
	cout << "Popping: of\n";
	cout << buff2;
	cout << "\n\n";

	buff2.pop();
	cout << "Popping: oz\n";
	cout << buff2;
	cout << "\n\n";

	/* ____________________________________________________________________________________


							<Dog> CIRCULAR BUFFER DEMO


_______________________________________________________________________________________*/

    cout << "\n*************** <Dog> Circular Buffer Demo ******************\n";
	cout << "\n\n";

	CircularBuffer<dog, 5> buff3 = CircularBuffer<dog, 5>();
	buff3.push_back(dog("Guinness", "Wheaten", 9));
	buff3.push_back(dog("Grimlock", "Lab", 2));
	buff3.push_back(dog("Optimus", "Bulldog", 5));
	buff3.push_back(dog("Murphy", "Lab", 14));
	buff3.push_back(dog("Floyd", "Beagle", 12));

	cout << buff3;
	cout << "\n";
	cout << "dogs Full?: " << buff3.full() << "\n\n";

	buff3.push_back(dog("Snoopy", "Beagle", 100));
	cout << buff3;
	cout << "\n\n";

	buff3.push_back(dog("Archie", "Brittany", 1));
	cout << buff3;
	cout << "\n\n";

	buff3.push_back(dog("Penny", "Beagle", 2));
	cout << buff3;
	cout << "\n\n";

	cout << "Popping:";
	cout << " " << buff3.tail();
	buff3.pop();
	cout << "\n\n";
	cout << buff3;
	cout << "\n\n";

	cout << "Popping:";
	cout << " " << buff3.tail();
	buff3.pop();
	cout << "\n\n";
	cout << buff3;
	cout << "\n\n";

	cout << "Popping:";
	cout << " " << buff3.tail();
	buff3.pop();
	cout << "\n\n";
	cout << buff3;
	cout << "\n\n";

	cout << "Popping:";
	cout << " " << buff3.tail();
	buff3.pop();
	cout << "\n\n";
	cout << buff3;
	cout << "\n\n";

	cout << "Popping:";
	cout << " " << buff3.tail();
	buff3.pop();
	cout << "\n\n";
	cout << buff3;
	cout << "\n\n";

    cout << endl;
}
