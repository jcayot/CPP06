//
// Created by jcayot on 8/26/24.
//

#include "Utils.hpp"

Base* Utils::generate() {
	static bool randomInit = false;

	if (!randomInit) {
		srand(time(nullptr));
		randomInit = true;
	}

	int	randomNumber = rand();

	if (randomNumber % 3 == 0)
		return new A();
	if (randomNumber % 3 == 1)
		return new B();
	return new C();
}

void Utils::identify(Base* base) {
	if (dynamic_cast<A*>(base))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(base))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(base))
		std::cout << "C" << std::endl;
}

void Utils::identify(Base& base) {
    try {
        A& a = dynamic_cast<A&>(base);
    	(void) a;
        std::cout << "A" << std::endl;
        return ;
    } catch (const std::bad_cast&) {}
    try {
        B& b = dynamic_cast<B&>(base);
    	(void) b;
        std::cout << "B" << std::endl;
        return ;
    } catch (const std::bad_cast&) {}
    try {
        C& c = dynamic_cast<C&>(base);
    	(void) c;
        std::cout << "C" << std::endl;
        return ;
    } catch (const std::bad_cast&) {}
}
