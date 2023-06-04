#pragma once
#include "CriteriaSet.hpp"
#include "IntersectionSet.h"
#include "UnionSet.h"
#include "HelperStructs.h"
#include "MyString.h"
#include <fstream>

class FileParser {
public:
	static Set* parse(const MyString& filename);
private:
	static Set* listedNumbers(std::ifstream&, uint16_t N);
	static Set* notDivisibleBy(std::ifstream&, uint16_t N);
	static Set* divisibleByOnlyOne(std::ifstream&, uint16_t N);
	static Set* unionFromFiles(std::ifstream&, uint16_t N);
	static Set* intersectionFromFiles(std::ifstream&, uint16_t N);
};