#ifndef EASYFIND_TPP
#define EASYFIND_TPP

template<typename T>
bool	easyfind(T container, int num) {
	if (std::find(container.begin(), container.end(), num) == container.end())
		throw std::out_of_range("cannot find the given argument");
	else
		return (true);
}

#endif
