#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	std::srand(std::time(0));

	int random = std::rand() % 3;

	if (random == 0)
		return new A();
	else if (random == 1)
		return new B();
	else
		return new C();
}

void identify(Base* p)
{
	// Dynamic cast returns a null pointer if the cast fails with a pointer
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	// Dynamic cast throws an exception if the cast fails with a reference
    try
    {
        A& a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
		(void)a;
        return;
    }
    catch (std::exception &e) {}

    try
    {
        B& b = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
		(void)b;
        return;
    }
    catch (std::exception &e) {}

    try
    {
        C& c = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
		(void)c;
        return;
    }
    catch (std::exception &e) {}
}
