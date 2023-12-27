#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <vector>

template<typename T>
T::iterator	easyfind(T container, int num) {
	T::iterator it = std::find(container.begin(), container.end(), num);
	if (it == container.end())
		throw std::out_of_range("cannot find the given argument");
	else
		return (it);
}

#endif
