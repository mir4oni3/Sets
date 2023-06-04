#include "FileParser.h"
#include <iostream>

void start() {
	Set* s = FileParser::parse("set.dat");

	int key = 0;
	do {
		std::cout << std::endl << "1. Enter Interval" << std::endl;
		std::cout << "2. Generate Next" << std::endl;
		std::cout << "3. Exit" << std::endl;
		std::cin >> key;
		switch (key) {
		case 1:
			std::cout << "Enter a and b, b>=a:" << std::endl;
			uint32_t a, b;
			std::cin >> a >> b;
			s->print(a, b);
			break;
		case 2:
			s->printNext();
			break;
		}
	} while (key != 3);

	delete s;
}

int main() {
	try {
		start();
	}
	catch (const std::exception& e) {
		std::cout << "Exception!" << std::endl;
		std::cout << e.what() << std::endl;
	}
}

//Criteria set syntax

//#include "CriteriaSet.hpp"
//#include <iostream>
//
//class A {
//public:
//	bool operator()(int a) {
//		return a % 2 == 0;
//	}
//};
//
//bool func(int a) {
//	return a % 2 == 0;
//}
//
//int main() {
//	CriteriaSet<bool(*)(int)> funcptr(func);
//	std::cout << "funcptr" << std::endl;
//	std::cout << funcptr.contains(0) << std::endl;
//	std::cout << funcptr.contains(1) << std::endl;
//	std::cout << funcptr.contains(2) << std::endl;
//	std::cout << funcptr.contains(3) << std::endl;
//
//	CriteriaSet<bool(*)(int)> lambda([](int a) { return a % 2 == 0;  });
//	std::cout << "lambda" << std::endl;
//	std::cout << lambda.contains(0) << std::endl;
//	std::cout << lambda.contains(1) << std::endl;
//	std::cout << lambda.contains(2) << std::endl;
//	std::cout << lambda.contains(3) << std::endl;
//
//	A obj;
//	CriteriaSet<A> criteriaClass(obj);
//	std::cout << "criteria class" << std::endl;
//	std::cout << criteriaClass.contains(0) << std::endl;
//	std::cout << criteriaClass.contains(1) << std::endl;
//	std::cout << criteriaClass.contains(2) << std::endl;
//	std::cout << criteriaClass.contains(3) << std::endl;
//}
