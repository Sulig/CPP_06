/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:26:17 by sadoming          #+#    #+#             */
/*   Updated: 2025/04/24 18:45:40 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static void test()
{
	std::cout << "Test function called" << std::endl;
	std::cout << "Test with char: 'a'" << std::endl;
	ScalarConverter::convert("a");
	std::cout << "Test with int: '42'" << std::endl;
	ScalarConverter::convert("42");
	std::cout << "Test with float: '42.0f'" << std::endl;
	ScalarConverter::convert("42.0f");
	std::cout << "Test with double: '42.0'" << std::endl;
	ScalarConverter::convert("42.0");
	std::cout << "Test with char: 'nan'" << std::endl;
	ScalarConverter::convert("nan");
	std::cout << "Test with char: 'nanf'" << std::endl;
	ScalarConverter::convert("nanf");
	std::cout << "Test with char: '+inf'" << std::endl;
	ScalarConverter::convert("+inf");
	std::cout << "Test with char: '-inf'" << std::endl;
	ScalarConverter::convert("-inf");
	std::cout << "Test with char: '+inff'" << std::endl;
	ScalarConverter::convert("+inff");
	std::cout << "Test with char: '-inff'" << std::endl;
	ScalarConverter::convert("-inff");
	std::cout << "Test with char: '0'" << std::endl;
	ScalarConverter::convert("0");
	std::cout << "Test with char: '0.0'" << std::endl;
	ScalarConverter::convert("0.0");
	std::cout << "Test with char: '0.0f'" << std::endl;
	ScalarConverter::convert("0.0f");
	std::cout << "Test with char: '1.0'" << std::endl;
	ScalarConverter::convert("1.0");
	std::cout << "Test with char: '1.0f'" << std::endl;
	ScalarConverter::convert("1.0f");
	std::cout << "Test with: '42.000001'" << std::endl;
	ScalarConverter::convert("42.000001");
	std::cout << "Test with: '42.000001f'" << std::endl;
	ScalarConverter::convert("42.000001f");
	std::cout << "Test with: 'MAX_INT'" << std::endl;
	ScalarConverter::convert("2147483647");
	std::cout << "Test with: 'MIN_INT'" << std::endl;
	ScalarConverter::convert("-2147483648");
	std::cout << "Test with: 'MAX_FLOAT'" << std::endl;
	ScalarConverter::convert("3.402823466e+38f");
	std::cout << "Test with: 'MIN_FLOAT'" << std::endl;
	ScalarConverter::convert("-3.402823466e+38f");
	std::cout << "Test with: 'MAX_DOUBLE'" << std::endl;
	ScalarConverter::convert("1.7976931348623157e+308");
	std::cout << "Test with: 'MIN_DOUBLE'" << std::endl;
	ScalarConverter::convert("-1.7976931348623157e+308");
}

int main(int argc, char **argv)
{
	if (argc != 2)
		test();
	else
	{
		std::string input = argv[1];
		ScalarConverter::convert(input);
	}
	return (0);
}
