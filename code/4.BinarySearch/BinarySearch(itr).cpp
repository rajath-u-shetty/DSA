#include <iostream>
#include<vector>

using namespace std;

int main() {
  vector<int> arr = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};
  int n = arr.size();
  int low = 0;
  int high = n - 1;
  int target = 11;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] == target)
      return -1;
    if (target < arr[mid]) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return 0;
}
