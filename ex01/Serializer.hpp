//
// Created by jules on 25/08/2024.
//

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <cstdint>
#include <string>

typedef struct Data {
	std::string	name;
}	Data;

class Serializer {
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
	private:
		Serializer();
		Serializer(const Serializer&);
		~Serializer();
		Serializer& operator=(const Serializer&);
};

#endif
