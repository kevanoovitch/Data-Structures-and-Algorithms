#ifndef GRAPH_H
#define GRAPH_H
#include <utility>
#include <vector>
#include <climits>
#include <tuple>
#include <string>
#include <map>

const int INFINIT_COST = INT_MAX;

template <class T>
class Graph
{
private:
	// for you decide
	std::map<T, Node*>> adjList; // ex when T=string: Map["A"] = Ptr to first node
	
	
public:
	Graph();
	virtual ~Graph() = default;
	Graph(const Graph& other) = delete;
	Graph& operator=(const Graph& other) = delete;
	void addVertex(T theNode);
	void addEdge(T from, T to, int weight = 0);
	std::vector<T> getAllNeighboursTo(T vertex);
	int getNrOfVertices() const;
	int getNrOfEdges() const;
	void kruskals(std::vector<std::tuple<T, T, int>>& mst, int& totalCost);
	void prims(std::vector<std::tuple<T, T, int>>& mst, int& totalCost);
	void readFromFile(std::string file);

	std::string depthFirstSearch(T from);
	std::string breadthFirstSearch(T from);
};

template<typename T>
class Node {
public:
	T data;        // Data field
	Node<T>* next; // Pointer to the next node

	// Constructor
	Node(T data, Node<T>* next = nullptr)
		: data(data), next(next) {} // Initialize the data and next pointer
};


#endif

template<class T>
inline Graph<T>::Graph()
{
}

template<class T>
inline void Graph<T>::addVertex(T theNode)
{

}

template<class T>
inline void Graph<T>::addEdge(T from, T to, int weight)
{
	//add_edge() för att lägga till en båge mellan två noder. 
	// Finns inte någon eller båda av noderna skall dessa skapas i add_edge().

	//Does the nodes exist? Any missing needs to be created.
	
		//Check for keys "from" and "to" in the adjList

		

	//else add this edge to the corresponding list entry in adjList
	
	
	
}

template<class T>
inline std::vector<T> Graph<T>::getAllNeighboursTo(T vertex)
{
	return std::vector<T>();
}

template<class T>
inline void Graph<T>::kruskals(std::vector<std::tuple<T, T, int>>& mst, int& totalCost)
{

}

template<class T>
inline void Graph<T>::prims(std::vector<std::tuple<T, T, int>>& mst, int& totalCost)
{

}

template<class T>
inline int Graph<T>::getNrOfVertices() const
{
	return 0;
}

template<class T>
inline int Graph<T>::getNrOfEdges() const
{
	return 0;
}

template <class T>
std::string Graph<T>::depthFirstSearch(T from)
{
	return "";
}
template <class T>
std::string Graph<T>::breadthFirstSearch(T from)
{
	return "";
}