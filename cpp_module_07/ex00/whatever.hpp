#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template<typename T>
void	swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T	min(const T& first, const T& second) {
	if (first < second)
		return (first);
	else
		return (second);
}

template<typename T>
T	max(const T& first, const T& second) {
	if (first > second)
		return (first);
	else
		return (second);
}

#endif
