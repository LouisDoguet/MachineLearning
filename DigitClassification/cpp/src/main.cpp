#include <neural/neural.h>

int main() {
	int node_id = 286;	
	const std::string pathName = "../database/t10k-images.idx3-ubyte";
	idxDatabase db(pathName);
	std::cout << db;
	Image im = db.read_image(500);
	std::cout << im;
	Neural::InputLayer lay(im);
	Neural::Layer lay1(10);
	Neural::Node n = lay.getNode(node_id);
	std::cout << lay1;
	std::cout << lay.getNode(node_id);
	n.activate(Math::Sigmoid);
	std::cout << lay.getNode(node_id);
	return 1;
}
