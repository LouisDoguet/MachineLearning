#ifndef MATH_H
#define MATH_H

#include <map>
#include <algorithm>

const std::vector<float> normalize(const std::vector<unsigned int>& UIntVec) {
	unsigned int max = *std::max_element(UIntVec.begin(), UIntVec.end()); // References an iterator, deref it with *
	std::vector<float> FloatVec;
	FloatVec.reserve(UIntVec.size());
	for (int i=0; i < (int) UIntVec.size(); i++)
		FloatVec.push_back(static_cast<float>(UIntVec[i]/(float)max));
	return FloatVec;
};

inline void ReLU(auto& node, double val) { node.setWeight(std::max(0. , val));};

class Activation {
	public:
	Activation(const std::string name, auto& node) : name(name) {}; 
	
	private:
	const std::string name;
};


#endif
