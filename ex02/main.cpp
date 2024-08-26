//
// Created by jcayot on 8/26/24.
//

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Utils.hpp"

int	main() {
	A a = A();
	B b = B();
	C c = C();
	for (int i = 0; i < 10; i++) {
		Base* base = Utils::generate();
		Utils::identify(base);
		delete base;
	}
	Utils::identify(a);
	Utils::identify(b);
	Utils::identify(c);
}
