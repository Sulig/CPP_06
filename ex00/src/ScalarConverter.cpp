/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:46:14 by sadoming          #+#    #+#             */
/*   Updated: 2025/04/24 17:50:31 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/*	Conversion -> Used -> `Static_Cast`	*/

/* Constructor & destructor */
ScalarConverter::ScalarConverter()	{	std::cout << "ScalarConverter default constructor called" << std::endl;	}
ScalarConverter::ScalarConverter(const ScalarConverter &src) { (void)src; }
ScalarConverter::~ScalarConverter()	{	std::cout << "ScalarConverter destructor called" << std::endl;			}
/* ----- */

/* Operator overloads */
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src) { (void)src; return *this; }
/* ----- */

/* Functions */
////void	ScalarConverter::doNotInstantiate() const { return ; }

void	ScalarConverter::displayChar(const int value)
{
	if (value < 0 || value > 127)
		std::cout << "char: \t\t|Impossible" << std::endl;
	else if (isprint(value))
		std::cout << "char: \t\t|" << static_cast<char>(value) << std::endl;
	else
		std::cout << "char: \t\t|Non displayable" << std::endl;
}

int		ScalarConverter::getType(const std::string &input)
{
	if (input.length() == 1 && !isdigit(input[0]))
		return (TYPE_CHAR);
	else if (input.find_first_of('.') != std::string::npos && input.find_first_of('f') != std::string::npos)
		return (TYPE_FLOAT);
	else if (input.find_first_of('.') != std::string::npos)
		return (TYPE_DOUBLE);
	else if (ft_atoi(input) != 0 || input == "0")
		return (TYPE_INT);
	else if (input == "-inf" || input == "+inf" || input == "nan")
		return (TYPE_PSEUDO_D);
	else if (input == "-inff" || input == "+inff" || input == "nanf")
		return (TYPE_PSEUDO_F);
	return (TYPE_UNKNOWN);
}

/*---------------------------------------*/
void	ScalarConverter::convert(const std::string &input)
{
	// Check type of input
	int	type = getType(input);
	int	precision = 1;
	int	intValue = 0;
	float	floatValue = 0.0f;
	double	doubleValue = 0.0;

	switch (type)
	{
		case TYPE_CHAR:
			std::cout << "char: \t\t|" << input[0] << std::endl;
			std::cout << "int:  \t\t|" << static_cast<int>(input[0]) << std::endl;
			std::cout << "float: \t\t|" << static_cast<float>(input[0]) << "f" << std::endl;
			std::cout << "double: \t|" << static_cast<double>(input[0]) << std::endl;
			break;

		case TYPE_INT:
			intValue = ft_atoi(input);
			displayChar(intValue);
			std::cout << "int:  \t\t|" << intValue << std::endl;
			std::cout << "float: \t\t|" << static_cast<float>(intValue) << ".0f" << std::endl;
			std::cout << "double: \t|" << static_cast<double>(intValue) << ".0" << std::endl;
			break;

		case TYPE_FLOAT:
			precision = setPrecision(input);
			floatValue = std::strtof(input.c_str(), NULL); // Convert string to float
			doubleValue = static_cast<double>(floatValue);
			intValue = static_cast<int>(floatValue);
			displayChar(intValue);
			std::cout << "int:  \t\t|" << intValue << std::endl;
			std::cout << "float: \t\t|" << std::fixed << std::setprecision(precision) << floatValue << "f" << std::endl;
			std::cout << "double: \t|" << std::fixed << std::setprecision(precision) << doubleValue << std::endl;
			break;

		case TYPE_DOUBLE:
			precision = setPrecision(input);
			doubleValue = std::strtod(input.c_str(), NULL); // Convert string to double
			intValue = static_cast<int>(doubleValue);
			floatValue = static_cast<float>(doubleValue);
			displayChar(intValue);
			std::cout << "int:  \t\t|" << intValue << std::endl;
			std::cout << "float: \t\t|" << std::fixed << std::setprecision(precision) << floatValue << "f" << std::endl;
			std::cout << "double: \t|" << std::fixed << std::setprecision(precision) << doubleValue << std::endl;
			break;

		case TYPE_PSEUDO_F:
			displayChar(-1);
			std::cout << "int:  \t\t|Impossible" << std::endl;
			std::cout << "float: \t\t|" << input << std::endl;
			std::cout << "double: \t|" << input.substr(0, input.length() - 1) << std::endl;
			break;

		case TYPE_PSEUDO_D:
			displayChar(-1);
			std::cout << "int:  \t\t|Impossible" << std::endl;
			std::cout << "float: \t\t|" << input << "f" << std::endl;
			std::cout << "double: \t|" << input << std::endl;
			break;

		default:
			std::cout << "char: \t\t|Impossible" << std::endl;
			std::cout << "int:  \t\t|Impossible" << std::endl;
			std::cout << "float: \t\t|Impossible" << std::endl;
			std::cout << "double: \t|Impossible" << std::endl;
			break;
	}
}
/*---------------------------------------*/

/** Utilities */
int	ScalarConverter::setPrecision(const std::string &input)
{
	int	precision = 1;
	size_t	pos = input.find('.');

	if (pos != std::string::npos)
	{
		precision = input.length() - pos - 1;
		if (input.find('f') != std::string::npos)
			precision--;
	}
	return (precision);
}

int	ScalarConverter::ft_atoi(const std::string str)
{
	int		cnt;
	int		sign;
	int		find;

	find = '\0';
	cnt = -1;
	sign = 1;
	while (str[++cnt] < 33)
		if ((str[cnt] < 9 || str[cnt] > 13) && str[cnt] != ' ')
			return ('\0');
	if (str[cnt] == '-' || str[cnt] == '+')
	{
		if (str[cnt] == '-')
			sign *= -1;
		cnt++;
	}
	while (str[cnt] >= '0' && str[cnt] <= '9')
	{
		find *= 10;
		find += str[cnt] - '0';
		cnt++;
	}
	return (find * sign);
}
/*---------------------------------------*/
