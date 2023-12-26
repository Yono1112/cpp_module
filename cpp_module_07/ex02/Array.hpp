#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <iostream>

template<typename T>
class Array {
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		Array& operator=(const Array& other);
		T& operator[](size_t index);
		~Array();
		size_t size() const;
	private:
		T*	_array;
		size_t	_len;
};

#include "Array.tpp"
#endif
