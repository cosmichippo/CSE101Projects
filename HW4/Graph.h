#include <map>
#include <list>

#ifndef AO4GRAPH
#define AO4GRAPH
template <class KeyType>
struct Edge{
  KeyType source;
  KeyType connected;
  KeyType name;
  Edge<KeyType>(KeyType s, KeyType c, KeyType m) : source(s), connected(c), name(m) {}
  Edge<KeyType>() : source(), connected(), name() {}

};


template <class KeyType>
class Graph{
  public:
    void insert(KeyType movie, std::vector<KeyType> actors);
    std::map<KeyType, std::pair<KeyType,KeyType>> find(KeyType source, KeyType end);
    Graph();
    //~Graph();
    std::vector<Edge<KeyType>> edges;
    std::map<KeyType, std::vector<Edge<KeyType>>> adjList;
};
#endif