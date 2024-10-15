#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

int countDivisor(vector<int> &arr, int mid){
  int totalSum = 0;
  for(int i=0;i<arr.size();i++){
    totalSum += ceil((double)arr[i] / mid); 
  }
  return totalSum;
}

int main() 
{
    vector<int> arr = {1,2,5,9};
    int n = arr.size();
    int low = 1;
    int high = 9;
    int mid = 0;
    int ans = 0;
    int threshold = 7;
    while(low<= high){
      mid = (low+high)/2;
      int val = countDivisor(arr, mid);
      if(val <= threshold){
        ans = mid;
        high = mid -1;
      }else{
        low = mid+1;
      }
    }
    cout << ans;
}
