// Lab B2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "IndexedList.h"



int main()
{
	try
	{
		IndexedList<int> MyList;

		//MyList.addAt(0,6);
		//MyList.addAt(1, 7);
		//MyList.addAt(2, 8);
		// 
		//std::cout << MyList.size() << " expected 3" << std::endl;

		//std::cout << MyList.getAt(1) << " expected 7" << std::endl;

		////---- whole seq print 1 ----
		//for (int i = 0; i < MyList.size(); i++)
		//{
		//	std::cout << MyList.getAt(i) << ", ";
		//}

		//std::cout << "\n"; 
		//std::cout << "Expected: 6,7,8" << std::endl;
		//// --------

		////test remove first
		//std::cout << MyList.removeFirst() << " expected 6" << std::endl;


		////whole seq print 2
		//for (int i = 0; i < MyList.size(); i++)
		//{
		//	std::cout << MyList.getAt(i) << ", ";
		//}

		//std::cout << "\n";
		//std::cout << "Expected: 7,8" << std::endl;

		//// --------

		//std::cout << MyList.removeAt(1) << " expected 8" << std::endl;

		//std::cout << MyList.removeLast() << " expected 6" << std::endl;

		//std::cout << MyList.size() << " expected 0 LIST IS NOW EMPTY!" << std::endl;


		for (int i = 0; i < 10; i++)
		{
			MyList.addAt(i, i);
		}
		

		std::cout << MyList.size() << " expected 10" << std::endl;

		
		//Calling removeAt() for index 9, 5, 2, 0
		MyList.removeAt(9);
		MyList.removeAt(5);
		MyList.removeAt(2);
		MyList.removeAt(0);

		

		std::cout << MyList.size() << " expected 6" << std::endl;

		//Calling addAt() with (index,value) for (0,0, (2,2), (5,5), (9,9)
		MyList.addAt(0, 0);
		MyList.addAt(2, 2);
		MyList.addAt(5, 5);
		MyList.addAt(9, 9);

		
		std::cout << MyList.size() << " expected 10" << std::endl;

		for (int i = 0; i < 10; i++)
		{
			std::cout<< MyList.getAt(i) << ", ";
		}
		std::cout << "\n";

		//Calling removeAt(0) until IndexedList is empty using is_empty() .... 
		while (!MyList.is_empty())
		{
			MyList.removeAt(0);
			/*std::cout << "popped data:" << MyList.removeAt(0) << std::endl;
			std::cout << "size atm:" << MyList.size() << std::endl;*/



			
		}
		std::cout << MyList.size() << " expected 0 LIST IS NOW EMPTY!" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "ERROR: " << e.what();
	}

   
}

