#ifndef DISJOINTSETS_HPP
#define DISJOINTSETS_HPP

#include <unordered_map>
#include <iostream>
#include <vector>

template <class T>
class DisjointSets {
private:

public:
    DisjointSets();
    int size();
    void makeSet(T u);
    T findSet(T u, bool with_path_compression = false);
    void unionSet(T u, T v, bool with_rank = false);

};
template <class T>
DisjointSets<T>::DisjointSets()
{

}
template <class T>
int DisjointSets<T>::size()
{

}
template <class T>
void DisjointSets<T>::makeSet(T u)
{

}
template <class T>
T DisjointSets<T>::findSet(T u, bool with_path_compression)
{
    return T();
}
template <class T>
void DisjointSets<T>::unionSet(T u, T v, bool with_rank)
{

}

#endif