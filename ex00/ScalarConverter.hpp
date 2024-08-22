//
// Created by jcayot on 8/20/24.
//

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <stdexcept>
# include <iostream>

class ScalarConverter {
	public:
		static void	convert(const std::string& string);

	private:

		enum	Type {
			CHAR = 1,
			INT = 2,
			FLOAT = 3,
			DOUBLE  = 4,
			ERROR = 5
		};

		ScalarConverter();

		static int		getInteger(const std::string& string);
		static float	getFloat(const std::string& string);

		static int		intLength(int number);
};

#endif //SCALARCONVERTER_HPP
