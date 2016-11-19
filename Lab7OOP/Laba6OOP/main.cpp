#include "Vector.h"
#include "Captain.h"
#include <iostream>
#include <time.h>

int main()
{
	const int number = 5;
	Vector<int, Captain, number> one;
	Vector<int, Captain, number> two;
	Vector<int, Captain, number> three;
	Vector<float, Captain> four;
	for (int i = 0; i < number; i++)
	{
		one.AddElement((rand() % 20) - 8);
		two.AddElement((rand() % 40) - 18);
	}
	four.AddElement(1.23f);
	four.AddElement(2.2f);
	four.AddElement(-2.2f);
	three = one + two;
	one.Show();
	two.Show();
	three.Show();
	std::cout << std::endl << four(1) << std::endl;
	two = one;
	two.Show();
	if (one > two)
		std::cout << std::endl << "one > two" << std::endl;
	else if (one == two)
		std::cout << std::endl << "one == two" << std::endl;
	else
		std::cout << std::endl << "one <  two" << std::endl;
	std::cout << std::endl << "Minimum: " << one.Min() << std::endl;
	one.setNameCaptain("Oleg");
	std::cout << std::endl << "Captain name: " << one.getNameCaptain() << std::endl;
	system("pause");
	return 0;
}