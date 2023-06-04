#pragma once
#include "IntersectionSet.h"

IntersectionSet::IntersectionSet(Set** sets, size_t setCount) {
	for (size_t i = 0; i < setCount; i++) {
		this->sets.push_back(SharedPtr<Set>(sets[i]));
	}
}

void IntersectionSet::intersectWith(Set* set) {
	this->sets.push_back(SharedPtr<Set>(set));
}

bool IntersectionSet::contains(uint32_t number) const {
	size_t size = sets.getSize();
	if (size == 0) {
		return false;
	}
	for (int i = 0; i < size; i++) {
		if (!(*sets[i]).contains(number)) {
			return false;
		}
	}
	return true;
}