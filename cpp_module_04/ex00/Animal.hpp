#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
	public:
		Animal();
		~Animal();
		void		setType(std::string new_type);
		std::string	getType(void);
		virtual void		makeSound(void);
	protected:
		std::string	type;
};

#endif