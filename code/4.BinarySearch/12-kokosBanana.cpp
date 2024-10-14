#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int timeCounter(vector<int> &arr, int i){
  int totalTime = 0;
  for(int i=0;i<=arr.size()-1;i++){
    totalTime += ceil(arr[i]/i);
  }
  return totalTime;
}

int main() 
{
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10,11};
    int n = arr.size();
    int low = 1;
    int high = n-1;
    int k=8;
    int ans = 0;
    while(low<=high){
     int mid = (low+high)/2;
     int hours = timeCounter(arr,mid);
     if(hours <= k){
       ans = mid;
       high = mid-1;
     }else{
      low = mid+1;
     }
    }
    cout << low;
}
