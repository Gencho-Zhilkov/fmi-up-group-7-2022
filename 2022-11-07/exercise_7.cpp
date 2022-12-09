#include <iostream>


size_t min(size_t x, size_t y) {
	return x <= y ? x : y;
}

size_t min(size_t x, size_t y, size_t z) {
	return min(min(x, y), z);
}

size_t levenstein_distance(int *xs, size_t xlen, int *ys, size_t ylen) {
	if (xlen == 0) {
		return ylen;
	} else if (ylen == 0) {
		return xlen;
	} else if (xs[xlen-1] == ys[ylen-1]) {
		return levenstein_distance(xs, xlen-1, ys, ylen-1);
	} else {
		return 1 + min(
			levenstein_distance(xs, xlen-1, ys, ylen),
			levenstein_distance(xs, xlen,   ys, ylen-1),
			levenstein_distance(xs, xlen-1, ys, ylen-1)
		);
	}
}

int main() {
	{
		int xs[] = {1, 2, 3, 4};
		int ys[] = {1, 2, 3};
		std::cout << levenstein_distance(xs, 4, ys, 3) << std::endl;
	}
	{
		int xs[] = {1, 2, 3, 4};
		int ys[] = {1, 2, 4};
		std::cout << levenstein_distance(xs, 4, ys, 3) << std::endl;
	}
	{
		int xs[] = {1, 2, 3, 4};
		int ys[] = {1, 2, 4, 3};
		std::cout << levenstein_distance(xs, 4, ys, 4) << std::endl;
	}
	{
		int xs[] = {1, 2, 3, 4};
		int ys[] = {1, 2, 4, 5};
		std::cout << levenstein_distance(xs, 4, ys, 4) << std::endl;
	}
	return 0;
}
