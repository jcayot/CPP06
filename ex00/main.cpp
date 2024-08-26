//
// Created by jcayot on 8/21/24.
//

#include "ScalarConverter.hpp"

int	main() {
	ScalarConverter::convert("455545.5");
	ScalarConverter::convert("455rwetggdg545.5");
	ScalarConverter::convert("455545");
	ScalarConverter::convert("a");
	ScalarConverter::convert("NaN");
	ScalarConverter::convert("13.f");
	ScalarConverter::convert("-");
	ScalarConverter::convert("87887987987897878978");
}
