//
// Created by jcayot on 8/20/24.
//

#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& string) {
	try {
		char charString = getChar(string);
		displayChar(charString);
		return;
	} catch (const std::invalid_argument& e) {

	}
	try {
		int intString = getInteger(string);
		displayInteger(intString);
		return;
	} catch (const std::invalid_argument& e) {

	}
	try {
		float floatString = getFloat(string);
		displayFloat(floatString);
		return;
	} catch (const std::invalid_argument& e) {

	}
	try {
		double doubleString = getDouble(string);
		displayDouble(doubleString);
		return;
	} catch (const std::invalid_argument& e) {

	}
}

int ScalarConverter::getInteger(const std::string& string) {
	int	num = std::stoi(string);
	int numLength = intLength(num);

	if (numLength != strLength(string))
		throw std::invalid_argument("Invalid argument");
	return (num);
}

float ScalarConverter::getFloat(const std::string& string) {
	float	num = std::stof(string);
	int		dotNum = 0;

	if (isinff(num))
		return (num);
	if (string[0] < '0' || string[0] > '9')
		throw std::invalid_argument("Invalid argument");

	for (int i = 1; i < strLength(string) - 1; i++) {
		if (string[i] == '.')
			dotNum++;
		else if (string[i] < '0' || string[i] > '9')
			throw std::invalid_argument("Invalid argument");
	}

	if (string[string.length() - 1] != 'f' || dotNum > 1)
		throw std::invalid_argument("Invalid argument");

	return (num);
}

double ScalarConverter::getDouble(const std::string& string) {
	double	num = std::stod(string);
	int		dotNum = 0;

	if (isinf(num) || isnan(num))
		return (num);
	if (string[0] < '0' || string[0] > '9')
		throw std::invalid_argument("Invalid argument");

	for (int i = 1; i < strLength(string); i++) {
		if (string[i] == '.')
			dotNum++;
		else if (string[i] < '0' || string[i] > '9')
			throw std::invalid_argument("Invalid argument");
	}
	return (num);
}

char ScalarConverter::getChar(const std::string& string) {
	if (strLength(string) > 1)
		throw std::invalid_argument("Invalid argument");
	return (string[0]);
}

void ScalarConverter::displayInteger(const int& value) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << value << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
}

void ScalarConverter::displayFloat(const float& value) {
	std::cout << "char: impossible" << std::endl;
	if (isinff(value))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	std::cout << "float: " << std::fixed << value << "f" << std::endl;
	std::cout << "double: " << std::fixed << static_cast<double>(value) << std::endl;
}

void ScalarConverter::displayDouble(const double& value) {
	std::cout << "char: impossible" << std::endl;
	if (isinf(value) || isnan(value))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	std::cout << "float: " << std::fixed << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << std::fixed << value << std::endl;
}

void ScalarConverter::displayChar(const char& value) {
	if (value < 32 || value > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << value << std::endl;
	std::cout << "int: " << static_cast<int>(value) << std::endl;
	std::cout << "float: " << std::fixed << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << std::fixed << static_cast<double>(value) << std::endl;
}

int ScalarConverter::intLength(int number) {
	int length = 1;

	if (number < 0)
		length++;
	while (number > 9 || number < -9) {
		number /= 10;
		length++;
	}
	return (length);
}

int ScalarConverter::strLength(const std::string& string) {
	int	length = 0;

	while (string[length] != 0)
		length++;
	return (length);
}
