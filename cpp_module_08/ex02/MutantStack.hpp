#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <deque>
#include <iostream>

template<typename T, typename Container = std::deque<T> >
class MutantStack {
	public:
		typedef typename Container::iterator iterator;
		MutantStack();
		MutantStack(const MutantStack& other);
		~MutantStack();
		MutantStack& operator=(const MutantStack& other);
		void	push(const T& value);
		void	pop();
		T&	top();
		bool	empty();
		size_t	size();
		iterator	begin()
		{
			return (_container.begin());
		};
		iterator	end()
		{
			return (_container.end());
		}
	private:
		Container _container;
};

#include "MutantStack.tpp"

#endif
