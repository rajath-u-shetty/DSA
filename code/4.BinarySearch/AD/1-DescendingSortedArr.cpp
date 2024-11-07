#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<int> arr = {20, 17, 15, 14, 12, 11, 8, 6, 3, 1};
  int n = arr.size();
  int low = 0;
  int high = n - 1;
  int x = 3;
  while(low <= high){
    int mid = low + (high - low) / 2;
    if (arr[mid] == x) {
      return mid;
    }
    if (arr[mid] > x) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return 0;
}
