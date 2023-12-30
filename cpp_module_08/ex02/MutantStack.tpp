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

