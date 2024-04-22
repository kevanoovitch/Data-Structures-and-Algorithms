// 3. QueueCircularArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "QueueCircularArray.hpp"
int main()
{
	try
	{
		Queue<int> myQueueCircular;

		//std::cout << myQueue.peek() << " | Expected exception" << std::endl;

		myQueueCircular.enqueue(10);
		myQueueCircular.enqueue(20);
		myQueueCircular.enqueue(30);

		std::cout << myQueueCircular.peek() << " | Expected 10" << std::endl;

		std::cout << myQueueCircular.dequeue() << " | Expected 10" << std::endl;

		std::cout << myQueueCircular.peek() << " | Expected 20" << std::endl;

	}
	catch (const std::runtime_error& e)
	{
		std::cout << "eception caught: " << e.what() << std::endl;
	}

    
}

//
//Implementera en Kö - klass(QueueCircularArray i QueueCircularArray.h) med en lista / array som inre datastruktur.
//Operationerna enqueue(), dequeue(), peek(), och is_empty() skall finnas.
//Arrayen måste användas cirkulärt.
