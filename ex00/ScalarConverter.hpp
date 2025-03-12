/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:46:23 by sadoming          #+#    #+#             */
/*   Updated: 2025/03/12 19:11:41 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>

# define TYPE_CHAR		0
# define TYPE_INT		1
# define TYPE_FLOAT		2
# define TYPE_DOUBLE	3
# define TYPE_UNKNOWN	-1

class	ScalarConverter
{
	public:
		static void	convert(const std::string &input);

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &src);

		virtual void	doNotInstantiate() const = 0;

		// Utilities
		static int		getType(const std::string &input);

};

#endif
