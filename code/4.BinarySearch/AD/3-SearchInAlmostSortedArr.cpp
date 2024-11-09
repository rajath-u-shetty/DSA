#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() 
{
  vector<int> arr = {10, 3, 40, 20, 50, 80, 70};
  int n = arr.size();
  int low = 0;
  int high = n - 1;
  int x = 40;
  while(low <= high){
    int mid = low + (high - low) / 2;
    if(arr[mid] == x){
      cout << mid;
    }
    if(mid-1 > low && arr[mid-1] == x){
      cout << mid-1;
    }
    if(mid+1 < high && arr[mid+1] == x){
      cout << mid+1;
    }
    
    if (arr[mid] > x) {
      high = mid - 2;
    }else{
      low = mid + 2;
    }
    
  }
  cout << high;
}
