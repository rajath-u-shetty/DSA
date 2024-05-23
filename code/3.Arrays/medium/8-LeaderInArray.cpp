#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> arr;
  arr = {10, 22, 12, 3, 0, 6};
  int n = arr.size();

  // BRUTE
  //   for (int i = 0; i < n; i++) {
  //     bool leader = true;
  //     for (int j = i + 1; j < n; j++) {
  //       if (arr[j] > arr[i]) {
  //         leader = false;
  //         break;
  //       }
  //     }
  //     if (leader == true)
  //       arr.push_back(arr[i]);
  //   }

  // OPTIMALL
  int maxi = INT_MIN;
  for (int i = n - 1; i >= 0; i--) {
    if (arr[i] > maxi) {
      arr.push_back(arr[i]);
    }
    maxi = max(maxi, arr[i]);
  }
  return 0;
}
