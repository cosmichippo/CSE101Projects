#include <map>
#include "Graph.h"
#include <vector>
#include <queue>
#include <list>
#include <iostream>

template <class KeyType>
Graph<KeyType>::Graph(){
  this->edges = std::vector<Edge<KeyType>>();
  this->adjList = std::map<KeyType, std::vector<Edge<KeyType>>>();
}

template<class KeyType>
void Graph<KeyType>::insert(KeyType movie, std::vector<KeyType> actors){
  for (auto actor: actors){
    if (this->adjList.find(actor) == this->adjList.end()){
      this->adjList[actor] = std::vector<Edge<KeyType>>();
    }
    for (auto potential_neighbor: actors){
      if (potential_neighbor != actor){
        this->edges.push_back(Edge<KeyType>(actor, potential_neighbor, movie));
        this->adjList[actor].push_back(Edge<KeyType>(actor, potential_neighbor, movie));      }
    }
  }
}

template<class KeyType>
std::map<KeyType, std::pair<KeyType, KeyType>> Graph<KeyType>::find(KeyType source, KeyType end){
  std::map<KeyType, std::pair<KeyType, KeyType>> prevs = std::map<KeyType, std::pair<KeyType, KeyType>>(); //use a map to maintain previous from a pos. if it is in prevs, that means that it has alr been looked at.
  if(this->adjList.find(source) == this->adjList.end()){
    return std::map<KeyType, std::pair<KeyType, KeyType>>();
  }
  if(this->adjList.find(end) == this->adjList.end()){
    return std::map<KeyType, std::pair<KeyType, KeyType>>();
  }
  
  prevs[source] = std::pair<KeyType, KeyType>(source, source);
  
  std::queue<KeyType> to_visit = std::queue<KeyType>(); //use a queue to keep track of where within the adjList we are
  to_visit.push(source);
  while (!to_visit.empty()){
    KeyType at = to_visit.front();
    to_visit.pop();

    if (at == end){
      return prevs;
    }

    for (auto neighbor_edge : this->adjList[at]){
      if (prevs.find(neighbor_edge.connected) == prevs.end()){
        prevs[neighbor_edge.connected] = std::pair<KeyType, KeyType>(at, neighbor_edge.name);
        to_visit.push(neighbor_edge.connected);
      }
    }
  }
  return std::map<KeyType, std::pair<KeyType, KeyType>>();
}