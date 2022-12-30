#include <iostream>
#include <map>
#include <string>
#include <queue>
#include "Graph.h"
#include "Graph.cpp"
#include <set>
#include <fstream>

const std::string MOVIES = "cleaned_movielist.txt";

std::vector<std::string> parse(std::string line){
  std::string str = "";
  std::vector<std::string> push = std::vector<std::string>();
  for (auto chr : line){
    if((chr == ' ')){
      push.push_back(str);
      str = "";
    }
    else{
    str += chr;
    }
  }
  return push;
}

std::vector<std::string> parse_two_electric_boogaloo(std::string line){
  std::string str = "";
  std::vector<std::string> push = std::vector<std::string>();
  for (auto chr : line){
    if((chr == ' ')){
      push.push_back(str);
      str = "";
    }
    else{
    str += chr;
    }
  }
  push.push_back(str);
  return push;
}

int main(int argc, char* argv[]){
  std::ifstream movie_input;
  std::ifstream input;
	std::ofstream output;

	movie_input.open(MOVIES);
	//output.open(argv[2]);

  std::string line;
  Graph<std::string> graph = Graph<std::string>();
  
  while(std::getline(movie_input, line)){
    if (line.length() == 0){
      continue;
    }
    std::vector<std::string> parsed = parse(line);
    
    std::string movie = parsed[0];
    parsed.erase(parsed.begin());
    graph.insert(movie, parsed);
  }

  movie_input.close();
  input.open(argv[1]);
  output.open(argv[2]);

std::string end = "Amitabh_Bachchan";
std::map<std::string, std::pair<std::string, std::string>> pitts = graph.find("Brad_Pitt", "Amitabh_Bachchan");

while(end != "Brad_Pitt"){
  std::cout << pitts[end].first << " " << pitts[end].second << std::endl;
  end = pitts[end].first;
}
//std::cout << pitts["Amitabh_Bachchan"].first << "QUE" << pitts["Amitabh_Bachchan"].second << "POR" << std::endl;


  while(getline(input, line)){
    if (line.size() == 0){
      continue;
    }

    std::vector<std::string> parsed = parse_two_electric_boogaloo(line);
    std::string root = parsed[0];
    std::string end = parsed[1];
    
    std::map<std::string, std::pair<std::string, std::string>> pitts = graph.find(parsed[0], parsed[1]);
    
    
    
    
    
    if (pitts.size() == 0){
      output << "Not present" << "\n";
    }
    else if (pitts.size() == 1){
      output << pitts[end].first << "\n";
    }
    else{
      std::vector<std::string> push = {};
      std::string norisk = "";

      while (end != root){
        
        push.push_back(end);
        norisk = "-(" + pitts[end].second + ")-";
        push.push_back(norisk);
        end = pitts[end].first;
      }
      push.push_back(end);

      for(int i = push.size() - 1; i >= 0; i--){
        output << push[i] << " ";
      }
      output << "\n";
    }
  }
  
  //std::cout << pitts["Amitabh_Bachchan"].first << " " << pitts["Amitabh_Bachchan"].second << std::endl;

  input.close();
  output.close();
  return 0;
}