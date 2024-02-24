template<typename T, typename Container>
MutantStack<T, Container>::MutantStack() 
	: _container() {
	std::cout << "Default Constructor Called" << std::endl;
}

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack& other)
	: _container(other._container) {
	std::cout << "Copy Constructor Called" << std::endl;
}

template<typename T, typename Container>
MutantStack<T, Container>&	MutantStack<T, Container>::operator=(const MutantStack& other) {
	std::cout << "Copy Assignment Operator Called" << std::endl;
	if (this != &other) {
		_container = other._container;
	}
	return (*this);
}

template<typename T, typename Container>
MutantStack<T, Container>::~MutantStack() {
	std::cout << "Destructor Called" << std::endl;
}

template<typename T, typename Container>
void	MutantStack<T, Container>::push(const T& value) {
	_container.push_back(value);
}

template<typename T, typename Container>
void	MutantStack<T, Container>::pop() {
	if (_container.empty())
		return ;
	_container.pop_back();
}

template<typename T, typename Container>
T&	MutantStack<T, Container>::top() {
	if (_container.empty())
		throw std::out_of_range("stack is empty");
	return (_container.back());
}

template<typename T, typename Container>
bool	MutantStack<T, Container>::empty() {
	return (_container.empty());
}

template<typename T, typename Container>
size_t	MutantStack<T, Container>::size() {
	return (_container.size());
}

template<typename T, typename Container>
typename Container::iterator	MutantStack<T, Container>::begin() {
	// std::cout << "iterator" << std::endl;
	return (_container.begin());
}

template<typename T, typename Container>
typename Container::iterator	MutantStack<T, Container>::end() {
	return (_container.end());
}

template<typename T, typename Container>
typename Container::const_iterator	MutantStack<T, Container>::begin() const {
	// std::cout << "const_iterator" << std::endl;
	return (_container.begin());
}

template<typename T, typename Container>
typename Container::const_iterator	MutantStack<T, Container>::end() const {
	return (_container.end());
}

template<typename T, typename Container>
typename Container::reverse_iterator	MutantStack<T, Container>::rbegin() {
	// std::cout << "reverse_iterator" << std::endl;
	return (_container.rbegin());
}

template<typename T, typename Container>
typename Container::reverse_iterator	MutantStack<T, Container>::rend() {
	return (_container.rend());
}

template<typename T, typename Container>
typename Container::const_reverse_iterator	MutantStack<T, Container>::rbegin() const {
	// std::cout << "const_reverse_iterator" << std::endl;
	return (_container.rbegin());
}

template<typename T, typename Container>
typename Container::const_reverse_iterator	MutantStack<T, Container>::rend() const {
	return (_container.rend());
}

template<typename T, typename Container>
Container&	MutantStack<T, Container>::getContainer() {
	return (_container);
}
