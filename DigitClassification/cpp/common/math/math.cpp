#include <math/math.h>
#include <neural/neural.h>
#include <cmath>

namespace Math {

const std::vector<float> normalize(const std::vector<unsigned int>& UIntVec) {
	unsigned int max = *std::max_element(UIntVec.begin(), UIntVec.end()); // References an iterator, deref it with *
	std::vector<float> FloatVec;
	FloatVec.reserve(UIntVec.size());
	for (int i=0; i < (int) UIntVec.size(); i++) {
		FloatVec.push_back(static_cast<float>(UIntVec[i]/(float)max));
	}
	return FloatVec;
};

void ReLU(Neural::Node& node, double val) { node.setWeight(std::max( 0. , val )); };
void Sigmoid(Neural::Node& node, double val) { node.setWeight(1.0/(1.0 + exp(val))); };

} // Namespace Math
