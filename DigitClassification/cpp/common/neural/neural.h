#ifndef NEURAL_H
#define NEURAL_H

#pragma once

#include <idxreader.h>
#include <math/math.h>

// Nodes
class Node {

	public:
	Node() : ID(hashKey++), weight(0.), bias(0.) {};
	Node(double w, double b) : ID(hashKey++), weight(w), bias(b) {}; 
	
	inline const double& getWeight() const {return weight;}
	inline const double& getBias() const {return bias;}
	
	inline void setWeight(double val) {weight = val;}
	inline void setBias(double val) {bias = val;}

	friend std::ostream &operator<<(std::ostream&, const Node&);

	private:
	inline static int hashKey = 0; 	// hashKey for random ID generation
	const int ID;		   	// const ID - secure
	double weight;		   	// Neuron weight
	double bias;		   	// Neuron bias
};


// Layers
class Layer{

	public:
	Layer() = default;
	Layer(const int nnodes) : ID(hashKey++), numNodes(nnodes) {
		numNodesIn = 0;
		numNodesOut = 0;
		setLayerNodes();
	}

	// Constructor :
	// - nnodes : (int) Number of nodes
	// - prev : (Layer&) Previous layer
	// - next : (Layer&) Next Layer
	
	Layer(const int nnodes, Layer &prev, Layer &next) : 
		ID(hashKey++), 
		numNodes(nnodes),
       		numNodesIn(prev.numNodes),
		numNodesOut(next.numNodes) {

		prev.numNodesOut = nnodes;
		next.numNodesIn = nnodes;

		setLayerNodes();
	}
	
	// Generate the node list
	void setLayerNodes() {
		for (int i=0; i<numNodes; i++)
			Nodes.push_back(Node());
	}

	inline const Node& getNode(int n) const {return Nodes.at(n);}

	inline int size() const {return Nodes.size();}

	friend std::ostream &operator<<(std::ostream&, const Layer&);

	private:
	inline static int hashKey = 0; // hashKey for random ID generation
	const int ID;		       // ID for secure
	const int numNodes;	       // Number of node in the layer
	int numNodesIn;
	int numNodesOut;
	
	protected:
	std::vector<Node> Nodes;	
};

class InputLayer : public Layer {
	public:
	InputLayer(const int nnodes) : Layer(nnodes) {}
	InputLayer(Image& img) : Layer(img.size()) {
		setupImage(img);
	}

	private:
	void setupImage(Image& img){
		for (int i=0; i<size(); i++){
			Nodes[i].setWeight(img.getPixel(i));
		}
	}
};

// Network
class Network {
	public:
	Network() = default;
	Network(std::vector<Layer> layers) : layers(layers) {}

	private:
	std::vector<Layer> layers;
};

std::ostream &operator<<(std::ostream &os, const Node &n);

std::ostream &operator<<(std::ostream &os, const Layer &lay);

#endif
