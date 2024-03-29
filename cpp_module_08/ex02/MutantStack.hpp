#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <deque>
#include <iostream>
#include <stack>

template<typename T, typename Container = std::deque<T> >
class MutantStack {
	public:
		typedef typename Container::iterator iterator;
		typedef typename Container::reverse_iterator reverse_iterator;
		typedef typename Container::const_iterator const_iterator;
		typedef typename Container::const_reverse_iterator const_reverse_iterator;
		typedef typename Container::value_type value_type;
		typedef typename Container::size_type size_type;
		MutantStack();
		MutantStack(const MutantStack& other);
		~MutantStack();
		MutantStack& operator=(const MutantStack& other);
		void	push(const T& value);
		void	pop();
		T&	top();
		bool	empty();
		size_t	size();
		iterator	begin();
		iterator	end();
		const_iterator	begin() const;
		const_iterator	end() const;
		reverse_iterator	rbegin();
		reverse_iterator	rend();
		const_reverse_iterator	rbegin() const;
		const_reverse_iterator	rend() const;
		Container&	getContainer();
	private:
		Container _container;
};

#include "MutantStack.tpp"

#endif
