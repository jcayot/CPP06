//
// Created by jcayot on 8/26/24.
//

#ifndef UTILS_HPP
# define UTILS_HPP

#include <ctime>
#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

class Utils {
	public:
		static Base*	generate(void);
		static void		identify(Base* base);
		static void		identify(Base& base);

	private:
		Utils() {}
};



#endif //UTILS_HPP
