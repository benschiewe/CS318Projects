#include <iostream>
#include <random>
#include <queue>

std::priority_queue<int> generateBaskets(const int min, const int max, const int numBaskets) {	// Returns a priority queue, populated with
	std::random_device rd;																		// random integers in range [min, max] inclusive
	std::mt19937 gen(rd());																		// Supposedly mt19937 is more evenly distributed than std::rand()
	std::uniform_int_distribution<> distr(min, max);
	std::priority_queue<int> q;

	for (int i = 0; i < numBaskets; i++) {
		q.push(distr(gen));
	}
	return q;
}

int main() {
	const int MIN_EMERALDS = 1, MAX_EMERALDS = 1000;

	int numBaskets, numMinutes;
	std::cout << "**** Dorothy and Emeralds ****\n\n";
	std::cout << "Enter the number of baskets: ";
	std::cin >> numBaskets;
	std::cout << "\n";
	std::cout << "Enter the number of minutes: ";
	std::cin >> numMinutes;

	std::cout << "\n";
	std::priority_queue<int> q{ generateBaskets(MIN_EMERALDS, MAX_EMERALDS, numBaskets) };		// Constructs a new priority queue given the p_queue returned from generateBaskets()
																								// Some interesting notes...
	int curr, emeraldCount = 0;																	// I tried passing "q" by reference to generateBaskets to prevent an "expensive" copy op...
	for (int i = 0; i < numMinutes; i++) {														// But the compiler is smart enough to optimize in either scenario. Very cool
		curr = q.top();																			// Tested average time with numBaskets, numMinutes = 10,000,000. Both take approx 8750ms
		emeraldCount += curr;																	// I assume "q" is assigned to the lvalue returned from generateBaskets(),
		q.pop();																				// since the local var in the helper function goes out of scope following assignment on line 29.
		q.push(curr / 2);
	}

	std::cout << "Dorothy has gathered " << emeraldCount << " emeralds!\n";
	return 0;
}