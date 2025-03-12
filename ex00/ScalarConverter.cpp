/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:46:14 by sadoming          #+#    #+#             */
/*   Updated: 2025/03/12 19:14:54 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

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

int		ScalarConverter::getType(const std::string &input)
{
	if (input.length() == 1 && !isdigit(input[0]))
		return (TYPE_CHAR);
	else if (input.length() > 1 && !input.find_first_not_of("0123456789") == std::string::npos)
		return (TYPE_INT);
	else if (input.find_first_of('.') != std::string::npos)
		return (TYPE_FLOAT);
	else if (input.find_first_of('.') != std::string::npos)
		return (TYPE_DOUBLE);
	return (TYPE_UNKNOWN);
}

/*	Conversion -> Used -> `Static_Cast`	*/
void	ScalarConverter::convert(const std::string &input)
{
	// Check type of input
	int	type = getType(input);
}

