#include "Serializer.hpp"
#include <cassert>

int main() {
	// assert(sizeof(void *) == sizeof(uintptr_t));
	Data d1;
	d1.num = 10;

	uintptr_t uint_ptr = Serializer::serialize(&d1);
	Data* d2 = Serializer::deserialize(uint_ptr);

	std::cout << "original Data ptr: " << &d1 << std::endl;
	std::cout << "Converted Data ptr: " << d2 << std::endl;

	std::cout << "original Data value: " << d1.num << std::endl;
	std::cout << "Converted Data value: " << d2->num << std::endl;
	return (0);
}
