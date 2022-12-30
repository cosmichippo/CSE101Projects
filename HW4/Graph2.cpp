#include "Graph2.h"
#include <vector>
#include <string>

Graph::Graph(){
  this->vertices = std::vector<std::string>();
  this->edges = std::vector<Edge>();
}
int Graph::in_vector(std::string actor){
  for (int i = 0; i < this->vertices.size(); i++){
    if this->vertices[i] == actor:
      return i;
  }
  return -1;
}
int 
Graph::insert(std::string movie, std::vector<std::string> actors){
  if 
}