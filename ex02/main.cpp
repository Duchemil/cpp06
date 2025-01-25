#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{

	Base *basePtr = generate();

	std::cout << "Identifying using pointer: ";
	identify(basePtr);

	std::cout << "Identifying using reference: ";
	identify(*basePtr);

	delete basePtr;

    return 0;
}
