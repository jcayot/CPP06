//
// Created by jules on 26/08/2024.
//

#include <iostream>
#include "Serializer.hpp"

int	main() {
	Data* data = new Data();
	std::cout << data << std::endl;
	uintptr_t serialized = Serializer::serialize(data);
	Data* deserialized = Serializer::deserialize(serialized);
	std::cout << deserialized << std::endl;
	delete data;
}