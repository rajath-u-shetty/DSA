#include<iostream>
#include<vector>
using namespace std;

int main(){

  vector<int> arr;
  arr.push_back(7);
  arr.push_back(8);
  arr.push_back(9);
  arr.push_back(1);
  arr.push_back(2);
  arr.push_back(3);
  arr.push_back(4);
  arr.push_back(5);
  arr.push_back(6);
  // [7,8,9,1,2,3,4,5,6]
  // 9
  int n = arr.size();
  int target = 8;
  int low = 0;
  int high = n - 1;

  while(low<=high){
    int mid = (low+high)/2;
    if(arr[mid]==target) return mid;
    if(arr[low]<=arr[mid]){
      if(arr[low]<target && target < arr[mid]){
        high=mid-1;
      }else{
        low=mid+1;
      }
    }else{
      if(arr[mid]<target && target < arr[high]){
        low=mid+1;
      }else{
        high=mid-1;
      }
    }
  }
  return 0;
}

