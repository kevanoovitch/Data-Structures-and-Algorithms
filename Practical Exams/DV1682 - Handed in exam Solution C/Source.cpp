#include <algorithm>
#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <string>
#include <map>
#include "DisjointSets.hpp"
#include "Graph.hpp"

std::string getVector(std::vector<std::string> vec)
{
	std::string ret = "";
	if (vec.size() > 0)
	{
		ret += vec[0];
		for (int i = 1; i < vec.size(); ++i)
			ret += "," + vec[i];
	}

	return ret;
}


int main()
{
	try
	{

		std::cout << "Starting tests for DisjointSet" << std::endl << std::endl;
		DisjointSets<std::string> ds;

		std::cout << "Using makeSet() to create sets [A, B, ..., I, J]" << std::endl;
		std::vector<std::string> names = { "A","B","C","D","E","F","G","H","I", "J" };
		for (int i = 0; i < names.size(); ++i)
			ds.makeSet(names[i]);

		std::cout << "Using findSet() to verify their existance ... " << std::flush;
		std::vector<std::string> results;
		for (int i = 0; i < names.size(); ++i)
			results.push_back(ds.findSet(names[i]));
		if (names != results)
		{
			std::cout << "The created sets are incorrect." << std::endl;
			std::cout << "Should be: " << getVector(names) << std::endl;
			std::cout << "Yours are: " << getVector(results) << std::endl;
			return false;
		}
		std::cout << "OK!" << std::endl;

		std::cout << "Using unionSet('A', 'B') ... " << std::flush;
		ds.unionSet("A", "B");
		results = std::vector<std::string>();
		for (int i = 0; i < names.size(); ++i)
			results.push_back(ds.findSet(names[i]));


		return 0;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}



}