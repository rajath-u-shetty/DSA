#include <iostream>
#include <cmath>
using namespace std;


int main(){
    int n,temp;
    cin >> n;
    temp=n;
    int count=0;
    
    while(temp>0){
      count++;
      temp=temp/10;
    }
    
    temp=n;
    int lastnum,sum=0;

    while(temp>0){
        lastnum = temp%10;
        sum=sum + pow(lastnum, count);
        temp=temp/10;
    }
    
    if(n==sum)cout << "True";
    else cout <<  "False";
}

