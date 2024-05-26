#include <iostream>
#include "OrderedList.hpp"

int main()
{
	OrderedList<int> Mylist;

	/*Mylist.add(1);
	Mylist.add(2);
	Mylist.add(4);
	Mylist.add(5);
	Mylist.add(7);
	Mylist.add(8);*/


	for (int i = 0; i < 10; i++)
	{
		Mylist.add(i);
	}


	for (int i = 0; i < Mylist.size(); i++)
	{
		std::cout << Mylist.getAt(i) << ", ";
	}

	
	std::cout << Mylist.removeAt(0) << std::endl;
	std::cout << Mylist.removeAt(2) << std::endl;
	std::cout << Mylist.removeAt(5) << std::endl;
	std::cout << Mylist.removeAt(9) << std::endl;

	std::cout << std::endl;
	for (int i = 0; i < Mylist.size(); i++)
	{
		std::cout << Mylist.getAt(i) << ", ";
	}

	std::cout << std::endl;

	while (Mylist.is_empty() != true)
	{
		std::cout << Mylist.removeLast() << ", ";
	}

	return 0;
}