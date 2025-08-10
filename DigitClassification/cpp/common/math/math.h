#ifndef MATH_H
#define MATH_H

#pragma once

#include <map>
#include <algorithm>
#include <vector>
#include <string>

class Node;

const std::vector<float> normalize(const std::vector<unsigned int>& UIntVec); 

inline void ReLU(Node& node, double val);

class Activation {
	public:
	Activation(const std::string name, Node& node) : name(name) {}; 
	
	private:
	const std::string name;
};


#endif
