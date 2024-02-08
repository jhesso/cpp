/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:52:51 by jhesso            #+#    #+#             */
/*   Updated: 2024/02/08 20:22:40 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Data.hpp"

int	main(void)
{
	Data	data = {.val = 42, .string = "Hive Helsinki"};
	uintptr_t	serializedPtr = Serializer::serialize(&data);
	Data *	deserializedPtr = Serializer::deserialize(serializedPtr);

	if (deserializedPtr == &data)
		std::cout << "Successfully serialized and then deserialized!" << std::endl;
	else
		std::cout << "Serialization or deserialization failed" << std::endl;
	std::cout << "Original " << data << std::endl;
	std::cout << "Serialization result: " << serializedPtr << std::endl;
	std::cout << "Deserialization result: " << *deserializedPtr << std::endl;

	return 0;
}
