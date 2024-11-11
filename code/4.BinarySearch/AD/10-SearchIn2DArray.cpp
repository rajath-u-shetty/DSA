#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<vector<int>> arr = {
      {10, 20, 30, 40}, {15, 25, 35, 45}, {27, 29, 37, 45}, {32, 33, 39, 50}};

  int i = 0;
  int j = m - 1;
  int k = 29;
  while (i >= 0 && i < n && j >= 0 && j < m) {
    if (arr[i][i] == k) {
      return i + j;
    }
    if (arr[i][j] > k) {
      j--;
    } else if (arr[i][j] < k) {
      i++;
    }
  }
  return -1;
}
