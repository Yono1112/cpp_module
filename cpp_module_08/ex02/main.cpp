#include "MutantStack.hpp"
#include <stack>

void	testSubject() {
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.top() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(2147483647);
	mstack.push(-2147483648);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	std::cout << "hello" << std::endl;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack.getContainer());
	std::cout << "copy from MutantStack<int> to std::stack<int>" << std::endl;
	std::cout << "pop std::stack<int>" << std::endl;
	while (s.size() != 0) {
		std::cout << s.top() << std::endl;
		s.pop();
	}
}

int	main() {
	testSubject();
	// testInvalidStack();
	// testVector();
	// testList();
	// try {
	// 	MutantStack<int>	 mstack1;
	// 	// MutantStack<int, std::vector<int> >	 mstack2(mstack1);

	// 	std::cout << "mstack size: " << mstack1.size() << std::endl;
	// 	mstack1.push(1);
	// 	mstack1.pop();
	// 	std::cout << "mtack empty: " << std::boolalpha << mstack1.empty() << std::endl;
	// 	for (int i = 0; i < 10; i++) {
	// 		std::cout << "push: " << i << std::endl;
	// 		mstack1.push(i);
	// 		std::cout << "mstack top: " << mstack1.top() << std::endl;
	// 	}
	// 	std::cout << "mtack empty: " << std::boolalpha << mstack1.empty() << std::endl;
	// 	std::cout << "mstack size: " << mstack1.size() << std::endl;
	// 	for (MutantStack<int>::iterator it = mstack1.begin(); it != mstack1.end(); ++it) {
	// 		std::cout << *it << std::endl;
	// 	}
	// 	for (MutantStack<int>::reverse_iterator it = mstack1.rbegin(); it != mstack1.rend(); ++it) {
	// 		std::cout << *it << std::endl;
	// 	}
	// } catch (const std::exception& e) {
	// 	std::cout << "catch std::exception: " << e.what() << std::endl;
	// }
	return (0);
}

// __attribute__((destructor))
// static void	destructor(void)
// {
// 	system("leaks -q stack");
// }
