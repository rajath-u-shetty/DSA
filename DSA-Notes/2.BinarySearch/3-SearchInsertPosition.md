---
id: 3-SearchInsertPosition
aliases: 
tags: 
area: Algorithms
project: DSA-Notes
---
#### On 30-05-2024 at 21:38

# The Problem Statement
## Brute Force Approach

In a sorted array if the element is present the return its index and if not then return the index where it has to be inserted.

```cpp
//#include <iostream>
//#include <vector>

//using namespace std;

//int main() {
//  vector<int> arr = {1, 2, 3, 5, 6, 8, 10, 11, 14, 15};
//  int n = arr.size();

//  int target = 11;
// int low = 0, high = n - 1;
//  while (low <= high) {
//    int mid = (low + high) / 2;
//    if (arr[mid] == target)
//      cout << mid;
//    if(arr[mid] > target){
//      high=mid-1;
//    }else{ 
//      low = mid+1;
//    }
//  }
//  if(low>high){
//    cout << low;
//  }
//  return 0;
//}

```

```cpp
//this is same as lower bound
int low = 0,
int high = n-1;
int ans = n; // last index
while(low <= high){
	int mid = (low+high)/2;
	if(arr[mid] >= target){
		ans = mid;
		high = mid - 1;
	}else{
		low = mid + 1;
	}
}
```