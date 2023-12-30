#include "MutantStack.hpp"

int	main() {
	try {
		MutantStack<int>	 mstack1;
		// MutantStack<int, std::vector<int> >	 mstack2(mstack1);

		std::cout << "mstack size: " << mstack1.size() << std::endl;
		mstack1.push(1);
		mstack1.pop();
		std::cout << "mtack empty: " << std::boolalpha << mstack1.empty() << std::endl;
		for (int i = 0; i < 10; i++) {
			std::cout << "push: " << i << std::endl;
			mstack1.push(i);
			std::cout << "mstack top: " << mstack1.top() << std::endl;
		}
		std::cout << "mtack empty: " << std::boolalpha << mstack1.empty() << std::endl;
		std::cout << "mstack size: " << mstack1.size() << std::endl;
	} catch (const std::exception& e) {
		std::cout << "catch std::exception: " << e.what() << std::endl;
	}
	return (0);
}
