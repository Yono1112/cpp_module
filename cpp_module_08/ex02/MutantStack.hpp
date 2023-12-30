#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <deque>
#include <iostream>

template<typename T, typename Container = std::deque<T> >
class MutantStack {
	public:
		MutantStack();
		MutantStack(const MutantStack& other);
		~MutantStack();
		MutantStack& operator=(const MutantStack& other);
		void	push(const T& value);
		void	pop();
		T&	top();
		bool	empty();
		size_t	size();
	private:
		Container _container;
};

#include "MutantStack.tpp"

#endif
