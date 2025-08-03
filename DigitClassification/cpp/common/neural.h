#ifndef NEURAL_H
#define NEURAL_H

#include <random>


// Nodes
class Node {

	public:
	Node() = default;
	Node(const int id) : ID(id) {};
	Node(const int id, double w, double b)
	       : ID(id), weight(w), bias(b) {}; 
	
	const double& getWeight() const {return weight;}
	const double& getBias() const {return bias;}
	
	void setWeight(double val) {weight = val;}
	void setBias(double val) {bias = val;}

	friend std::ostream &operator<<(std::ostream&, Node&);

	private:
	inline static int hashKey; // hashKey for random ID generation
	const int ID;		   // const ID - secure
	double weight;		   // Neuron weight
	double bias;		   // Neuron bias
};


// Layers
class Layer{

	public:
	Layer() = default;
	Layer(const int nnodes) : ID(hashKey++), numNodes(nnodes) {}
	Layer(const int nnodes, Layer &neighbor, int order) : ID(hashKey++), numNodes(nnodes) {
		if (order > 0){
			numNodesIn = 0;
			numNodesOut = neighbor.numNodes;
			neighbor.numNodesIn = nnodes;
		}
		else{
			numNodesIn = neighbor.numNodes;
			numNodesOut = 0;
			neighbor.numNodesIn = nnodes;
		}
		setLayerNodes();
	}
	Layer(const int nnodes, Layer &prev, Layer &next) : ID(hashKey++), numNodes(nnodes) {
		numNodesIn = prev.numNodes;
		numNodesOut = next.numNodes;
		prev.numNodesOut = nnodes;
		next.numNodesIn = nnodes;

		setLayerNodes();
	}

	void setLayerNodes() {
		for (int i=0; i<numNodes; i++){
			Nodes.push_back(Node(i));
		}
	}

	friend std::ostream &operator<<(std::ostream&, Layer&);

	private:
	inline static int hashKey = 0;
	const int ID;
	const int numNodes;
	int numNodesIn;
	int numNodesOut;

	std::vector<Node> Nodes;	
};


// Network
class Network {
	public:
	Network() = default;
	Network(std::vector<Layer> layers) : layers(layers) {}

	private:
	std::vector<layer> layers;
}


std::ostream &operator<<(std::ostream &os, Node &n) {
	os << "NodeID : " << n.ID << std::endl
	   << "NodeW  : " << n.weight << std::endl
	   << "NodeB  : " << n.bias << std::endl;
	return os;
};

std::ostream &operator<<(std::ostream &os, Layer &lay) {
	os << "Layer Level       : " << lay.ID << std::endl
	   << "Layer numNodes    : " << lay.numNodes << std::endl
	   << "Layer numNodesIn  : " << lay.numNodesIn << std::endl
	   << "Layer numNodesOut : " << lay.numNodesOut << std::endl;
	return os;
}

#endif
