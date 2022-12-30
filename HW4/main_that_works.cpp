#include <iostream>
#include <map>
#include <string>
#include <queue>
#include "Graph.h"
#include "Graph.cpp"
#include <set>
std::vector<std::string> data = {"Miss_Jerry Blanche_Bayliss William_Courtenay Chauncey_Depew ",
"The_5,000_Fingers_of_Dr._T. Peter_Lind_Hayes Mary_Healy Hans_Conried Tommy_Rettig ",
"Ant_Pasted Mel_Blanc Arthur_Q._Bryan ",
"Bandits_of_the_West Roy_Barcroft Mel_Blanc Allan_Lane Black_Jack Eddy_Waller Cathy_Downs ",
"Big_Leaguer Edward_G._Robinson Vera-Ellen Jeff_Richards Richard_Jaeckel ",
"Crazylegs Elroy_'Crazylegs'_Hirsch Lloyd_Nolan Joan_Vohs James_Millican ",
"Dance_Hall_Racket Timothy_Farrell Lenny_Bruce Bernie_Jones Honey_Bruce_Friedman ",
"Dream_Wife Cary_Grant Deborah_Kerr Walter_Pidgeon Betta_St._John ",
"Easy_Peckin's Mel_Blanc Bea_Benaderet Gladys_Holland ",
"El_Paso_Stampede Stephen_Chase Allan_Lane Black_Jack Eddy_Waller Phyllis_Coates ",
"The_Flaming_Urge Harold_Lloyd_Jr. Cathy_Downs Byron_Foulger Jonathan_Hale ",
"Fresh_Painter Gil_Lamb Carol_Hughes Andy_Clyde Dick_Wessel Florence_Lake William_J._O'Brien Emil_Sitka" 
};


std::vector<std::string> parse(std::string line){
  std::string str = "";
  std::vector<std::string> push = std::vector<std::string>();
  for (auto chr : line){
    if(chr == ' ' or chr == '\n'){
      push.push_back(str);
      str = "";
    }
    else{
    str += chr;
    }
  }
  return push;
}

int main(int argc, char* argv[]){
  
  std::vector<std::vector<std::string>> parsed = std::vector<std::vector<std::string>>();
  Graph<std::string> G = Graph<std::string>();
  for (auto line: data){
    parsed.push_back(parse(line));
  }
for (auto line : parsed){
  std::string movie = line[0];
  line.erase(line.begin());
  G.insert(movie, line);
}

std::string start = "Arthur_Q._Bryan";
std::string last = "Allan_Lane";
std::string movie = std::string();
std::map<std::string, std::pair<std::string, std::string>> test = G.find(start, last);
std::cout << G.adjList["Arthur_Q._Bryan"].size() << std::endl;
while (start != last){
  std::cout << last;
  movie = test[last].second;
  std::cout << " " << movie << std::endl;
  last = test[last].first;
}
  return 0;
}