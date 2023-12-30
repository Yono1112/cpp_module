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
		T&	top() {
			if (_container.empty())
				throw std::out_of_range("stack is empty");
			return (_container.back());
		};
		bool	empty() {
			return (_container.empty());
		};
		size_t	size() {
			return (_container.size());
		};
	private:
		Container _container;
};

#include "MutantStack.tpp"

#endif
