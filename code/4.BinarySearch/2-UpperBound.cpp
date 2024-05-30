#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> arr = {};
  int n = arr.size();

  int ans = n;
  int low = 0, high = n - 1;
  int target = 11;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] > target) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return 0;
}
