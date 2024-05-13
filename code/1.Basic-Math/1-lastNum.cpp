#include<iostream>
using namespace std;


int main(){
    int n;
    cin >> n;
    while(n>0){
        int lastnum = n%10;
        cout << lastnum << endl;
        n=n/10;
    }
}

