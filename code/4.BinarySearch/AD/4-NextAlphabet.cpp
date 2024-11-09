#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<int> arr = {1, 3, 4, 5, 7, 9, 11};
  int n = arr.size();
  int low = 0;
  int high = n - 1;
  int mid = 0;
  int x = 4;
  int ans;
  while (low <= high) {
    mid = low + (high - low) / 2;
    if (arr[mid] >= x) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  if (arr[mid] == x) {
    cout << ans + 1;
  } else {
    cout << ans;
  }
  return 0;
}

