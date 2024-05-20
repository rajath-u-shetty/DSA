#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> arr;
  arr = {-2, -3, 4, -1, -2, 1, 5, -3};
  int n = arr.size();

  // BRUTE
  // int maxi = 0;
  // for(int i=0;i<n;i++){
  //   for(int j=i;j<n;j++){
  //     int sum = 0;
  //     for(int k=i;k<j;k++){
  //       sum += arr[k];
  //       maxi = max(sum, max);
  //     }
  //   }
  // }

  // Better
  //   int maxi = 0;
  //    for(int i=0;i<n;i++){
  //    for(int j=1;j<n;j++){
  //      int sum = 0;
  //      for(int k=0;k<j;k++){
  //        sum += arr[j];
  //        maxi = max(sum, max);
  //      }
  //    }
  //  }
 
  // optimal
 
  int sum = 0;
  int maxi = INT_MIN;
  for(int i=0;i<n;i++){
    sum += arr[i];

    if(sum >  maxi){
       maxi = sum;
    }

    if(sum < 0){
      sum = 0;
    }
  }

  // follow up question - print sub-arr witth max-sum
  int sum = 0;
  int maxi = INT_MIN;
  for(int i=0;i<n;i++){
  if(sum == 0 ) start = i; //everytime sum bcms 0 we assign the index to start
  
    sum += arr[i];
    if(sum >  maxi){
       maxi = sum;
       arrStart = start,
       arrEnd = i;
    }
    
    if(sum < 0){
      sum = 0;
    }
  }

  return 0;
}
