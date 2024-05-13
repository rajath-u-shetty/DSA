#include <iostream>
#include <cmath>
using namespace std;


int main(){
    int n,x;
    cin >> n;
    x=n;
    int count=0;
    
    while(x>0){
      x=x/10;
      count++;
    }
    
    x=n;
    int lastnum,sum=0;
    while(x>0){
        lastnum = x%10;
        sum=sum + pow(lastnum, count);
        x=x/10;
    }
    
    if(x==sum)cout << "True";
    else cout <<  "False";
}

