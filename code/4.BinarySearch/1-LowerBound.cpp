#include<iostream>
#include<vector>

using namespace std;

//BRUTE
// int main(){
// vector<int> arr = {1,2,3,5,6,8,10,11,14,17,19};
// int n = arr.size();
// int target = 11;
//   
//  for(int i=0;i<n;i++){
//     if(arr[i]>=target){
//       cout << i;
//     }
//   }
//   return 0;
// }
//

//BETTER
int BS(int *arr,int low,int high,int target,int ans){
  int mid = (low+high)/2;
  if(low >= high) return -1;
  if(arr[mid] < target){
    BS(arr,low,mid+1,target,ans);
  }else{
    ans=mid;
    BS(arr,mid-1,high,target,ans);
  }

  return ans;
}

int main(){
  vector<int> arr = {1,2,3,5,7,8,9,10,11,13,15,17};
  int n = arr.size();
  int low = 0;
  int high = n-1;
  int ans = n;
  int target = 11;
  BS(arr,low,high,target,ans);

  //OR
  // while(low<=high){
  //   int mid=(low+high)/2;
  //   if(arr[mid] >= target){
  //       ans=mid;
  //       high=mid+1;
  //   }else{
  //       low=mid-1;
  //   }
  // }

}






