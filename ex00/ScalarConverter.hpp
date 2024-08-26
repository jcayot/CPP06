//
// Created by jcayot on 8/20/24.
//

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <stdexcept>
# include <cmath>
# include <iomanip>
# include <iostream>
# include <climits>
# include <cfloat>

class ScalarConverter {
	public:
		static void	convert(const std::string& string);

	private:
		ScalarConverter();

		static int		getInteger(const std::string& string);
		static float	getFloat(const std::string& string, int& precision);
		static double	getDouble(const std::string& string, int& precision);
		static char		getChar(const std::string& string);

		static void		displayInteger(const int& value);
		static void		displayFloat(const float& value, int& precision);
		static void		displayDouble(const double& value, int& precision);
		static void		displayChar(const char& value);


		static int		intLength(int number);
		static int		strLength(const std::string& string);
};

#endif
