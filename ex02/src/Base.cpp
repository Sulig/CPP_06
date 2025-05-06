/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:46:14 by sadoming          #+#    #+#             */
/*   Updated: 2025/04/24 17:50:31 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

/*	Conversion -> Used -> `Dynamic_Cast`	*/

/* Constructor & destructor */
Base::Base()	{	std::cout << "Base default constructor called" << std::endl;	}
Base::Base(const Base &src) { (void)src; }
Base::~Base()	{	std::cout << "Base destructor called" << std::endl;			}
/* ----- */

/* Operator overloads */
Base &Base::operator=(const Base &src) { (void)src; return *this; }
/* ----- */

/* Functions */
/*---------------------------------------*/
Base	*Base::generate(void)
{
	switch (rand() % 3)
	{
		case 0:
			std::cout << "Generate :: A" << std::endl;
			return new A;
			break;

		case 1:
			std::cout << "Generate :: B" << std::endl;
			return new B;
			break;

		default:
			std::cout << "Generate :: C" << std::endl;
			return new C;
			break;
	}
}
/*---------------------------------------*/
void	Base::identify(Base *p)
{
	if (p == NULL)
		std::cout << "Pointer is NULL" << std::endl;
	else if (dynamic_cast<A*>(p))
		std::cout << "Identifed as : A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Identifed as : B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Identifed as : C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}
/*---------------------------------------*/

void	Base::identify(Base &p)
{
	try {
		A &a = dynamic_cast<A&>(p);
		std::cout << "Identifed as : A" << std::endl;
		(void)a;
	}
	catch (std::exception &e) {
		try {
			B &b = dynamic_cast<B&>(p);
			std::cout << "Identifed as : B" << std::endl;
			(void)b;
		}
		catch (std::exception &ex) {
			try {
				C &c = dynamic_cast<C&>(p);
				std::cout << "Identifed as : C" << std::endl;
				(void)c;
			}
			catch (std::exception &exc) {
				std::cout << "Unknown type" << std::endl;
			}
		}
	}
}
