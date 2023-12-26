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

// #include "Array.tpp"
template<typename T>
Array<T>::Array()
	: _array(new T[0])
	, _len(0) {
	std::cout << "Array Default Constructor Called" << std::endl;
}

template<typename T>
Array<T>::Array(unsigned int n)
	: _array(new T[n])
	, _len(n) {
	std::cout << "Array Argument Constructor Called" << std::endl;
}

template<typename T>
Array<T>::Array(const Array& other) {
	std::cout << "Array Copy Constructor Called" << std::endl;
	this->_len = other._len;
	this->_array = new T[this->_len];
	for (size_t i = 0; i < _len; i++) {
		this->_array[i] = other._array[i];
	}
}

template<typename T>
Array<T>&	Array<T>::operator=(const Array& other) {
	std::cout << "Array Copy Assignment Operator Called" << std::endl;
	if (this != &other) {
		this->_len = other._len;
		if (this->_array != NULL)
			delete [] this->_array;
		this->_array = new T[this->_len];
		for (size_t i = 0; i < _len; i++) {
			this->_array[i] = other._array[i];
		}
	}
	return (*this);
}

template<typename T>
T&	Array<T>::operator[](size_t index) {
	if (index < 0 || index >= _len) {
		throw std::out_of_range("index out of range");
	}
	return (_array[index]);
}

template<typename T>
Array<T>::~Array() {
	std::cout << "Array Destructor Called" << std::endl;
	if (this->_array) {
		delete[] this->_array;
	}
}

template<typename T>
size_t	Array<T>::size() const{
	return (_len);
}

#endif
