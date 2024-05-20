// Majority element that is greater tha n/2

#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    // Brute
    // [2,2,3,3,1,2,2]
    // for(int i=0;i<n;i++){
    //     cnt = 0;
    //     for(int j=0;j<n;j++){
    //         if(arr[j] == arr[i]){
    //             cnt++;
    //         }
    //     }
    //     if(cnt > n/2) return a[i];
    // }

    // Better
    // map<int, int> mpp;
    // for(int i=0;i<n;i++){
    //     mpp[arr[i]++];
    // }

    // for(auto it: mpp){
    //     if(it.second() > (n / 2)){
    //         return it.first()
    //     }
    // }

    int cnt = 0;
    int ele;
    for(int i=0;i<n;i++){
        if(cnt==0){
            cnt=1;
            ele=arr[i];
        }else if(arr[i] == ele){
            cnt++;
        }else{
            cnt--;
        }
    }

    int cnt1=0;
    for(int i=0;i<n;i++){
        if(arr[i] = ele) cnt1++;
        //the last assigned element is counted
    }
    if(cnt1 > n/2) return ele;
}