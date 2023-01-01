#include <bits/stdc++.h>
using namespace std;

int main() {

  vector<string> input;
  string userInput;
  int currentValue;
  int currentSecond;
  int previousCharValue = 0;
  int time = 0;
  vector<int> timeSet;
  
  map<char, int> char_to_num{{'a', 2}, {'b', 2}, {'c', 2}, {'d', 3}, {'e', 3}, {'f', 3}, {'g', 4}, {'h', 4}, {'i', 4}, {'j', 5}, {'k', 5}, {'l', 5}, {'m', 6}, {'n', 6}, {'o', 6}, {'p', 7}, {'q', 7}, {'r', 7}, {'s', 7}, {'t', 8}, {'u', 8}, {'v', 8}, {'w', 9}, {'x', 9}, {'y', 9}, {'z', 9}};
  
map<char, int> char_to_seconds{{'a', 1}, {'b', 2}, {'c', 3}, {'d', 1}, {'e', 2}, {'f', 3}, {'g', 1}, {'h', 2}, {'i', 3}, {'j', 1}, {'k', 2}, {'l', 3}, {'m', 1}, {'n', 2}, {'o', 3}, {'p', 1}, {'q', 2}, {'r', 3}, {'s', 4}, {'t', 1}, {'u', 2}, {'v', 3}, {'w', 1}, {'x', 2}, {'y', 3}, {'z', 4}};
  
  for(int i=0; ; i++){
    cin >> userInput;
    input.push_back(userInput);
    if (input[i] == "halt"){
      input.pop_back();
      break;
    }
  }

  for(int first=0; first<input.size(); first++){
	time = 0;
    for(int second=0; second<input[first].size(); second++){
      currentValue = char_to_num[input[first][second]]; //2
      currentSecond = char_to_seconds[input[first][second]]; //2

      time = time + currentSecond; //1
      
      if (currentValue == previousCharValue){
        time = time + 2;
      }
      
      previousCharValue = currentValue; //2
    }
    timeSet.push_back(time);
    
  }

  for(int i=0; i<timeSet.size(); i++)
    cout << timeSet[i] << endl;

}