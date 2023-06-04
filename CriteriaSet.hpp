#pragma once
#include "Set.h"
#include <iostream>

template <typename T>
class CriteriaSet : public Set {
	mutable T criteria; // mutable because operator() may be const
public:
	//following constructors are intended to accept bool(*)(int), lambda functions or object of 
	//a class with predefined operator()(int) *const*
	CriteriaSet(const T& criteria);
	CriteriaSet(T&& criteria); // can be called if criteria is a class with implemented move semantics

	bool contains(uint32_t number) const override;
};

template <typename T>
CriteriaSet<T>::CriteriaSet(const T& cr) : criteria(cr) {}

template <typename T>
CriteriaSet<T>::CriteriaSet(T&& cr) : criteria(std::move(cr)) {}

template <typename T>
bool CriteriaSet<T>::contains(uint32_t number) const {
	return criteria(number);
}