// 2. QueueLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "QueueLinkedList.h"

int main()
{
	try
	{
		Queue<int> myQueue;

		//std::cout << myQueue.peek() << " | Expected exception" << std::endl;

		myQueue.enqueue(1);
		myQueue.enqueue(2);

		std::cout << myQueue.peek() << " | Expected 1" << std::endl;

		std::cout << myQueue.dequeue() << " | Expected 1" << std::endl;

		std::cout << myQueue.peek() << " | Expected 2" << std::endl;

	}
	catch (const std::runtime_error& e)
	{
		std::cout << "eception caught: " << e.what() << std::endl;
	}

	return 0;
}

//Implementera en Kö - klass(QueueLinkedList i QueueLinkedList.h) med en länkad lista som inre datastruktur.
//Du ska definiera en klass som ska användas för att representera listans element.
//Operationerna enqueue(), dequeue(), peek(), och is_empty() skall finnas.