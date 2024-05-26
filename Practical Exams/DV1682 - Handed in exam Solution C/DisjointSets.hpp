#ifndef DISJOINTSETS_HPP
#define DISJOINTSETS_HPP

#include <stdexcept>
#include <unordered_map>
template <class T>
class DisjointSets {
private:
    // To be filled.
    //create to unordermaps elems and ranks

    std::unordered_map<T, T> elems;
    std::unordered_map<T, int> ranks;
    
public:
    DisjointSets();
    ~DisjointSets();
    DisjointSets(const DisjointSets &other) = delete;
    DisjointSets& operator=(const DisjointSets &other) = delete;
    int size();
    void makeSet(T u);
    T _findSet(T parent, T child);
    T findSet(T u);
    void unionSet(T u, T v);
};
template <class T>
DisjointSets<T>::DisjointSets()
{

}
template <class T>
DisjointSets<T>::~DisjointSets()
{

}
template <class T>
int DisjointSets<T>::size()
{   
    //thow exception on empty (?)
    //return size of unorder map elems
    return elems.size();
}
template <class T>
void DisjointSets<T>::makeSet(T u)
{
    //thow exception on empty (?)

    if (elems.find(u) == elems.end())
    {
        //if u is not an element in the disjointed structure it becoms its own value with the rank of 0
        elems[u] = u;
        ranks[u] = 0;
    }
}


    
template <class T>
T DisjointSets<T>::_findSet(T parent, T child)
{
   

    //base case if parent is child
    if (parent == child)
    {
        return parent;
    }
    else
    {
        //traverse and search for leaf child (?)
        return _findSet(elems[parent], child);
    }
}

template <class T>
T DisjointSets<T>::findSet(T u)
{
    //thow exception on empty (?)
    if (elems.size() == 0)
    {
        throw std::runtime_error{ "Exception: findSets() called on empty dis_Set" };
    }
    //use helper functions
    return _findSet(elems[u], u);
}
template <class T>
void DisjointSets<T>::unionSet(T u, T v)
{
    //thow exception on empty (?)
    if (elems.size() == 0)
    {
        throw std::runtime_error{ "Exception: unionSet() called on empty dis_Set" };
    }


    // find the sets from the structure

    //exception of the sets cant be found(?)
    T u_set = findSet(u);
    T v_set = findSet(v);

    //union-by-rank : look for the three "rank" cases
    if (ranks[u_set] == ranks[v_set])
    {
        ranks[u_set]++;
        elems[u_set] = v_set;
    }
    else if (ranks[u_set] < ranks[v_set])
    {
        elems[v_set] = u_set;
    }
    else
    {
        //u_set greater then v_set
        elems[u_set] = v_set;
    }


}
#endif