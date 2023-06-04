#pragma once
#include "Set.h"

void Set::print(uint32_t start, uint32_t end) const {
	if (start > end) {
		throw std::invalid_argument("start number should be smaller than end number.");
	}
	std::cout << "The numbers in the set between " << start << " and " << end << " are:" << std::endl;
	for (uint32_t i = start; i <= end; i++) {
		if (contains(i)) {
			std::cout << i << std::endl;
		}
	}
}

void Set::printNext() const {
	uint32_t i = previous + 1;
	std::cout << "The next number in the set is: " << std::endl;
	while (true) {
		if (i == UINT32_MAX) {
			std::cout << "You already generated the biggest 32-bit number in the set !" << std::endl;
			break;
		}
		if (contains(i)) {
			std::cout << i << std::endl;
			previous = i;
			break;
		}
		i++;
	}
}