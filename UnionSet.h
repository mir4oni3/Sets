#pragma once
#include "Set.h"
#include "Vector.hpp"
#include "SharedPtr.hpp"
#include <iostream>

class UnionSet : public Set {
	MyVector<SharedPtr<Set>> sets;
public:
	UnionSet(Set** sets, size_t setCount);
	UnionSet() = default;

	void uniteWith(Set* set);

	bool contains(uint32_t number) const override;
};