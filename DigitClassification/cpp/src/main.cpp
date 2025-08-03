#include <idxreader.h>
#include <iostream>
#include <neural.h>

int main() {
	
	const std::string pathName = "../database/t10k-images.idx3-ubyte";
	idxDatabase db(pathName);
	std::cout << db;

	Image im = db.read_image(3);

	Layer lay0(800);
	Layer lay1(10, lay0,-1);
	std::cout << lay1;

	return 1;
}
