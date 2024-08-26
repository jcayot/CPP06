//
// Created by jules on 25/08/2024.
//

#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr) {
	uintptr_t serialized = reinterpret_cast<uintptr_t>(ptr);
	return (serialized);
}

Data* Serializer::deserialize(uintptr_t raw) {
	Data* ptr = reinterpret_cast<Data*>(raw);
	return (ptr);
}
