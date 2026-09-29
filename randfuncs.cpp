#include "randfuncs.h"

#include <random>
#include <stdexcept>

namespace {
std::mt19937& randomEngine() {
	static std::mt19937 engine(std::random_device{}());
	return engine;
}
}

int rollDie(int sides) {
	if (sides < 1) {
		throw std::invalid_argument("A die must have at least one side.");
	}

	std::uniform_int_distribution<int> distribution(1, sides);
	return distribution(randomEngine());
}

std::vector<int> rollDice(int count, int sides) {
	if (count < 0) {
		throw std::invalid_argument("The number of dice cannot be negative.");
	}

	std::vector<int> rolls;
	rolls.reserve(static_cast<std::size_t>(count));
	for (int index = 0; index < count; ++index) {
		rolls.push_back(rollDie(sides));
	}

	return rolls;
}
