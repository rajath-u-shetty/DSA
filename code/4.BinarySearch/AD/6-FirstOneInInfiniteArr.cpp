#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<int> arr = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  // 15
  int n = arr.size();
  int low = 0;
  int high = 1;
  while (low <= high) {
    if (arr[high] < 1) {
      low = high;
      high = high * 2;
    }
    if (arr[high] == 1) {
      break;
    }
  }
  cout << low;
  cout << high;
  int ans = 0;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] == 1) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  cout << ans;
}
