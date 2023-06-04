#pragma once
#include <iostream>

class Set {
	mutable uint32_t previous = UINT32_MAX; // keeping the last generated number from printNext
public:
	virtual bool contains(uint32_t number) const = 0;
	virtual void print(uint32_t start, uint32_t end) const;
	virtual void printNext() const; // starts from 0

	virtual ~Set() = default;
};