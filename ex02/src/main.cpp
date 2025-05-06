/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:26:17 by sadoming          #+#    #+#             */
/*   Updated: 2025/05/06 19:30:23 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

int main()
{
	srand(time(NULL));
	/*********************************** */
	Base	*ptr1 = Base::generate();
	Base	*ptr2 = Base::generate();
	Base	*ptr3 = Base::generate();
	Base	*ptr4 = Base::generate();
	Base	*ptr5 = Base::generate();
	//**- */
	Base	&ref1 = *ptr1;
	Base	&ref2 = *ptr2;
	Base	&ref3 = *ptr3;
	Base	&ref4 = *ptr4;
	Base	&ref5 = *ptr5;
	//**- */
	//**- */
	std::cout << std::endl;
	//**- */


	std::cout << "Indentify class by pointer" << std::endl;
	Base::identify(ptr1);
	Base::identify(ptr2);
	Base::identify(ptr3);
	Base::identify(ptr4);
	Base::identify(ptr5);
	std::cout << std::endl;
	//**- */

	std::cout << "Indentify class by reference" << std::endl;
	Base::identify(ref1);
	Base::identify(ref2);
	Base::identify(ref3);
	Base::identify(ref4);
	Base::identify(ref5);
	Base::identify(NULL);
	std::cout << std::endl;
	/*********************************** */
	return (0);
}
