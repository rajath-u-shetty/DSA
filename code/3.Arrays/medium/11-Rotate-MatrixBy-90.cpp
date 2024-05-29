#include <iostream>
#include <vector>

using namespace std;

int main() {
  //BRUTE
  // vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  // int n = arr.size();
  //
  // vector<vector<int>> ans(n, vector<int>(n));
  //
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < n; j++) {
  //     ans[j][n - i - 1] = arr[i][j];
  //   }
  // }
  //


  // OPTIMALL
  int vector<int> arr = {};
  int n = arr.size();
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      swap(arr[i][j], arr[j][i]);
    }
  }

  for(int i=0;i<n;i++){
    reverse(arr[i].begin(), arr[].end());
  }
  return 0;
}
