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
		int first = 1;
		int second = 3;
		int thid = 2;
		MyList.add(first);
		std::cout << "shows last element should be " << first << " <--> " << MyList.last() << std::endl;
		MyList.add(second);
		MyList.add(second);
		MyList.remove(second);
	}
		catch(const  std::runtime_error& e){
		std::cout << "Caught an exception: " << e.what()<< std::endl;
	}
}