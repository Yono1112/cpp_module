#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

#include <string>
#include <iostream>
#include "Animal.hpp"
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	public:
		WrongCat();
		~WrongCat();
		void	makeSound(void) const;
};

#endif