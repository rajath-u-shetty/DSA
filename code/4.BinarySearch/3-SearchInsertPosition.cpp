#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> arr = {1, 2, 3, 5, 6, 8, 10, 11, 14, 15};
  int n = arr.size();

  int target = 11;
  int low = 0, high = n - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] == target) {
      cout << mid;
      break;
    }
    if (arr[mid] > target) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  if (low > high) {
    cout << "Element not found";
  }
  return 0;
}

