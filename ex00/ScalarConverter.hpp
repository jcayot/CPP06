//
// Created by jcayot on 8/20/24.
//

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <stdexcept>
# include <math.h>
# include <iomanip>
# include <iostream>

class ScalarConverter {
	public:
		static void	convert(const std::string& string);

	private:
		ScalarConverter();

		static int		getInteger(const std::string& string);
		static float	getFloat(const std::string& string);
		static double	getDouble(const std::string& string);
		static char		getChar(const std::string& string);

		static void		displayInteger(const int& value);
		static void		displayFloat(const float& value);
		static void		displayDouble(const double& value);
		static void		displayChar(const char& value);


		static int		intLength(int number);
		static int		strLength(const std::string& string);
};

#endif
