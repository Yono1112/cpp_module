#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal();
		virtual ~WrongAnimal();
		void		setType(std::string new_type);
		std::string	getType(void) const;
		virtual void		makeSound(void) const;
	protected:
		std::string	type;
};

#endif