#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int n = arr.size();
  int low = 0;
  int high = 1;
  int x = 4;
  int ans;
  while (low <= high) {
    if (arr[high] < x) {
      low = high;
      high *= 2;
    }
    if (arr[high] > x) {
      break;
    }
  }
  cout << low;
  cout << high;
  while (low <= 2) {
    int mid = (low + high) / 2;
    if (arr[mid] == x)
      cout << mid;
    if (arr[mid] < x) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
}
