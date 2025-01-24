#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cctype>
#include <sstream>

class ScalarConverter
{
	private:
		std::string _input;
		ScalarConverter();

	public:
		ScalarConverter(std::string input);
		ScalarConverter(const ScalarConverter &copy);
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &copy);

		void static convert(std::string input);
};

#endif
