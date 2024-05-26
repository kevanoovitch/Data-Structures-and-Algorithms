#ifndef GRAPH_H
#define GRAPH_H
#include <utility>
#include <vector>
#include <map>
#include <climits>
#include <tuple>
#include <iostream>
#include <set>
#include"Quicksort.hpp"
#include "DisjointSets.hpp"
#include "MinPriorityQueue.hpp"

const int INFINIT_COST = INT_MAX;

template <typename T>
class Edge
{
public:
	int cost;
	T next;
	T origin;

	Edge() :origin(T()),next(T()),cost(0){}
	Edge(T origin, T next, int cost) : origin(origin),next(next),cost(cost){}
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
	bool operator <(const Edge& other)
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
	bool operator >(const Edge& other)
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
	std::map<T,std::vector<Edge<T>>> adjList;
public:
	Graph();
	virtual ~Graph();
	Graph(const Graph& other) = delete;
	Graph& operator=(const Graph& other) = delete;
	void addVertex(T theNode);
	void addEdge(T from, T to, int weight = 0);
	std::vector<T> getAllNeighboursTo(T vertex);
	int getNrOfVerticies() const;
	int getNrOfEdges() const;
	void prims(std::vector<std::tuple<T, T, int>>& mst, int &totalCost);
	void kruskals(std::vector<std::tuple<T, T, int>>& mst, int& totalCost);
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
inline void Graph<T>::addVertex(T theNode)
{
	this->adjList[theNode];
}

template<typename T>
inline void Graph<T>::addEdge(T from, T to, int weight)
{
	std::vector<Edge<T>>& temp = this->adjList[from];
	temp.push_back(Edge<T>(from, to, weight));
}

template<typename T>
inline std::vector<T> Graph<T>::getAllNeighboursTo(T vertex)
{
	std::vector<T> Neighbors;

	for (int i = 0; i < this->adjList[vertex].size(); i++)
	{
		Neighbors.push_back(this->adjList[vertex][i].next);
	}

	return Neighbors;
}

template<typename T>
inline int Graph<T>::getNrOfVerticies() const
{

	return this->adjList.size();
}

template<typename T>
inline int Graph<T>::getNrOfEdges() const
{
	int nrOf = 0;
	for (auto& mapElem : this->adjList)
	{
		nrOf += mapElem.second.size();
	}
	return nrOf;
}


template<typename T>
inline void Graph<T>::prims(std::vector<std::tuple<T, T, int>>& mst, int& totalCost)
{
	std::set<T> Visited;

	//make a min queue
	MinPriorityQueue<Edge<T>> MyQueue;

	//choose arbiteray starting point
	auto start = this->adjList.begin();
		//add all neighbors to the start
	for (int i = 0; i < start->second.size(); i++)
	{
		MyQueue.enqueue(start->second[i]);
	}
		//Add start as visited
	Visited.insert(start->first);

	//traverse the graph by dequeuing until queue is empty
	while (!MyQueue.is_empty())
	{
		//make a from queue Edge
		auto fromQueue = MyQueue.dequeue();

		//check if fromQueue is aldredy visited
		if (Visited.find(fromQueue.next) == Visited.end())
		{
			// add to mst, increase totaltcost, add to visitied, queue neighbors
			mst.push_back(std::make_tuple(fromQueue.origin, fromQueue.next, fromQueue.cost));
			totalCost += fromQueue.cost;
			Visited.insert(fromQueue.next);

			//add neighbors
			auto& nextAdj = this->adjList[fromQueue.next];
			for (int i = 0; i < nextAdj.size(); i++)
			{
				MyQueue.enqueue(nextAdj[i]);
			}
		}
			
		
		//else do nothing
	}


}

template<typename T>
inline void Graph<T>::kruskals(std::vector<std::tuple<T, T, int>>& mst, int& totalCost)
{
	//From new vector/tuple structure
	std::vector<std::tuple<T, T, int>> newAdjList;

	for (auto& mapElem : this->adjList)
	{
		for (int i = 0; i < mapElem.second.size(); i++)
		{
			auto TempTuple = std::make_tuple(mapElem.second[i].origin, mapElem.second[i].next, mapElem.second[i].cost);
			newAdjList.push_back(TempTuple);
		}
	}
	//quicksort the structure
	quickSort(newAdjList, newAdjList.size());

	////DEBUG check
	//for (int i = 0; i < newAdjList.size(); i++)
	//{
	//	std::cout << std::get<2>(newAdjList[i]) << std::endl;
	//}

	//make disjointed sets
	DisjointSets<T> ds;

	//build mst by adding things to mst and checking if union does not create a union

	for (auto& edge : newAdjList)
	{

		ds.makeSet(std::get<0>(edge));
		ds.makeSet(std::get<1>(edge));

		T set1 = ds.findSet(std::get<0>(edge));
		T set2 = ds.findSet(std::get<1>(edge));

		if (set1 != set2)
		{
			mst.push_back(edge);
			totalCost += std::get<2>(edge);
			ds.unionSet(set1, set2);
		}
		else
		{
			//discard by doing nothing eg. not adding to mst
		}
	}
	

	
}



