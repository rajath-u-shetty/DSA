#include<iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int int a[N];
    int xor1 = 0;
    int xor2 = 0;

    int n = N - 1;//one missing element

    for(int i=0;i<=n;i++){
        xor2 = xor2 ^ a[i];//xor of elements in the array
        xor1 = xor1 ^ (i+1); // xor of n natural number except Nth number bcz we used n=N-1
    }

    xor1 = xor1 ^ N;//xor of last number N
    return xor1 ^ xor2;
}