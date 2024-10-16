#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool canwePlace(vector<int> &arr, int dist, int cows) {
  int cntCows = 1;
  int last = arr[0];
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] - last >= dist) {
      cntCows++;
      last = arr[i];
    }
    if (cntCows >= cows)
      return true;
  }
  return false;
}

int main() {
  vector<int> arr = {0, 3, 4, 7, 10, 9};
  sort(arr.begin(), arr.end());
  int n = arr.size();
  int low = 1;
  int k = 4;
  int high = arr[n - 1] - arr[0];
  while (low <= high) {
    int mid = (low + high) / 2;
    if (canwePlace(arr, mid, k) == true) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return high;
}
