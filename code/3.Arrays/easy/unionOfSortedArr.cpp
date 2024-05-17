#include <iostream>
#include <vector>
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
    int n = arr1.size() + arr2.size();
    vector<int> newArr;
    int i = 0;
    int j = 0;
    while (i < n1 && j < n2){
        if (arr1[i] <= arr2[j]){
            if (newArr.size() == 0 || newArr.back() == arr1[i]){
                newArr.push_back(arr1[i]);
            }
            i++;
        }else{
            if (newArr.size() == 0 || newArr.back() == arr2[j]){
                newArr.push_back(arr2[j]);
            }
            j++;
        }
    }

    while (i < n1){
        if (newArr.size() == 0 || newArr.back() == arr1[i]){
            newArr.push_back(arr1[i]);
        }
        i++;
    }

    while (j < n2){
        if (newArr.size() == 0 || newArr.back() == arr2[j]){
            newArr.push_back(arr2[j]);
        }
        j++;
    }

    return newArr;
}