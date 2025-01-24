#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(std::string input) : _input(input) {}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	*this = copy;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	if (this != &copy)
		_input = copy._input;
	return *this;
}

void ScalarConverter::convert(std::string input)
{
	// Check for char input
	if (input.length() == 1 && !isdigit(input[0]))
	{
		char c = input[0];
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
		return;
	}

	// Pseudo literals for science and "fun"
	if (input == "+inff" || input == "inff" || input == "+inf" || input == "inf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
        return;
    }
    if (input == "-inff" || input == "-inf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        return;
    }
    if (input == "nanf" || input == "nan")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
    }

	// Try to convert to int
	try
    {
        std::istringstream iss(input);
        long long i;
        if (iss >> i && iss.eof())
        {
            if (i < std::numeric_limits<int>::min() || i > std::numeric_limits<int>::max())
            {
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: Overflow" << std::endl;
            }
            else
            {
                std::cout << "char: ";
                if (i < 32 || i > 126)
                    std::cout << "Non displayable" << std::endl;
                else
                    std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
                std::cout << "int: " << static_cast<int>(i) << std::endl;
            }
            if (i < -std::numeric_limits<float>::max() || i > std::numeric_limits<float>::max())
                std::cout << "float: Overflow" << std::endl;
            else
                std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(i) << std::endl;
            return;
        }
    }
    catch(const std::exception& e) {}

	// Try to convert to float
	try
    {
        std::istringstream iss(input);
        double d;
        if (iss >> d && iss.eof())
        {
            if (d < -std::numeric_limits<float>::max() || d > std::numeric_limits<float>::max())
            {
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
                std::cout << "float: Overflow" << std::endl;
            }
            else
            {
                float f = static_cast<float>(d);
                std::cout << "char: ";
                if (f < 32 || f > 126)
                    std::cout << "Non displayable" << std::endl;
                else
                    std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
                std::cout << "int: ";
                if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
                    std::cout << "Overflow" << std::endl;
                else
                    std::cout << static_cast<int>(f) << std::endl;
                std::cout << "float: " << f << "f" << std::endl;
            }
            std::cout << "double: " << d << std::endl;
            return;
        }
    }
    catch(const std::exception& e) {}

	// Try to convert to double
	try
    {
        std::istringstream iss(input);
        double d;
        if (iss >> d && iss.eof())
        {
            std::cout << "char: ";
            if (d < 32 || d > 126)
                std::cout << "Non displayable" << std::endl;
            else
                std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
            std::cout << "int: ";
            if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
                std::cout << "Overflow" << std::endl;
            else
                std::cout << static_cast<int>(d) << std::endl;
            std::cout << "float: ";
            if (d < -std::numeric_limits<float>::max() || d > std::numeric_limits<float>::max())
                std::cout << "Overflow" << std::endl;
            else
                std::cout << static_cast<float>(d) << "f" << std::endl;
            std::cout << "double: " << d << std::endl;
            return;
        }
    }
	catch(const std::exception& e) {}

	std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

