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
