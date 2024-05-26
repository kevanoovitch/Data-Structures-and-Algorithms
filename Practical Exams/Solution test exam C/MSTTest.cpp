#include <vector>
#include <iostream>
#include <utility>
#include <string>
#include <fstream>
#include <map>
#include "Graph.hpp"


using namespace std;

int foundEdge(std::vector<std::tuple<string, string, int>> mst, const std::tuple<string, string, int>& edge, const std::tuple<string, string, int>& revEdge)
{
	int counter = 0;
	for (int i = 0; i < (int)mst.size(); i++)
		if (mst[i] == edge || mst[i] == revEdge)
			counter++;
	return counter;
}

int nrOfEdgesWithWeight(std::vector<std::tuple<string, string, int>> mst, int weight)
{
	int counter = 0;
	for (int i = 0; i < (int)mst.size(); i++)
		if (std::get<2>(mst[i]) == weight)
			counter++;
	return counter;
}

template <typename T>
void readFromFile(Graph<T>& graph, string filename)
{
	ifstream inFile;
	inFile.open(filename);
	if (inFile.is_open())
	{
		string typeOfGraph;
		int nrOfVert = 0;
		string vertice;
		inFile >> typeOfGraph;
		inFile >> nrOfVert; inFile.ignore();
		for (int i = 0; i < nrOfVert; i++)
		{
			getline(inFile, vertice);
			graph.addVertex(vertice);
		}
		string line;
		string vertOne;
		string vertTwo;
		int weight;
		getline(inFile, line);
		while (line != "#")
		{
			vertOne = line.substr(0, line.find_first_of(":"));
			line = line.substr(line.find_first_of(":") + 1);
			vertTwo = line.substr(0, line.find_first_of(":"));
			line = line.substr(line.find_first_of(":") + 1);
			weight = atoi(line.c_str());
			graph.addEdge(vertOne, vertTwo, weight);
			if (typeOfGraph == "U")
				graph.addEdge(vertTwo, vertOne, weight);
			getline(inFile, line);
		}
	}
	else
	{
		cout << "Not possible to open file " << filename << " for reading" << endl;
	}
}

bool testMST_KruskalsOnSmallGraph01()
{
	std::cout << "Testing MST on a small graph (Graph01) containing 4 verticies.... " << std::endl;
	Graph<string> graph;
	const int TOT_COST_MST = 7;
	int totCostMST = 0;
	readFromFile(graph, "Graph01.txt");
	std::vector<std::tuple<string, string, int>> mst;
	std::cout << "Checking amount of edges in MST ...." << std::endl;
	graph.kruskals(mst, totCostMST);
	if (mst.size() != 3)
	{
		std::cout << "Not correct amount of edges. Expected 3  but got " << mst.size() << std::endl;
		return false;
	}
	std::cout << "Checking total cost of MST ...." << std::endl;
	if (totCostMST != 7)
	{
		std::cout << "Not correct total cost. Expected " << TOT_COST_MST << " but got " << totCostMST << std::endl;
		return false;
	}

	std::vector<std::tuple<string, string, int>> allEdges;
	allEdges.push_back(std::make_tuple("A", "D", 2));
	allEdges.push_back(std::make_tuple("D", "A", 2));
	allEdges.push_back(std::make_tuple("B", "D", 2));
	allEdges.push_back(std::make_tuple("D", "B", 2));
	allEdges.push_back(std::make_tuple("D", "C", 3));
	allEdges.push_back(std::make_tuple("C", "D", 3));


	int counter = 0;
	counter = foundEdge(mst, allEdges[0], allEdges[1]);
	counter += foundEdge(mst, allEdges[2], allEdges[3]);
	counter += foundEdge(mst, allEdges[4], allEdges[5]);

	std::cout << "Checking edges in MST ...." << std::endl;
	if (counter != 3)
	{
		cout << "The MST did not contain all correct edges .... " << std::endl;
		return false;
	}

	std::vector<std::tuple<string, string, int>> wrongEdges;
	wrongEdges.push_back(std::make_tuple("A", "B", 3));
	wrongEdges.push_back(std::make_tuple("B", "A", 3));
	wrongEdges.push_back(std::make_tuple("A", "C", 4));
	wrongEdges.push_back(std::make_tuple("C", "A", 4));

	counter = 0;
	counter = foundEdge(mst, wrongEdges[0], wrongEdges[1]);
	counter += foundEdge(mst, wrongEdges[2], wrongEdges[3]);
	if (counter != 0)
	{
		cout << "The MST did contain wrong edges .... " << std::endl;
		return false;
	}
	std::cout << "Done testing MST on a small graph containing 4 verticies!" << std::endl;
	return true;
}

bool testMST_KruskalsOnBiggerGraph02()
{
	std::cout << "Testing MST on a graph (Graph02) containing 8 verticies.... " << std::endl;
	Graph<string> graph;
	const int TOT_COST_MST = 31;
	int totCostMST = 0;
	readFromFile(graph, "Graph02.txt");
	std::vector<std::tuple<string, string, int>> mst;

	graph.kruskals(mst, totCostMST);
	std::cout << "Checking amount of edges in MST ...." << std::endl;
	if (mst.size() != 7)
	{
		std::cout << "Graph 02: Not correct amount of edges. Expected 7 but got " << mst.size() << std::endl;
		return false;
	}
	std::cout << "Checking total cost of MST ...." << std::endl;
	if (totCostMST != TOT_COST_MST)
	{
		std::cout << "Graph 02: Not correct total cost. Expected " << TOT_COST_MST << " but got " << totCostMST << std::endl;
		return false;
	}

	vector<int> correctNrOfEdgeWithWeight{0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1};

	std::cout << "Checking weight of edges in MST ...." << std::endl;
	for (int i = 0; i < (int)correctNrOfEdgeWithWeight.size(); i++)
	{
		if (nrOfEdgesWithWeight(mst, i) != correctNrOfEdgeWithWeight[i])
		{
			std::cout << "Graph 02: Wrong amount of edges of weight " << i << ". Expected " << correctNrOfEdgeWithWeight[i] << " but got " << nrOfEdgesWithWeight(mst, i) << std::endl;
			return false;
		}
	}

	std::cout << "Done testing MST on graph containing 8 verticies!" << std::endl;
	return true;
}

bool testMST_KruskalsOnBiggerGraph03()
{
	std::cout << "Testing MST on a graph (Graph03) containing 9 verticies.... " << std::endl;
	Graph<string> graph;
	const int TOT_COST_MST = 37;
	int totCostMST = 0;
	readFromFile(graph, "Graph03.txt");
	std::vector<std::tuple<string, string, int>> mst;

	std::cout << "Checking amount of edges in MST ...." << std::endl;
	graph.kruskals(mst, totCostMST);
	if (mst.size() != 8)
	{
		std::cout << "Graph 03: Not correct amount of edges. Expected 8 but got " << mst.size() << std::endl;
		return false;
	}
	std::cout << "Checking total cost of MST ...." << std::endl;
	if (totCostMST != TOT_COST_MST)
	{
		std::cout << "Graph 03: Not correct total cost. Expected " << TOT_COST_MST << " but got " << totCostMST << std::endl;
		return false;
	}

	vector<int> correctNrOfEdgeWithWeight{0, 1, 2, 0, 2, 0, 0, 1, 1, 1};

	std::cout << "Checking weight of edges in MST ...." << std::endl;
	for (int i = 0; i < (int)correctNrOfEdgeWithWeight.size(); i++)
	{
		if (nrOfEdgesWithWeight(mst, i) != correctNrOfEdgeWithWeight[i])
		{
			std::cout << "Graph 03: Wrong amount of edges of weight " << i << ". Expected " << correctNrOfEdgeWithWeight[i] << " but got " << nrOfEdgesWithWeight(mst, i) << std::endl;
			return false;
		}
	}
	std::cout << "Done testing MST on graph containing 9 verticies!" << std::endl;
	return true;
}


bool testMST_PrimsOnSmallGraph01()
{
	std::cout << "Testing MST on a small graph (Graph01) containing 4 verticies.... " << std::endl;
	Graph<string> graph;
	const int TOT_COST_MST = 7;
	int totCostMST = 0;
	readFromFile(graph, "Graph01.txt");
	std::vector<std::tuple<string, string, int>> mst;
	std::cout << "Checking amount of edges in MST ...." << std::endl;
	graph.prims(mst, totCostMST);
	if (mst.size() != 3)
	{
		std::cout << "Not correct amount of edges. Expected 3  but got " << mst.size() << std::endl;
		return false;
	}
	std::cout << "Checking total cost of MST ...." << std::endl;
	if (totCostMST != 7)
	{
		std::cout << "Not correct total cost. Expected " << TOT_COST_MST << " but got " << totCostMST << std::endl;
		return false;
	}

	std::vector<std::tuple<string, string, int>> allEdges;
	allEdges.push_back(std::make_tuple("A", "D", 2));
	allEdges.push_back(std::make_tuple("D", "A", 2));
	allEdges.push_back(std::make_tuple("B", "D", 2));
	allEdges.push_back(std::make_tuple("D", "B", 2));
	allEdges.push_back(std::make_tuple("D", "C", 3));
	allEdges.push_back(std::make_tuple("C", "D", 3));


	int counter = 0;
	counter = foundEdge(mst, allEdges[0], allEdges[1]);
	counter += foundEdge(mst, allEdges[2], allEdges[3]);
	counter += foundEdge(mst, allEdges[4], allEdges[5]);

	std::cout << "Checking edges in MST ...." << std::endl;
	if (counter != 3)
	{
		cout << "The MST did not contain all correct edges .... " << std::endl;
		return false;
	}

	std::vector<std::tuple<string, string, int>> wrongEdges;
	wrongEdges.push_back(std::make_tuple("A", "B", 3));
	wrongEdges.push_back(std::make_tuple("B", "A", 3));
	wrongEdges.push_back(std::make_tuple("A", "C", 4));
	wrongEdges.push_back(std::make_tuple("C", "A", 4));

	counter = 0;
	counter = foundEdge(mst, wrongEdges[0], wrongEdges[1]);
	counter += foundEdge(mst, wrongEdges[2], wrongEdges[3]);
	if (counter != 0)
	{
		cout << "The MST did contain wrong edges .... " << std::endl;
		return false;
	}
	std::cout << "Done testing MST on a small graph containing 4 verticies!" << std::endl;
	return true;
}

bool testMST_PrimsOnBiggerGraph02()
{
	std::cout << "Testing MST on a graph (Graph02) containing 8 verticies.... " << std::endl;
	Graph<string> graph;
	const int TOT_COST_MST = 31;
	int totCostMST = 0;
	readFromFile(graph, "Graph02.txt");
	std::vector<std::tuple<string, string, int>> mst;

	graph.prims(mst, totCostMST);
	std::cout << "Checking amount of edges in MST ...." << std::endl;
	if (mst.size() != 7)
	{
		std::cout << "Graph 03: Not correct amount of edges. Expected 7 but got " << mst.size() << std::endl;
		return false;
	}
	std::cout << "Checking total cost of MST ...." << std::endl;
	if (totCostMST != TOT_COST_MST)
	{
		std::cout << "Graph 03: Not correct total cost. Expected " << TOT_COST_MST << " but got " << totCostMST << std::endl;
		return false;
	}

	vector<int> correctNrOfEdgeWithWeight{0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1};

	std::cout << "Checking weight of edges in MST ...." << std::endl;
	for (int i = 0; i < (int)correctNrOfEdgeWithWeight.size(); i++)
	{
		if (nrOfEdgesWithWeight(mst, i) != correctNrOfEdgeWithWeight[i])
		{
			std::cout << "Graph 02: Wrong amount of edges of weight " << i << ". Expected " << correctNrOfEdgeWithWeight[i] << " but got " << nrOfEdgesWithWeight(mst, i) << std::endl;
			return false;
		}
	}

	std::cout << "Done testing MST on graph containing 8 verticies!" << std::endl;
	return true;
}

bool testMST_PrimsOnBiggerGraph03()
{
	std::cout << "Testing MST on a graph (Graph03) containing 9 verticies.... " << std::endl;
	Graph<string> graph;
	const int TOT_COST_MST = 37;
	int totCostMST = 0;
	readFromFile(graph, "Graph03.txt");
	std::vector<std::tuple<string, string, int>> mst;

	std::cout << "Checking amount of edges in MST ...." << std::endl;
	graph.prims(mst, totCostMST);
	if (mst.size() != 8)
	{
		std::cout << "Graph 02: Not correct amount of edges. Expected 8 but got " << mst.size() << std::endl;
		return false;
	}
	std::cout << "Checking total cost of MST ...." << std::endl;
	if (totCostMST != TOT_COST_MST)
	{
		std::cout << "Graph 02: Not correct total cost. Expected " << TOT_COST_MST << " but got " << totCostMST << std::endl;
		return false;
	}

	vector<int> correctNrOfEdgeWithWeight{0, 1, 2, 0, 2, 0, 0, 1, 1, 1};

	std::cout << "Checking weight of edges in MST ...." << std::endl;
	for (int i = 0; i < (int)correctNrOfEdgeWithWeight.size(); i++)
	{
		if (nrOfEdgesWithWeight(mst, i) != correctNrOfEdgeWithWeight[i])
		{
			std::cout << "Graph 02: Wrong amount of edges of weight " << i << ". Expected " << correctNrOfEdgeWithWeight[i] << " but got " << nrOfEdgesWithWeight(mst, i) << std::endl;
			return false;
		}
	}
	std::cout << "Done testing MST on graph containing 9 verticies!" << std::endl;
	return true;
}


int main()
{
	if (!testMST_KruskalsOnSmallGraph01())
	{
		std::cout << "Testing Kruskals algoritm on a small graph did not give the correct result ...." << std::endl;
		return -1;
	}
	std::cout << std::endl;
	if (!testMST_KruskalsOnBiggerGraph02())
	{
		std::cout << "Testing Kruskals algoritm on a bigger graph (Graph02) did not give the correct result ...." << std::endl;
		return -2;
	}
	std::cout << std::endl;
	if (!testMST_KruskalsOnBiggerGraph03())
	{
		std::cout << "Testing Kruskals algoritm on a bigger graph (Graph03) did not give the correct result ...." << std::endl;
		return -3;
	}

	if (!testMST_PrimsOnSmallGraph01())
	{
		std::cout << "Testing Prims algoritm on a small graph did not give the correct result ...." << std::endl;
		return -4;
	}
	std::cout << std::endl;
	if (!testMST_PrimsOnBiggerGraph02())
	{
		std::cout << "Testing Prims algoritm on a bigger graph (Graph02) did not give the correct result ...." << std::endl;
		return -5;
	}
	std::cout << std::endl;
	if (!testMST_PrimsOnBiggerGraph03())
	{
		std::cout << "Testing Prims algoritm on a bigger graph (Graph03) did not give the correct result ...." << std::endl;
		return -6;
	}
	std::cout<<std::endl;
	std::cout << "All tests passed ...." << std::endl;

	return 0;
}
