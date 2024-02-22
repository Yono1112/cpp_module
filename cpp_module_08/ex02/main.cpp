#include "MutantStack.hpp"
#include <stack>
#include <list>
#include <vector>
#include <stack>
#include <string>

void	testSubject() {
	std::cout << "================================" << std::endl;
	std::cout << "run testSubject" << std::endl;
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
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack.getContainer());
}

void	testInvalidStack() {
	std::cout << "================================" << std::endl;
	std::cout << "run testInvalidStack" << std::endl;
	try {
		MutantStack<int>	mstack;
		std::cout <<  mstack.size() << std::endl;
		mstack.top();
	} catch(const std::exception& e) {
		std::cout << "catch std::exception: " << e.what() << std::endl;
	}
	try {
		MutantStack<int>	mstack1;
		// if you comment in under two lines and compile, the compiler should output the error message because each type of container is different(mstack1 is std::deque and mstack2 is std::vector)!
		// MutantStack<double>	mstack2(mstack1);
		// MutantStack<int, std::vector<int> >	mstack2(mstack1);
		std::cout <<  mstack1.size() << std::endl;
		mstack1.top();
	} catch(const std::exception& e) {
		std::cout << "catch std::exception: " << e.what() << std::endl;
	}
}

void	testIterator() {
	std::cout << "================================" << std::endl;
	std::cout << "run testIterator" << std::endl;
	try {
		MutantStack<int>	 mstack1;

		std::cout << "mtack empty: " << std::boolalpha << mstack1.empty() << std::endl;
		std::cout << "mstack size: " << mstack1.size() << std::endl;
		for (int i = 0; i < 10; i++) {
			std::cout << "push: " << i << std::endl;
			mstack1.push(i);
			std::cout << "mstack top: " << mstack1.top() << std::endl;
		}
		std::cout << "mtack empty: " << std::boolalpha << mstack1.empty() << std::endl;
		std::cout << "mstack size: " << mstack1.size() << std::endl;
		std::cout << "iterator begin() and end()" << std::endl;
		for (MutantStack<int>::iterator it = mstack1.begin(); it != mstack1.end(); ++it) {
			std::cout << *it << std::endl;
		}
		std::cout << "revese_iterator rbegin() and rend()" << std::endl;
		for (MutantStack<int>::reverse_iterator it = mstack1.rbegin(); it != mstack1.rend(); ++it) {
			std::cout << *it << std::endl;
		}
	} catch (const std::exception& e) {
		std::cout << "catch std::exception: " << e.what() << std::endl;
	}
}

void	testVariousContainer() {
	std::cout << "================================" << std::endl;
	std::cout << "run testVariousContainer" << std::endl;
	{
		std::cout << "test std::vector" << std::endl;
		MutantStack<double, std::vector<double> > double_mstack;

		for (int i = 0; i < 10; i++) {
			std::cout << "push: " << i + 0.5 << std::endl;
			double_mstack.push(i + 0.5);
			std::cout << "double_mstack top: " << double_mstack.top() << std::endl;
		}
		std::cout << "copy to std::vector" << std::endl;
		std::vector<double> double_vec(double_mstack.getContainer());
		std::cout << "MutantStack size: " << double_mstack.size() << ", std::vector size: " << double_vec.size() << std::endl;
		for (std::vector<double>::size_type i = 0; i != double_vec.size(); i++) {
			std::cout << "double_vec at(" << i << "): " << double_vec.at(i) << std::endl;
		}
	}
	{
		std::cout << "test std::list" << std::endl;
		MutantStack<std::string, std::list<std::string> > str_mstack;
		for (int i = 0; i < 10; i++) {
			std::cout << "push: " << "hoge" << std::endl;
			str_mstack.push("hoge");
			std::cout << "str_mstack top: " << str_mstack.top() << std::endl;
		}
		std::cout << "str_mstack size: " << str_mstack.size() << std::endl;
		std::cout << "copy to std::list" << std::endl;
		std::list<std::string> str_lst;
		str_lst = str_mstack.getContainer();
		std::cout << "MutantStack size: " << str_mstack.size() << ", std::list size: " << str_lst.size() << std::endl;
		std::cout << "str::list pop" << std::endl;
		while (str_lst.size() != 0) {
			str_lst.pop_back();
		}
		std::cout << "MutantStack size: " << str_mstack.size() << ", std::list size: " << str_lst.size() << std::endl;
	}
}

int	main() {
	testSubject();
	testInvalidStack();
	testIterator();
	testVariousContainer();
	return (0);
}

// __attribute__((destructor))
// static void	destructor(void)
// {
// 	system("leaks -q stack");
// }

// Sample code for problems when inheriting std::stack
// 
// #include <iostream>
// #include <stack>
// #include <deque>

// class MyStack : public std::stack<int> {
// 	public:
// 		MyStack() {
// 			std::cout << "MyStack Constructor" << std::endl;
// 			a = new int(1);
// 		}
// 		~MyStack() {
// 			delete a;
// 			std::cout << "MyStack Destructor" << std::endl;
// 		}
// 	private:
// 		int* a;
// };

// int main() {
// 	std::stack<int>* ptr = new MyStack();
// 	// MyStack* mystack_ptr = new MyStack();

// 	delete ptr;
// 	// delete mystack_ptr;

// 	return 0;
// }

// __attribute__((destructor))
// static void	destructor(void)
// {
// 	system("leaks -q a.out");
// }