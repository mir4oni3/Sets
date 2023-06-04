#pragma once
#include "Set.h"
#include "Vector.hpp"
#include "SharedPtr.hpp"
#include <iostream>

class IntersectionSet : public Set {
	MyVector<SharedPtr<Set>> sets;
public:
	IntersectionSet(Set** sets, size_t setCount);
	IntersectionSet() = default;

	void intersectWith(Set* set);

	bool contains(uint32_t number) const override;
};