#include <iostream>
#include <vector>
using namespace std;

int main(){
  vector<int> arr;
  arr.push_back(1);
  arr.push_back(2);
  arr.push_back(3);
  arr.push_back(4);
  arr.push_back(5);
  arr.push_back(8);
  arr.push_back(8);
  arr.push_back(8);
  arr.push_back(9);
  int n = arr.size();
  int target = 8;
  int low = 0;
  int high = n - 1;

  //bruter
  // int last=-1;
  // int first=-1;
  // for(int i=0;i<n;i++){
  //   if(arr[i]==target){
  //       if(first==-1){
  //       first = i;
  //     } else last = i;
  //   }
  // }
  //

  int first = -1;
  int second = -1;

  while(low<=high){
    int mid = (low+high)/2;
    if(arr[mid] == target){
      first = mid;
      low=mid+1;
    }
    if(arr[mid]<target){
      high = mid-1;
    }else{
      low=mid+1;
    }
  }
  cout << first << " " << low;
   return 0;
}

