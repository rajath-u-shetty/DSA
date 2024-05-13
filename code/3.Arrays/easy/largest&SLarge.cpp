#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i =0;i<=n;i++){
        cin >> arr[i];
    }

    int maxi = 0;
    int sMaxi = 0;
    for(int i=0;i<=n;i++){
        if(arr[i] > maxi){
            sMaxi = maxi;
            maxi = arr[i];
        }
        if(arr[i] > sMaxi && arr[i] < maxi){
            sMaxi = arr[i];
        }
    }

    cout << maxi;
    cout << sMaxi;

}