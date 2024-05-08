#ifndef GRAPH_H
#define GRAPH_H
#include <utility>
#include <vector>
#include <climits>
#include <tuple>
#include <string>
#include <map>

const int INFINIT_COST = INT_MAX;

template<typename T>
class Edge {
public:
	int cost;
	T next;
	// Constructor
	Edge(int cost, T next)
		:cost(cost), next(next){} // Initialize the data and next pointer
};



template <class T>
class Graph
{
private:
	// for you decide
	std::map<T, std::vector<Edge<T>>> adjList; // ex when T=string: Map["A"] = Ptr to first node
	
	
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
	// finns noderna i listan

	// ("A", "B", 3)
	// ("A", "D", 3)

	std::vector<Edge<T>> &temp1 = this->adjList[from]; //checks and refs to it or creates if missing
	temp1.push_back(Edge<T>(weight, to));

	std::vector <Edge<T>> &temp2 = this->adjList[to];
	temp2.push_back(Edge<T>(weight, from));
	
	
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