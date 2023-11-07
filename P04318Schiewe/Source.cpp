#include <iostream>
#include <random>
#include <queue>

/* Returns a priority queue, populated with random integers in range [min, max] inclusive
   Supposedly mt19937 is more evenly distributed than std::rand() */

std::priority_queue<int> generateBaskets(const int min, const int max, const int numBaskets) {
	std::random_device rd;
	std::mt19937 gen(rd());
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

	std::priority_queue<int> q{ generateBaskets(MIN_EMERALDS, MAX_EMERALDS, numBaskets) };

	int curr, emeraldCount = 0;
	for (int i = 0; i < numMinutes; i++) {
		curr = q.top();
		emeraldCount += curr;
		q.pop();
		q.push(curr / 2);
	}

	std::cout << "Dorothy has gathered " << emeraldCount << " emeralds!\n";
	return 0;
}

/* Some interesting notes about line 32:
   I tried passing "q" by reference to generateBaskets() to prevent an expensive copy op
   but the language / compiler is smart enough to optimize in either scenario. Very cool
   Tested average execution time with numBaskets, numMinutes = 10,000,000. Both take approx. 8750ms
   I assume "q" is assigned to the lvalue returned from generateBaskets()
   since the local var in the helper function goes out of scope following assignment */