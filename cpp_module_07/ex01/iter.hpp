#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template<typename T>
void	iter(T* array, std::size_t len, void (*f)(T)) {
	for (std::size_t i = 0; i < len; i++) {
		f(array[i]);
	}
}

#endif
