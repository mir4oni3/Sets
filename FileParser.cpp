#pragma once
#include "FileParser.h"
#include "HelperStructs.h"
#include "MyString.h"
#include <fstream>

Set* FileParser::parse(const MyString& filename) {
	std::ifstream input(filename.c_str(), std::ios::binary);
	if (!input.is_open()) {
		throw std::exception("Couldn't open file.");
	}

	uint16_t N = 0;
	input.read((char*)&N, sizeof(N));
	if (N > 32) {
		throw std::exception("Incorrect data in file.");
	}

	uint16_t T = 0;
	input.read((char*)&T, sizeof(T));
	switch (T) {
		case 0: return listedNumbers(input, N); break;
		case 1: return notDivisibleBy(input, N); break;
		case 2: return divisibleByOnlyOne(input, N); break;
		case 3: return unionFromFiles(input, N); break;
		case 4: return intersectionFromFiles(input, N); break;
		default: throw std::exception("Incorrect data in file.");
	}

	return nullptr;
}

Set* FileParser::listedNumbers(std::ifstream& input, uint16_t N) {
	ListedNumbers ln; // helperStructs.h
	uint32_t number;
	for (uint16_t i = 0; i < N; i++) {
		input.read((char*)&number, sizeof(number));
		ln.values.push_back(number);
	}
	CriteriaSet<ListedNumbers>* crSet = new CriteriaSet<ListedNumbers>(ln);
	input.close();
	return crSet;
}

Set* FileParser::notDivisibleBy(std::ifstream& input, uint16_t N) {
	NotDivisibleBy ndb; // helperStructs.h
	uint32_t number = 0;
	for (uint16_t i = 0; i < N; i++) {
		input.read((char*)&number, sizeof(number));
		ndb.values.push_back(number);
	}
	CriteriaSet<NotDivisibleBy>* crSet = new CriteriaSet<NotDivisibleBy>(ndb);
	input.close();
	return crSet;
}

Set* FileParser::divisibleByOnlyOne(std::ifstream& input, uint16_t N) {
	DivisibleByOnlyOne dboo; // helperStructs.h
	uint32_t number = 0;
	for (uint16_t i = 0; i < N; i++) {
		input.read((char*)&number, sizeof(number));
		dboo.values.push_back(number);
	}
	CriteriaSet<DivisibleByOnlyOne>* crSet = new CriteriaSet<DivisibleByOnlyOne>(dboo);
	input.close();
	return crSet;
}

Set* FileParser::unionFromFiles(std::ifstream& input, uint16_t N) {
	MyVector<MyString> filepaths;
	MyVector<char> current;
	for (uint16_t i = 0; i < N; i++) {
		char ch = 0;
		while (true) {
			ch = input.get();
			current.push_back(ch);
			if (ch == '\0') {
				break;
			}
		}
		char* str = new char[current.getSize()];
		for (size_t j = 0; j < current.getSize(); j++) {
			str[j] = current[j];
		}
		filepaths.push_back(MyString(str));
		current.clear();
		delete[] str;
	}

	UnionSet* us = new UnionSet;
	for (size_t i = 0; i < filepaths.getSize(); i++) {
		us->uniteWith(parse(filepaths[i]));
	}

	return us;
}

Set* FileParser::intersectionFromFiles(std::ifstream& input, uint16_t N) {
	MyVector<MyString> filepaths;
	MyVector<char> current;
	for (uint16_t i = 0; i < N; i++) {
		char ch = 0;
		while (true) {
			ch = input.get();
			current.push_back(ch);
			if (ch == '\0') {
				break;
			}
		}
		char* str = new char[current.getSize()];
		for (size_t j = 0; j < current.getSize(); j++) {
			str[j] = current[j];
		}
		filepaths.push_back(MyString(str));
		current.clear();
		delete[] str;
	}

	IntersectionSet* is = new IntersectionSet;
	for (size_t i = 0; i < filepaths.getSize(); i++) {
		is->intersectWith(parse(filepaths[i]));
	}
	return is;
}