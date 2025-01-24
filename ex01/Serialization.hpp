#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <iostream>
#include <stdint.h>
#include "Data.hpp"

class Serialization
{
	private:
		Serialization();

	public:
		~Serialization();
		Serialization(Serialization const &src);
		Serialization &operator=(Serialization const &src);

	static uintptr_t serialize(Data *ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif
