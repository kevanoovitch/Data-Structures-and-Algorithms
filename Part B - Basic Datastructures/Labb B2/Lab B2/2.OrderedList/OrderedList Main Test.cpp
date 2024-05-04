// 2.OrderedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "OrderedList.h"

//Implementera en sorterad Lista(OrderedList i OrderedList.hpp) 
//med länkade noder som inre datastruktur.Sorteringen vid insättning sker i växande ordning.

int main()
{
	try{
		OrderedList<int> MyList;
		
		//Codegrade test case

		MyList.add(30);
		MyList.add(20);
		MyList.add(10);


		while (!MyList.is_empty())
		{
			std::cout << MyList.last() << " | ";
			std::cout << MyList.removeLast() << std::endl;
		}

		MyList.add(10);
		std::cout << MyList.remove(88);
	}
		catch(const  std::runtime_error& e){
		std::cout << "Caught an exception: " << e.what()<< std::endl;
	}
}