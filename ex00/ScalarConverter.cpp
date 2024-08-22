//
// Created by jcayot on 8/20/24.
//

#include "ScalarConverter.hpp"

int ScalarConverter::getInteger(const std::string& string) throw (std::invalid_argument) {
	int	num = std::stoi(string);
	int numLength = intLength(num);
	if (numLength != string.length())
		throw std::invalid_argument("Invalid argument");
	return (num);
}

float ScalarConverter::getFloat(const std::string& string) throw (std::invalid_argument) {
	float	num = std::stof(string);
	int	dotNum;
	int	fNum;
	for (int i = 0; i < string.length(); i++) {

	}
}

