#include <iostream>
#include <string>
#include <vector>

using namespace std;

int BS(vector<int> &arr, int low, int high, int x) {
  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] == x)
      return mid;
    if (arr[mid] < x) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}

int BinaryDesc(vector<int> &arr, int low, int high, int x) {
  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] == x)
      return mid;
    if (arr[mid] > x)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;
}

int main() {
  vector<int> arr = {5, 10, 20, 15};
  int n = arr.size();
  int low = 1;
  int high = n - 2;
  int mid;
  int x = 10;
  while (low <= high) {
    mid = (low + high) / 2;
    if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
      cout << mid;
    if (arr[0] > arr[1])
      cout << arr[0];
    if (arr[n - 1] > arr[n - 2])
      cout << arr[n - 1];

    if (arr[mid] > arr[mid - 1]) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  int val = BS(arr, low, high, x);
  int val2 = BinaryDesc(arr, low, high, x);
  if (val != -1)
    return val;
  if (val2 != -1)
    return val2;
}
