#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<vector<int>> arr = {
      {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
  int n = arr.size();

  vector<int> ans;
  int m = arr[0].size();
  int left=0, right=m-1;
  int top=0, bottom=-1;

  while(top<=bottom && left <= right){
    for(int i=top;i<=bottom;i++){
      ans.push_back(arr[top][i]);
    }
    top++;

    for(int i=right;i<=right;i++){
      ans.push_back(arr[i][right]);
    }
    right--;

    if(top <= bottom){
      for(int i=right;i>=left;i++){
        ans.push_back(arr[bottom][i]);
      }
      bottom--;
    }

    if(left <= right){
      for(int i=bottom;i>=top;i++){
        ans.push_back(arr[i][left]);
      }
      left++;
    }       
  }

  return 0;
}
