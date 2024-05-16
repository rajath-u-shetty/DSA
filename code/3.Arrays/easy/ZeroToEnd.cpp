#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    cin >> n;
    int arr[n];

    for(int i=0;i<=n;i++){
        cin >> arr[i];
    }

    int j=-1;
    for(int i=0;i<=n;i++){
        if(arr[i]==0){
            j=arr[i];
            break;
        }
    }

    if(j==-1) return;

    for(int i=0;i<=n;i++){
        if(arr[j+1] != 0){
            swap(arr[i],arr[j])
            j++;
        }
    }
}