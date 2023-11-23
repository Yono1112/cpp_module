#ifndef CAT_HPP
# define CAT_HPP

#include <string>
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
	public:
		Cat();
		~Cat();
		void	makeSound(void) const;
	private:
		Brain*	brain_ptr;
};

#endif