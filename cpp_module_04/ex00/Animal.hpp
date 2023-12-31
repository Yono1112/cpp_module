#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
	public:
		Animal();
		virtual ~Animal();
		Animal(const Animal& other);
		Animal&	operator=(const Animal& other);
		void		setType(std::string new_type);
		std::string	getType(void) const;
		virtual void		makeSound(void) const;
	protected:
		std::string	type;
};

#endif