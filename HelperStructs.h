#pragma once
#include "Vector.hpp"
#include <iostream>

struct ListedNumbers {
	MyVector<uint32_t> values;
	bool operator()(uint32_t number) {
		for (size_t i = 0; i < values.getSize(); i++) {
			if (number == values[i]) {
				return true;
			}
		}
		return false;
	}
};

struct NotDivisibleBy {
	MyVector<uint32_t> values;
	bool operator()(uint32_t number) {
		for (size_t i = 0; i < values.getSize(); i++) {
			if (values[i] != 0 && number % values[i] == 0) {
				return false;
			}
		}
		return true;
	}
};

struct DivisibleByOnlyOne {
	MyVector<uint32_t> values;
	bool operator()(uint32_t number) {
		bool flag = false;
		for (size_t i = 0; i < values.getSize(); i++) {
			if (values[i] != 0 && number % values[i] == 0) {
				if (flag) {
					return false;
				}
				else {
					flag = true;
				}
			}
		}
		return flag;
	}
};

