/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:26:17 by sadoming          #+#    #+#             */
/*   Updated: 2025/04/24 20:03:34 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data		data;
	uintptr_t	serialized;

	data.i = 42;
	data.f = 42.42f;
	data.d = 42.4242;
	data.c = 'a';
	data.s = "Hello World";
	std::cout << "Data before serialization:" << std::endl;
	std::cout << "i: " << data.i << std::endl;
	std::cout << "f: " << data.f << std::endl;
	std::cout << "d: " << data.d << std::endl;
	std::cout << "c: " << data.c << std::endl;
	std::cout << "s: " << data.s << std::endl;
	std::cout << "ptr of data: " << &data << std::endl;
	//-----
	serialized = Serializer::serialize(&data);
	std::cout << "Serialized data: " << serialized << std::endl;
	//-----
	Data	*deserialized = Serializer::deserialize(serialized);
	std::cout << "Data after deserialization:" << std::endl;
	std::cout << "i: " << deserialized->i << std::endl;
	std::cout << "f: " << deserialized->f << std::endl;
	std::cout << "d: " << deserialized->d << std::endl;
	std::cout << "c: " << deserialized->c << std::endl;
	std::cout << "s: " << deserialized->s << std::endl;
	std::cout << "ptr of data: " << deserialized << " |deserialized" << std::endl;
	std::cout << "ptr of data: " << &data  << " |original" << std::endl;
	std::cout << "ptr of deserialized: " << &deserialized << std::endl;
	//-----
	return (0);
}
