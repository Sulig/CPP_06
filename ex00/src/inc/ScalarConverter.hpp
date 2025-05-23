/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:46:23 by sadoming          #+#    #+#             */
/*   Updated: 2025/04/24 18:56:09 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>

# define TYPE_CHAR		0
# define TYPE_INT		1
# define TYPE_FLOAT		2
# define TYPE_DOUBLE	3
# define TYPE_PSEUDO_F	4
# define TYPE_PSEUDO_D	5
# define TYPE_UNKNOWN	-1

class	ScalarConverter
{
	public:
		static void	serialize(const std::string &input);

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &src);

		virtual void	doNotInstantiate() const = 0;

		// Utilities
		static void	displayChar(const int value);
		static int	getType(const std::string &input);
		static int	setPrecision(const std::string &input);
		static int	ft_atoi(const std::string str);

};

#endif
