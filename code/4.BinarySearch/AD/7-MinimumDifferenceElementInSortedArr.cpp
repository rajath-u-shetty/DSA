#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<int> arr = {1, 3, 4, 5, 7, 10, 15};
  int k = 12;
  int n = arr.size();
  int low = 0;
  int high = n-1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] == k) {
      cout << mid || 0;
    }
    if (arr[mid] > k) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  if (k - arr[high] > k - arr[low]) {
    return k - arr[high];
  } else {
    return k - arr[low];
  }
}
