#include "Array.hpp"
#define MAX_VAL 500

void	test_subject() {
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));

	std::cout << "numbers.size(): " << numbers.size() << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	std::cout << "SCOPE" << std::endl;
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	std::cout << "COMPARE" << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return ;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;
	return ;
}

int	main() {
	// Array<int>	int_array(10);

	// for (size_t i = 0; i < 10; i++) {
	// 	int_array[i] = i;
	// 	std::cout << "array[" << i << "]: " << int_array[i] << std::endl;
	// }
	// try {
	// 	int_array[-2] = 0;
	// } catch (const std::exception& e) {
	// 	std::cerr << e.what() << std::endl;
	// }
	// try {
	// 	int_array[11] = 0;
	// } catch (const std::exception& e) {
	// 	std::cerr << e.what() << std::endl;
	// }
	test_subject();
	return (0);
}

__attribute__((destructor))
static void	destructor(void)
{
	system("leaks -q array");
}
