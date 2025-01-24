#include "ScalarConverter.hpp"

void testConversion(const std::string &input)
{
    std::cout << "Testing input: " << input << std::endl;
    ScalarConverter::convert(input);
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        std::string input = argv[1];
        testConversion(input);
    }
    else
    {
        testConversion("a");        // Single character
        testConversion("42");       // Integer
        testConversion("-3.14");    // Float
        testConversion("2.71828");  // Double
        testConversion("nanf");     // Not a number float
        testConversion("inff");     // Positive infinity float
        testConversion("-inf");     // Negative infinity int
        testConversion("123456789000000"); // Large number that doesn't fit in int
        testConversion("0");        // Zero
        testConversion(" ");        // Space
    }

    return 0;
}
