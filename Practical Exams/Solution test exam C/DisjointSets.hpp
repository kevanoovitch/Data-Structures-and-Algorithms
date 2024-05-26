#ifndef DISJOINTSETS_HPP
#define DISJOINTSETS_HPP

#include <unordered_map>
#include <iostream>
#include <vector>

template <class T>
class DisjointSets {
private:
    std::unordered_map<T, T> elems;
    std::unordered_map<T, int> ranks;

public:
    int size() {
        return elems.size();
    }

    void makeSet(T u) {
        if (elems.find(u) == elems.end())
        {
            elems[u] = u;
            ranks[u] = 0;
        }
    }

    T findSet(T u, bool with_path_compression = false) {
        return _findSet(u, T(), with_path_compression);
    }

    T _findSet(T parent, T child, bool with_path_compression) {

        //base case 
        if (parent == child)
        {
            return parent;
        }
        //if without compression
        if (!with_path_compression)
        {
            return _findSet(elems[parent], parent, with_path_compression);
        }
        //else with compression
        else
        {
            elems[parent] = _findSet(elems[parent], parent, with_path_compression);
            return elems[parent];
        }
      
    }

    void unionSet(T u, T v, bool with_rank = false) {
        
        // make sets
        T u_set = findSet(u);
        T v_set = findSet(v);
        //if without ranks
        if (!with_rank)
        {
            if (u_set != v_set)
            {
                //only do stuff if sets are not the same
                elems[u_set] = v_set;
            }
        }
        //else with ranks
        else
        {
            //if ranks are equal
            if (ranks[u_set] == ranks[v_set])
            {
                ranks[u_set]++;
                elems[u_set] = v_set;
            }

            //if u rank is less than v
            else if (ranks[u_set] < ranks[v_set])
            {
                elems[v_set] = u_set;
            }
            //if u rank is greater than v
            else
            {
                elems[u_set] = v_set;
            }


           
        }
       

           
    }
};

#endif