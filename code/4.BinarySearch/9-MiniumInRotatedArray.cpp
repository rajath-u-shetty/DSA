#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int searchInARotatedSortedArrayII(vector<int> &arr) {
  int n = arr.size();
  int low = 0;
  int high = n - 1;
  int mid;
  int ans = INT_MAX;
  while(low<=high){
    mid = (low+high)/2;
    if(arr[low]<=arr[mid]){
      ans = min(ans,arr[low]);
      low = mid+1;
    }else{
      ans = min(ans,arr[mid]);
      high = mid - 1;
    }
    cout << ans;
  }
  return ans;
}

int main() {
  vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
  int ans = searchInARotatedSortedArrayII(arr);
  cout << ans;
  return 0;
}

