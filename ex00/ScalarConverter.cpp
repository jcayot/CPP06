//
// Created by jcayot on 8/20/24.
//

#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& string) {
	if (strEqual(string, "nan") || strEqual(string, "-inf") || strEqual(string, "+inf")) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "integer: impossible" << std::endl;
		std::cout << "float: " << string << "f" << std::endl;
		std::cout << "double: " << string << std::endl;
		return ;
	}
	if (strEqual(string, "-inff") || strEqual(string, "+inff")) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "integer: impossible" << std::endl;
		std::cout << "float: " << string << std::endl;
		std::cout << "double: " << string[0] << "inf" << std::endl;
	}
	try {
		char	charString = getChar(string);

		displayChar(charString);

		return;
	} catch (const std::exception&) {}
	try {
		int	intString = getInteger(string);

		displayInteger(intString);

		return;
	} catch (const std::exception&) {}
	try {
		int		precision = 0;
		float	floatString = getFloat(string, precision);

		displayFloat(floatString, precision);

		return;
	} catch (const std::exception&) {}
	try {
		int		precision = 0;
		double	doubleString = getDouble(string, precision);

		displayDouble(doubleString, precision);

		return;
	} catch (const std::exception&) {}
	std::cout << "char: impossible" << std::endl;
	std::cout << "integer: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

int ScalarConverter::getInteger(const std::string& string) {
	int	num = std::stoi(string);
	int numLength = intLength(num);

	if (numLength != strLength(string))
		throw std::invalid_argument("Invalid argument");
	return (num);
}

float ScalarConverter::getFloat(const std::string& string, int& precision) {
	float	num = std::stof(string);
	int		dotNum = 0;

	if (string[0] < '0' || string[0] > '9')
		throw std::invalid_argument("Invalid argument");

	for (int i = 1; i < strLength(string) - 1; i++) {
		if (string[i] == '.') {
			dotNum++;
			continue ;
		}
		if (dotNum == 1)
			precision++;
		if (string[i] < '0' || string[i] > '9')
			throw std::invalid_argument("Invalid argument");
	}

	if (string[strLength(string) - 1] != 'f' || dotNum != 1)
		throw std::invalid_argument("Invalid argument");

	return (num);
}

double ScalarConverter::getDouble(const std::string& string, int& precision) {
	double	num = std::stod(string);
	int		dotNum = 0;

	if (string[0] < '0' || string[0] > '9')
		throw std::invalid_argument("Invalid argument");

	for (int i = 1; i < strLength(string); i++) {
		if (string[i] == '.') {
			dotNum++;
			continue ;
		}
		if (dotNum == 1)
			precision++;
		if (string[i] < '0' || string[i] > '9')
			throw std::invalid_argument("Invalid argument");
	}
	if (dotNum != 1)
		throw std::invalid_argument("Invalid argument");
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

void ScalarConverter::displayFloat(const float& value, int& precision) {
	if (precision == 0)
		precision++;
	std::cout << "char: impossible" << std::endl;

	if (isinff(value))
		std::cout << "int: impossible" << std::endl;
	else if (value > static_cast<float>(INT_MAX) || value < static_cast<float>(INT_MIN))
		std::cout << "int: overflow" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;

	std::cout << "float: " << std::fixed << std::setprecision(precision) << value << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(precision) << static_cast<double>(value) << std::endl;
}

void ScalarConverter::displayDouble(const double& value, int& precision) {
	if (precision == 0)
		precision++;
	std::cout << "char: impossible" << std::endl;

	if (isinfl(value) != 0 || isnanl(value))
		std::cout << "int: impossible" << std::endl;
	else if (value > static_cast<double>(INT_MAX) || value < static_cast<double>(INT_MIN))
		std::cout << "int: overflow" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;

	if (value > static_cast<double>(FLT_MAX) || value < static_cast<double>(FLT_MIN))
		std::cout << "float: overflow" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(precision) << static_cast<float>(value) << "f" << std::endl;

	std::cout << "double: " << std::fixed << std::setprecision(precision) << value << std::endl;
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

bool ScalarConverter::strEqual(const std::string& string1, const std::string& string2) {
	int	i = 0;

	while (string1[i] && string2[i] && string1[i] == string2[i])
		i++;
	return (string1[i] == string2[i]);
}
