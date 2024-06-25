// #include <iostream>
// #include <vector>
// using namespace std;
//
// int lowerbound(vector<int>&arr,int n,int x){
//   int low=0;int high=n-1;
//   int ans=0;
//   while(low<=high){
//     int mid=(low+high)/2;
//     if(arr[mid]>=x){
//       ans=mid;
//       high=mid-1;
//     }else{
//       low=mid+1;
//     }
//   }
//   return ans;
// }
//
//
//
// int upperbound(vector<int>&arr,int n,int x){
//   int low=0;int high=n-1;
//   int ans=0;
//   while(low<=high){
//     int mid=(low+high)/2;
//     if(arr[mid]>x){
//       ans=mid;
//       high=mid-1;
//     }else{
//       low=mid+1;
//     }
//   }
//   return ans;
// }
//
// int main(){
//   vector<int> arr;
//   arr.push_back(1);
//   arr.push_back(2);
//   arr.push_back(3);
//   arr.push_back(4);
//   arr.push_back(5);
//   arr.push_back(8);
//   arr.push_back(8);
//   arr.push_back(8);
//   arr.push_back(9);
//   int n = arr.size();
//   int target = 8;
//   int low = 0;
//   int high = n - 1;
//
//   //bruter
//   // int last=-1;
//   // int first=-1;
//   // for(int i=0;i<n;i++){
//   //   if(arr[i]==target){
//   //       if(first==-1){
//   //       first = i;
//   //     } else last = i;
//   //   }
//   // }
//   //
//
//   int first = -1;
//   int second = -1;
//
//   int lb = lowerbound(arr,n,target);
//   if(lb == n || arr[lb]!= target) return  {-1, -1};
//   return {lb, upperbound(arr,n,target)};
//
//   return 0;
// }
//
//



#include<iostream>
#include <utility>
#include <vector>
using namespace std;

int firstOcuurance(vector<int> &arr, int n, int x){
  int low=0;int high=n-1;
  int first=-1;
  while(low<=high){
    int mid=(low+high)/2;
    if(arr[mid]==x){
      first=mid;
      high=mid-1;
    }else if(arr[mid]<x){
      low=mid+1;
    }else{
      high=mid-1;
    }
  }
  return first;
}

int lastOcuurance(vector<int> &arr, int n,int x){
  int low=0;int high=n-1;
  int last=-1;
  while(low<=high){
    int mid=(low+high)/2;
    if(arr[mid]==x){
      last=mid;
      low=mid+1;
    }else if(arr[mid]<x){
      low=mid+1;
    }else{
      high=mid-1;
    }
  }
}

pair<int, int> main(){
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
  
  int first = firstOcuurance(arr,n,target);
  if(first==-1)return {-1, -1};
  int last = lastOcuurance(arr,n,target);
  return {first, last};
}
