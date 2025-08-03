#include <idxreader.h>
#include <iostream>
#include <neural.h>

int main() {
	
	const std::string pathName = "../database/t10k-images.idx3-ubyte";
	idxDatabase db(pathName);
	std::cout << db;

	Image im = db.read_image(3);
	std::cout << im;
	InputLayer lay(im);
	Layer lay1(10);
	std::cout << lay1;
	std::cout << lay.getNode(399);
	return 1;
}
