#pragma once
#include "UnionSet.h"

UnionSet::UnionSet(Set** sets, size_t setCount) {
	for (size_t i = 0; i < setCount; i++) {
		this->sets.push_back(SharedPtr<Set>(sets[i]));
	}
}

void UnionSet::uniteWith(Set* set) {
	this->sets.push_back(SharedPtr<Set>(set));
}

bool UnionSet::contains(uint32_t number) const {
	for (int i = 0; i < sets.getSize(); i++) {
		if ((*sets[i]).contains(number)) {
			return true;
		}
	}
	return false;
}