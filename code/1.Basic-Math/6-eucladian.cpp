#include <iostream>
using namespace std;


int main(){
  int a,b;
  cin >> a;
  cin >> b;
  while(a>0 && b>0){
    if(a>b){
      a=a%b;
    }else{
      b=b%a;
    }
    
    if(a==0 || b==0){
      cout << max(a,b);
    }
  }
}

