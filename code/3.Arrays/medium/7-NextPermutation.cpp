#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

int main() {
  int index = -1;
  vector<int> arr;
  arr = {2, 1, 5, 4, 3, 0, 0};
  int n = arr.size();
  for (int i = n - 2; i >= 0; i--) {
    if (arr[i] < arr[i + 1]) {
      index = i;
      break;
    }
  }

  if (index == -1) {
    reverse(arr.begin(), arr.end());
  }

  for (int i = n - 1; i >= index; i--) {
    if (arr[i] > arr[index]) {
      swap(arr[index], arr[i]);
      break;
    }
  }

  reverse(arr.begin()+index+1, arr.end());

  return 0;
}
