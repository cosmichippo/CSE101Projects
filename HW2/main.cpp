//
// Created by Juan-Fernando Prado Morales on 10/26/2022.
//


#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include <string>
#include <array>
#include <cstring>
using namespace std;


using A = array<int, 2>;

bool helper(vector<int> array, int column, int row_val){
  int diag_up = row_val;
  int diag_down = row_val;
  for (int col_pos = column; col_pos > -1; col_pos--){
    diag_up += 1;
    diag_down -= 1;
    if (array[col_pos] == row_val){
      //cout << "row == row " <<  array[col_pos] << endl;
      return false;}
    if (array[col_pos] == diag_up){
      //cout << "diag_up == row " <<  array[col_pos] << endl;
      return false;}
    if (array[col_pos] == diag_down){
      //cout << "diag_down == row " <<  array[col_pos] << endl;
      return false;
    }
  }
  return true;

}



bool IinVec(int i, vector<int> a){
  if (a.size() == 0){
    return false;
  }
  for (auto x : a){
    if (x == i){
      return true;
    }
  }
  return false;
}

vector<int> iterative_queens(vector<int> arr, vector<int> restrictions){
  stack<A> s = stack<A>();
  bool flag = true;
  int arrSize = arr.size();
  s.push({0,0});

  int counter = 0;
  
  while (s.size() > 0 && counter < 100){
    //cout << "Counter: " <<counter;
    int col = s.top()[0];
    int row = s.top()[1];
    if (col == arrSize){
      return arr;
    }
    if (IinVec(col, restrictions)){
      //cout << "restriction called" << endl;

      s.pop();
      if (helper(arr, col - 1, arr[col])){
        A new_pos = {col + 1, 0};
        s.push(new_pos);
      }
      //cout << "SIZE" << s.size() << endl;
    }
    else{
      for (int r = row; r < arrSize; r++){
        if (helper(arr, col-1, r)){
          //cout << "found node" << col << "," << r << endl;
          s.top()[1] = r + 1;

          A new_pos = {col + 1, 0};
          arr[col] = r;
          s.push(new_pos);
          flag = false;
          break;
        }
      }
      if (flag){
        s.pop();
        //cout << "SIZE" << s.size() << endl;
      }else{
        flag = true;
      }
    }
  //cout << "COUNTER: " << counter << "ARR: ";
  /*for (auto x: arr){
    cout<< x << ", ";
  }
  cout << endl;
    counter++;*/
  }
  return vector<int>();
}

int main(int argc, char* argv[]){

    if (argc > 3) //checks amount of args
    {
        throw std::invalid_argument("Usage: ./NQueens <INPUT FILE> <OUTPUT FILE>"); //throws error
    }

		ifstream input;
		ofstream output;

		//open fstreams
		input.open(argv[1]);
		output.open(argv[2]);

    char *com;
    char *pos1;
    char *pos2;
    string line;
    string foo = "";
    int N;

    while (getline(input, line)){
    vector<int> arr;
    vector<int> restrictions;
      if (line.length() == 0)
            continue;
      com = strdup(line.c_str()); 
      pos1 = strtok(com, " \t");

      N = stoi(pos1);
      arr = vector<int>(N, 0);

      while (pos1 != NULL){
        pos1 = strtok(NULL, " \t");
        pos2 = strtok(NULL, " \t");

        if (pos1 != NULL && pos2 != NULL){
          int i = stoi(pos1) - 1;
          int j = stoi(pos2) - 1;
          arr[i] = j;
          restrictions.push_back(i);
        }
      }

      arr = iterative_queens(arr, restrictions);
      
      if (arr.size() > 0){
        for (uint i = 0; i < arr.size() - 1; i++){
          output << i + 1 << " " << arr[i] + 1 << " ";
        }
        output << arr.size() << " " <<  arr.back() + 1 << "\n";
      }
      else{
          output << "No solution\n";
      }
    }

    input.close();
    output.close();


}