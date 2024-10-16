#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int arr[5] = {2, 3, 4, 7, 11};
  int n = arr.size();
  int low = 0;
  int high = n - 1;
  int k = 5;
  while (low <= high) {
    int mid = (low + high) / 2;
    int missing = arr[mid] - (mid + 1);
    if (missing < k) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return high + k + 1;
}
