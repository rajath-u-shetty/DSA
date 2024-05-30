---
id: 2-upperBound
aliases: 
tags: 
area: Algorithms
project: DSA-Notes
---
#### On 30-05-2024 at 21:22

# The Problem Statement

find the first index that is greater than the target
## Brute Force Approach

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> arr = {};
  int n = arr.size();

  int ans = n;
  int low = 0, high = n - 1;
  int target = 11;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] > target) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return 0;
}

```

up = upper_bound(arr.begin(), arr.end(), x)