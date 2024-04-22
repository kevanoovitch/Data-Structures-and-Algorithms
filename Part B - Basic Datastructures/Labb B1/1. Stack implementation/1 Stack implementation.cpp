
#include <iostream>
#include "StackArray.h"

int main()
{

	Stack<std::string> LetterStack(1);

	
	LetterStack.push("A");
	
	LetterStack.push("B");
	//should expand it
	LetterStack.push("C");

	std::cout << LetterStack.peek() << " Expected C" << std::endl;

	std::cout << LetterStack.is_empty() << " Expected False" << std::endl;

	for (int i = 0; i < 3; i++)
	{
		std::cout << LetterStack.pop() << std::endl;
	}

	std::cout << LetterStack.is_empty() << " Expected True" << std::endl;
	


	return 0;
}

