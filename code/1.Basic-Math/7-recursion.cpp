// #include <iostream>
// using namespace std;

// void f(int l,int r,int arr[]){
//   if(l>=r) return;
//   swap(arr[l], arr[r]);
//   f(l+1, r-1, arr);
// }

// int main(){
//   int n;
//   cin >> n;
//   int arr[n];
  
//   for(int i=0;i<n;i++){
//     cin >> arr[i];
//   }
  
//   f(0, n-1, arr);
  
//   for(int i=0;i<n;i++){
//     cout << arr[i];
//   }
// }

#include <iostream>
using namespace std;

void f(int i,int n,int arr[]){
  if(i>=n/2) return;
  swap(arr[i], arr[n-i-1]);
  f(i+1, n, arr);
}

int main(){
  int n;
  cin >> n;
  int arr[n];
  
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }
  
  f(0, n, arr);
  
  for(int i=0;i<n;i++){
    cout << arr[i];
  }
}

