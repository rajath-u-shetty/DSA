#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

int main() 
{
    vector<int> arr = {1,1,2,2,3,3,4,5,5,6,6};
    int n=arr.size();
    int mid=0;
    int low = 1;
    int high = n-2;
    int ans = INT_MIN;
    while(low <= high){
      mid = (low+high)/2;
      if(arr[1]!=arr[0]){
        cout << arr[0];
      }
      
      if(arr[n-1] != arr[n-2]){
        cout << arr[n-1];
      }
      
      if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]){
        cout << mid;
      }
      
      if((mid % 2 == 1 && arr[mid] == arr[mid-1]) || (mid % 2 == 0  && arr[mid] != arr[mid+1])){
        low = mid+1;
      }else{
        high = mid -1;
      }
    }
    cout << mid;
}
