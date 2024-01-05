#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>

class RPN {
	public:
		RPN();
		RPN(const RPN& other);
		~RPN();
		RPN& operator=(const RPN& other);
		void calcReversePolish(const char *c_str);
		static bool checkArguments(const char *argv);
	private:
		std::stack<int> _stack;
	private:
		void skipSpace(const std::string& str, size_t& i);
		static bool checkValidChar(const char c);
		static bool isArithmetic(const char c);
};

#endif
