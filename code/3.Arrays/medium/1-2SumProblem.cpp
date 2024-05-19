#include<iostream>
using namespace std;

int main(){
    int n,target;
    cin >> target;
    cin >> n;
    int arr[n];
    // [2,6,5,8,11]
    //target = 14
    for(int i=0;i<=n;i++){
        cin >> arr[i];
    }
    
    // BRUTE
    // for(int i=0;i<n;i++){
    //     for(int j=i;j<n;j++){
    //         if(arr[i] + arr[j] == target){
    //             cout >> "true";
    //             cout >> arr[i] >> arr[j];
    //         }
    //     }
    // }

    // BETTER 
    // map<int, int> mpp;
    // for(int i=0;i<n;i++){
    //     int a = arr[i];
    //     int rem = target - a;

    //     if(mpp.find(rem) != mpp.end()){
    //         return "YES";// return (mpp[rem], i)
    //     }
    //     mpp[a] = i;
    // }

    int left = 0,right = n-1;
    while(left < right){
    int sum = arr[left] + arr[right]
      if( == target ){
        cout << "YES";
        break;
      }else if(sum < target){
        left++;
      }else {
        right--;
      }
    }
}