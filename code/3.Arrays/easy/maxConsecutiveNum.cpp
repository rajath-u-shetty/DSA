#include<iostream>
usimg namespace std;

int main(){
    // [1,1,0,0,1,1,1,0,1,1]
    int n,maxi=0,count=0;
    cin >> n;
    int arr[n];

    for(int i=0;i<=n;i++){
        cin >> arr[i];
    }

    for(int i=0;i<n;i++){
        if(arr[i] == 1){
            count ++;
            maxi = max(count, maxi);
        }else{
            count = 0;
        }
    }
}