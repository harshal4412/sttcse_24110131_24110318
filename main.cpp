#include "randfuncs.h"

#include <iostream>
#include <numeric>
#include <stdexcept>

int main() {
	int count;
	int sides;

	std::cout << "Number of dice: ";
	if (!(std::cin >> count)) {
		std::cerr << "Please enter a valid number.\n";
		return 1;
	}

	std::cout << "Number of sides per die: ";
	if (!(std::cin >> sides)) {
		std::cerr << "Please enter a valid number.\n";
		return 1;
	}

	try {
		const std::vector<int> rolls = rollDice(count, sides);
		const int total = std::accumulate(rolls.begin(), rolls.end(), 0);

		std::cout << "Rolls:";
		for (const int roll : rolls) {
			std::cout << ' ' << roll;
		}
		std::cout << "\nTotal: " << total << '\n';
	} catch (const std::invalid_argument& error) {
		std::cerr << "Invalid dice settings: " << error.what() << '\n';
		return 1;
	}

	return 0;
}
