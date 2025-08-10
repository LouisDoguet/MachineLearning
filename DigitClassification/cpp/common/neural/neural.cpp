#include <neural/neural.h>
#include <ostream>

namespace Neural {

std::ostream &operator<<(std::ostream &os, const Node &n) {
	os << "NodeID : " << n.ID << std::endl
	   << "NodeW  : " << n.weight << std::endl
	   << "NodeB  : " << n.bias << std::endl;
	return os;
};

std::ostream &operator<<(std::ostream &os, const Layer &lay) {
	os << "Layer Level       : " << lay.ID << std::endl
	   << "Layer numNodes    : " << lay.numNodes << std::endl
	   << "Layer numNodesIn  : " << lay.numNodesIn << std::endl
	   << "Layer numNodesOut : " << lay.numNodesOut << std::endl;
	return os;
};

}
