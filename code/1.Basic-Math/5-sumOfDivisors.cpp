#include <iostream>
using namespace std;


int main(){
  int sum=0;
  int n;
  cin >> n;
  // for(int i=1;i<=n;i++){
  //   for(int j=1;j<=i;j++){
  //     if(i%j==0){
  //       sum = sum + i;
  //     }
  //   }
  // }

  
  for(int i=1;i*i<=n;i++){
    if(n%i==0){
      sum=sum+i;
    }
    
    if(i != n/i){
      sum = sum + n/i;
    }
  }
  
    cout << sum;
}

