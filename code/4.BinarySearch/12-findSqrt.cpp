#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<int> arr = {1,  2,  3,  4,  5,  6,  7,  8,  9,  10,
               11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
  int n = arr.size();
  int low = 0;
  int high = n-1;
  int mid;
  int x = 9;
  while(low<=high){
    mid = (low+high)/2;
    if(mid * mid <= n){
      int ans = mid;
      low = mid+1;
    }else{
      high = mid-1;
    }
  }
  cout << mid;
  return 0;
}

