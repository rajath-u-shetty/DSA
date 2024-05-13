#include<iostream>
using namespace std;


int main(){
    int n;
    int reverseNum=0;
    cin >> n;
    int x=n;
    while(n>0){
        int lastnum = n%10;
        reverseNum = (reverseNum * 10) + lastnum;
        n = n/10;
    }
    cout << reverseNum;
    
    if(x==reverseNum) cout << "Palindrome";
    else cout << "Not palindrome";
}

