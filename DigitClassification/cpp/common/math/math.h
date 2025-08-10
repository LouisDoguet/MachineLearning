#ifndef MATH_H
#define MATH_H

#include <map>
#include <algorithm>
#include <vector>
#include <string>

#pragma once

namespace Neural { class Node; }

namespace Math {

const std::vector<float> normalize(const std::vector<unsigned int>& UIntVec); 

void ReLU(Neural::Node& node, double val); 
void Sigmoid(Neural::Node& node, double val); 

} // Namespace Math

#endif
