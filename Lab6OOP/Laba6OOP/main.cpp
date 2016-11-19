#include "Vector.h"
#include <iostream>

int main()
{
	Vector one(2, 1, 5, 6); 
	Vector two(4, 6, 5, 7);
	Vector three;
	three = one + two;
	one.Show();
	two.Show();
	three.Show();
	one(3, 2, 6, 7).Show();
	two = one;
	two.Show();
	if (one > two)
		std::cout << "one > two" << std::endl;
	else if (one == two)
		std::cout << "one == two" << std::endl;
	else
	std::cout << "one <  two" << std::endl;
	system("pause");
	return 0;
}