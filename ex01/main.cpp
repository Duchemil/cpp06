#include "Serialization.hpp"

int main()
{
	Data data;
	data.s1 = "Hello";
	data.n = 42;
	data.s2 = "World";

	std::cout << "s1: " << data.s1 << std::endl;
	std::cout << "n: " << data.n << std::endl;
	std::cout << "s2: " << data.s2 << std::endl;

	uintptr_t raw = Serialization::serialize(&data);
	Data *ptr = Serialization::deserialize(raw);

	std::cout << "s1: " << ptr->s1 << std::endl;
	std::cout << "n: " << ptr->n << std::endl;
	std::cout << "s2: " << ptr->s2 << std::endl;

	return 0;
}
