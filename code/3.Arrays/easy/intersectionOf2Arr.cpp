#include<iostream>
using namespace std;

int main(){
    int n1,n2;
    int a[n1],, a2[n2];
    for(int i=0;i<=n;i++){
        cin >>  a[i];
    }

    for(int i=0;i<=n;i++){
        cin >>  b[i];
    }

    vector<int> newArr;
    int i = 0;
    int j = 0;

    while(i < n1 && j < n2){
        if(a[i] < b[j]){
            i++;
        }else if(a[i] > b[j]){
            j++;
        }
        else{
            newArr.push_back(a[i]);
            i++;
            j++;
        }

    }
    
}