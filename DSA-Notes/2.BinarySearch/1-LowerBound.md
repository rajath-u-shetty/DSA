---
id: LowerBound
aliases: 
tags: 
area: Algorithms
project: DSA-Notes
---
#### On 30-05-2024 at 21:05

# The Problem Statement

Find the first element that is greater than erqual to the target element.
`int arr = [3,5,8,15,19,19,19]`

* if target = 9 -> lower_bound = 3
* t=16 -> lb = 4
* t=20 -> lb = 7 // 7 does not exist but is an hypothetical value
* t = 18 -> lb = 5 // first smallest index
## Brute Force Approach

```cpp
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

//OR

lb = lower_bound(arr.begin(), arr.end(), x);

TC - O(log (base)2 N)

