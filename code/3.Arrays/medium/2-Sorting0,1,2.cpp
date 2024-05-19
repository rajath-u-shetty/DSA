#include<iostream>
using namespace std;

int main(){
    int n;
    int arr[n];

    // int cnt0 = 0;
    // int cnt1 = 0;
    // int cnt2 = 0;
    // for(int i=0;i<n;i++){
    //     if(arr[i] == 0){
    //         cnt0++;
    //     }else if(arr[i] == 2){
    //         cnt1++;
    //     }else{
    //         cnt2++;
    //     }
    // }
    // for(int i=0;i<cnt0;i++) arr[i] = 0;
    // for(int i=cnt0;i<cnt0+cnt1;i++) arr[i] = 1;
    // for(int i=cnt0+cnt1;i<n;i++) arr[i] = 2;
    

    int low=0 ,mid=0 ,high = n-1;
    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }

        if(arr[mid] == 1){
            mid++;
        }

        if(arr[mid] == 2){
            swap(arr[mid], arr[high]);
            high--;
        }

    }
}