#include <iostream>
#include <string>
#include <vector>
using namespace std;

// int minDecide(vector<int> arr, int mid, int k) {
//   int sum = 0;
//   int count = 0;
//   for (int i = 0; i < arr.size(); i++) {
//     if (sum + arr[i] < mid) {
//       sum += arr[i];
//     } else {
//       count++;
//       sum = 0;
//       sum += arr[i];
//     }
//   }
//   if (sum > 0 && sum < mid) {
//     count++;
//   }
//   return count;
// }
//
// int main() {
//   vector<int> arr = {10, 20, 30, 40};
//   int n = arr.size();
//   int k = 2;
//   int sum, maxi;
//   for (int i = 0; i < n; i++) {
//     sum += arr[i];
//     maxi = 0;
//     if (arr[i] > maxi) {
//       maxi = arr[i];
//     }
//   }
//   int low = maxi;
//   int high = sum;
//   int mid, val;
//   while (low <= high) {
//     mid = (low + high) / 2;
//     val = minDecide(arr, mid, k);
//     if (val > k) {
//       low = mid + 1;
//     } else {
//       high = mid - 1;
//     }
//   }
//   cout << mid;
//   cout << val;
// }
//

bool isValid(vector<int> arr, int k, int mid, int maxi) {
  int sum = 0;
  int count = 0;
  for (int i = 0; i < arr.size(); i++) {
    sum += arr[i];
    if(sum + arr[i] > mid){
      count++;
      sum = arr[i];
    }
    if(count > k){
      return false;
    }
  }

  return true;
}

int main() {
  vector<int> arr = {10, 20, 30, 40};
  int n = arr.size();
  int k = 2;
  int sum, maxi;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
    maxi = 0;
    if (arr[i] > maxi) {
      maxi = arr[i];
    }
  }
  int low = maxi;
  int high = sum;
  int mid, res;
  if (arr.size() > k) {
    cout << false;
  }
  while (low <= high) {
    mid = low + (high - low) / 2;
    if (isValid(arr, k, mid, high) == true) {
      res = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
}
