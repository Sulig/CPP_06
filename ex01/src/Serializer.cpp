/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:46:14 by sadoming          #+#    #+#             */
/*   Updated: 2025/04/24 17:50:31 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/*	Conversion -> Used -> `Static_Cast`	*/

/* Constructor & destructor */
Serializer::Serializer()	{	std::cout << "Serializer default constructor called" << std::endl;	}
Serializer::Serializer(const Serializer &src) { (void)src; }
Serializer::~Serializer()	{	std::cout << "Serializer destructor called" << std::endl;			}
/* ----- */

/* Operator overloads */
Serializer &Serializer::operator=(const Serializer &src) { (void)src; return *this; }
/* ----- */

/* Functions */
////void	Serializer::doNotInstantiate() const { return ; }

/*---------------------------------------*/
uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}
/*---------------------------------------*/
/*---------------------------------------*/
Data*	Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
/*---------------------------------------*/
