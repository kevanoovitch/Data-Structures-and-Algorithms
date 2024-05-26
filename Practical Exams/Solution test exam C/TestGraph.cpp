#include <vector>
#include <iostream>
#include <utility>
#include <string>
#include <fstream>
#include <map>
#include "Graph.hpp"


using namespace std;

bool testGraphBasics()
{
	Graph<std::string> strGraph;

	strGraph.addVertex("V1");
	strGraph.addVertex("V2");
	strGraph.addVertex("V3");
	strGraph.addVertex("V4");

	if (strGraph.getNrOfVerticies() != 4)
	{
		std::cout << "Wrong amount of verticies. Expected 4 but got " << strGraph.getNrOfVerticies() << std::endl;
		return false;
	}

	strGraph.addEdge("V1", "V2", 3);
	strGraph.addEdge("V1", "V3", 5);
	strGraph.addEdge("V3", "V2", 3);
	strGraph.addEdge("V1", "V4", 1);
	strGraph.addEdge("V4", "V2", 3);

	
	if (strGraph.getNrOfEdges() != 5)
	{
		std::cout << "Wrong amount of edges. Expected 5 but got " << strGraph.getNrOfEdges() << std::endl;
		return false;
	}

	std::vector<std::string> neighbours = strGraph.getAllNeighboursTo("V2");
	if (neighbours.size() != 0)
	{
		std::cout << "Wrong amount of neighbours for vertex V2. Expected 0 but got " << neighbours.size() << std::endl;
		return false;
	}

	neighbours = strGraph.getAllNeighboursTo("V3");
	if (neighbours.size() != 1)
	{
		std::cout << "Wrong amount of neighbours for vertex V3. Expected 1 but got " << neighbours.size() << std::endl;
		return false;
	}


	std::string allNeigboursAsString;
	for (int i = 0; i < neighbours.size(); i++)
	{
		allNeigboursAsString += " " + neighbours[i];
	}

	if (allNeigboursAsString.find("V2") == std::string::npos)
	{
		std::cout << "Neigbours missing for vertex V3. Expected V2 but got " << allNeigboursAsString << std::endl;
		return false;
	}

	neighbours = strGraph.getAllNeighboursTo("V1");
	if (neighbours.size() != 3)
	{
		std::cout << "Wrong amount of neighbours for vertex V1. Expected 3 but got " << neighbours.size() << std::endl;
		return false;
	}

	allNeigboursAsString = "";
	for (int i = 0; i < neighbours.size(); i++)
	{
		allNeigboursAsString += " " + neighbours[i];
	}

	if (allNeigboursAsString.find("V2") == std::string::npos ||
		allNeigboursAsString.find("V3") == std::string::npos ||
		allNeigboursAsString.find("V4") == std::string::npos)
	{
		std::cout << "Neigbours missing for vertex V1. Expected V2, V3 and V4 but got "<<allNeigboursAsString << std::endl;
	}

	return true;
}

int main()
{
	if (!testGraphBasics())
	{
		std::cout << "Not ok testing basics " << std::endl;
		return -1;
	}
	std::cout << "All tests passed" << std::endl;

	return 0;
}