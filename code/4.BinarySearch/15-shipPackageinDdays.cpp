#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int daysRequired(vector<int> &arr, int capacity) {
  int days = 1;
  int load = 0;
  for (int i = 0; i < arr.size(); i++) {
    if (load + arr[i] > capacity) {
      days += 1;
      load = arr[i];
    } else {
      load += arr[i];
    }
  }
  return days;
}

int main() {
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int n = arr.size();
  int low = 10;
  int high = n * (n + 1) / 2;
  int mid = 0;
  int days = 5;
  while (low <= high) {
    mid = (low + high) / 2;
    int numOfDays = daysRequired(arr, capacity);
    if (numOfDays <= days) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

cout << ans;
}
