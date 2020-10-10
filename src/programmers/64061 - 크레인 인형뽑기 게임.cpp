#include <iostream>
#include <vector>
#include "../print_utils.hpp"

using namespace std;

vector<vector<vector<int>>> inputs1 = {
  {
    {0,0,0,0,0},
    {0,0,1,0,3},
    {0,2,5,0,1},
    {4,2,4,4,2},
    {3,5,1,3,1}
  }
};

vector<vector<int>> inputs2 = {
  {1,5,3,5,1,2,1,4}
};

int outputs[] = {
  4
};

int solution(vector<vector<int>> board, vector<int> moves) {
  ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

  int HEIGHT = board.size();
  int WIDTH = board[0].size();

  vector<int> pointers(WIDTH);
  vector<int> stack;
  int result = 0;

  for(int j = 0; j < WIDTH; j++) {
    for(int i = 0; i < HEIGHT; i++) {
      if (board[i][j] != 0) {
        pointers[j] = i;
        break;
      }
    }
  }

  for(int move2: moves) {
    int move = move2 - 1;

    if (pointers[move] >= HEIGHT) {
      continue;
    }

    int doll = board[pointers[move]][move];
    
    if (stack.size() > 0 && stack.back() == doll) {
      stack.pop_back();
      result++;
    } else {
      stack.push_back(doll);
    }

    // board[pointers[move]][move] = 0;
    pointers[move]++;
  }

  // cout << stack << endl;
  
  return result * 2;
}

int main() {
  cout << "64061 - 크레인 인형뽑기 게임" << endl;
  for (int i = 0; i < inputs1.size(); i++) {
    auto input1 = inputs1[i];
    auto input2 = inputs2[i];
    auto expected = outputs[i];
    auto real = solution(input1, input2);

    if(real == expected) {
      cout << "success" << endl;
    } else {
      cout << "failed" << endl;
      cout << expected << endl;
      cout << real << endl;
    }
  }
}