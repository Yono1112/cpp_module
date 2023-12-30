#include "MutantStack.hpp"

int	main() {
	MutantStack<int, std::deque<int> >	 mstack1;
	MutantStack<int>	 mstack2(mstack1);
	MutantStack<int>	 mstack3;

	mstack3 = mstack1;
	return (0);
}
