#include <iostream>
#include <string>
#include <vector>

using namespace std;
// the array can be in ascending order or in descending order

int main() {
  vector<int> arr = {20, 17, 15, 14, 12, 11, 8, 6, 3, 1};
  int n = arr.size();
  int low = 0;
  int high = n - 1;
  int x = 3;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] == x)
      cout << x;
    if (arr[low] < arr[high]) {
      if (arr[mid] > x) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    } else {
      if (arr[mid] > x) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
  }
  return 0;
}
