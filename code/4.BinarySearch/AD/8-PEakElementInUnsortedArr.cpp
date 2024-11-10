#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<int> arr = {5, 10, 20, 15};
  int n = arr.size();
  int low = 1;
  int high = n - 2;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[0] > arr[1])
      cout << arr[0];
    if (arr[n - 1] > arr[n - 2])
      cout << arr[n - 1];
    if (mid > 0 && mid < n - 1) {
      if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid - 1]) {
        return mid;
      } else if (arr[mid] > arr[mid - 1]) {
        low = mid + 1;
      } else if (arr[mid] > arr[mid + 1]) {
        high = mid - 1;
      }
    }
  }
  return 0;
}
