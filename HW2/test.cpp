#include <iostream>
#include <stack>
#include <array>
#include <vector>

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
      cout << "SIZE" << s.size() << endl;
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
  cout << "COUNTER: " << counter << "ARR: ";
  for (auto x: arr){
    cout<< x << ", ";
  }
  cout << endl;
    counter++;
  }
  return vector<int>();
}

int main(int argc, char** argv){
  int N = 11;
  vector<int> test = {2,0,0,7,3,0,0,0,0,0,0};
  cout << test.size();
  
  vector<int> r = {0, 3, 4, 8};
  vector<int> ans = iterative_queens(test, r);
  for (auto x: ans){
    cout<< x << ", ";
  }
  cout << endl;
  return 0;
}
