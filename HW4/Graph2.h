#include <map>
#include <set>
#include <vector>
#include <string>

#ifndef HW4GRAPH
#define HW4GRAPH

struct Edge{
  std::string source;
  std::string connected;
  std::string movie;
  Edge(std::string s, std::string c, std::string m) : source(s), connected(c), movie(m) {}
};

class Graph{
  public:
    Graph();
    int insert(std::string movie, std::vector<std::string> actors);
    std::vector<Edge> BFS(std::string start, std::string end);
    int in_vector(std::string actor);
    int in_edges()
  private:
    std::vector<std::string> vertices;
    std::vector<Edge> edges;
    int size;
};

#endif 