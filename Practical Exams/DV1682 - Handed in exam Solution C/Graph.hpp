#ifndef GRAPH_H
#define GRAPH_H
#include <utility>
#include <vector>
#include <climits>
#include <tuple>
#include <stdexcept>
#include <map>

#include "DisjointSets.hpp"
#include "MinPriorityQueue.hpp"
#include "Quicksort.hpp"

const int INFINIT_COST = INT_MAX;

template <typename T>
class Edge
{
public:
	int cost;
	T next;
	T origin;
	Edge(): origin(T()),next(T()),cost(0) {}
	Edge(T origin, T next, int cost): origin(origin), next(next), cost(cost) {}

	//operator overloading used in quicksort in order to use cost to compare
	bool operator==(const Edge& other)
	{
		if (cost == other.cost)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator<(const Edge& other)
	{
		if (cost < other.cost)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator>(const Edge& other)
	{
		if (cost > other.cost)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

template <typename T>
class Graph
{
private:
	// for you to decide
	std::map<T, std::vector<Edge<T>>> adjList;
	
public:
	Graph();
	virtual ~Graph();
	Graph(const Graph& other) = delete;
	Graph& operator=(const Graph& other) = delete;
	void addVertex(T vertex);
	void addEdge(T from, T to, int weight = 0);
	std::vector<T> getAllNeighboursTo(T vertex);
	int getNrOfVertices() const;
	int getNrOfEdges() const;
	void MST(std::vector<std::tuple<T, T, int>>& mst, int &totalCost);
};


#endif

template<typename T>
inline Graph<T>::Graph()
{
}

template<typename T>
inline Graph<T>::~Graph()
{
}

template<typename T>
inline void Graph<T>::addVertex(T vertex)
{
	// Adds a vertex
		//will refrence the key "vertex" if there are no key called "vertex" it will create it
	this->adjList[vertex];
}

template<typename T>
inline void Graph<T>::addEdge(T from, T to, int weight)
{
	// Adds an edge

	std::vector<Edge<T>>& Temp = this->adjList[from];
	Temp.push_back(Edge<T>(from, to, weight));
}

template<typename T>
inline std::vector<T> Graph<T>::getAllNeighboursTo(T vertex)
{
	// Returns all neighbors to vertex in alphabetical order 

	//thow exception on empty!
	if (this->adjList.size() == 0)
	{
		throw std::runtime_error{ "Exception getAllNeighboursTo() called on empty stucture" };
	}

	std::vector<T> neighbors;

	for (int i = 0; i < this->adjList[vertex].size(); i++)
	{
		neighbors.push_back(this->adjList[vertex][i].next);
	}

	return neighbors;
}

template<typename T>
inline int Graph<T>::getNrOfVertices() const
{
	// Returns number of vertices

	//thow exception on empty!
	if (this->adjList.size() == 0)
	{
		throw std::runtime_error{ "Exception getNrOfVertices() called on empty stucture" };
	}

	
	return this->adjList.size();
}

template<typename T>
inline int Graph<T>::getNrOfEdges() const
{
	// Returns number of edges

	//thow exception on empty!
	if (this->adjList.size() == 0)
	{
		throw std::runtime_error{ "Exception getNrOfEdges() called on empty stucture" };
	}

	int nrOf = 0;

	for (auto& mapElem : this->adjList)
	{
		nrOf += mapElem.second.size();
	}
	return nrOf;
}


template<typename T>
inline void Graph<T>::MST(std::vector<std::tuple<T, T, int>>& mst, int& totalCost)
{
	// Creates the MST of the graph
	// Should populate the vector mst with all included edges in format tuple(from, to, weight)
	// and store the total cost of the MST in totalCost.

	//Kruskal´s algo

	//make a vector out of tuples
		
		//copy contents

		//quicksort based on cost/weight

	//make disjointed sets

		//loop thorugh newAdjList and union sets if two sets are not already in the same set

		//discard by doing nothing eg. dont add to mst
}