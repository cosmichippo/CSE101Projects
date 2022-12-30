#include "BinarySearchTree.cpp"
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]){
/*
  if (argc > 3) //checks amount of args
  {
      throw std::invalid_argument("Usage: ./hello <INPUT FILE> <OUTPUT FILE>"); //throws error
  }*/
	ifstream input;
	ofstream output;

	input.open(argv[1]);
	output.open(argv[2]);
  //input.open("Tests/allwords-more-range.txt");
	//output.open("test-output.txt");


  char *com;
  char *command;
  char *key1;
  char *key2;
  string line;
  bool flag = true;
  BinarySearchTree<string, int> tree = BinarySearchTree<string, int>();
  long test = 0;
  while (getline(input, line)){
    string foo = "";
    //cout << test << endl;
    if (line.length() == 0) continue;

    com = strdup(line.c_str()); 
    command = strtok(com, " \t");
    foo = command;
    key1 = strtok(NULL, " \t");
    key2 = strtok(NULL, " \t");
    //cout << command << " "<< key1;

    if (foo == "i"){
      if(key1 == nullptr) continue;
      //cout << "test" << endl;
      string num1 = key1;
      if(flag){
        tree.addRoot(num1, 0);
        flag = false;
        //cout << "WTF"<< endl;
      }else{
        tree.insert(num1, 0);
        //cout << "pee" << endl;
      }
    }
    //cout << "line: " << line << typeof(foo) << endl; 
    if (foo == "r"){
      test++;
      if(key1 == nullptr or key2 == nullptr) continue;
      string num1 = key1;
      string num2 = key2;
      //int num1 = stoi(key1);
      //int num2 = stoi(key2);
      output << tree.range(tree.get_root(), num1, num2) << "\n";
    }
  }
  //tree.postorder(tree.get_root());
  return 0;

}