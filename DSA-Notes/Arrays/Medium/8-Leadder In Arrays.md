---
id: 8-Leadder In Arrays
aliases: 
tags: 
area: Algorithms
project: DSA-Notes
---
#### On 23-05-2024 at 02:46

# The Problem Statement

if all the elements present on the right side of an element then it is called as leader.
 * arr = [10, 22, 12, 3, 0, 6]
 * here 22, 12 and 6 are called leader elements

## Brute Force Approach

```cpp
for(int i=0;i<n;i++){
	bool leader = true;
	for(int j=i+1;j<n;j++){
		if(arr[j] > arr[i]){
			leader = false;
			break;
		}
	}
	if(leader == true) arr.push_back(arr[i]);
}
```
## Optimal Approach

* if we can prove that arr[i] is greater than the max element on the right then we can conclude that arr[i] is leader.
* arr = [10, 22, 12, 3, 0, 6] here if we prove 12 is greater 6 the 12 is leader.

```cpp
 int maxi = INT_MIN;
  for (int i = n - 1; i >= 0; i--) {
    if (arr[i] > maxi) {
      arr.push_back(arr[i]);
    }
    maxi = max(maxi, arr[i]);
  }
  //sort it if they ask in ascending order
```

TC - O(N)
O(nlogn) if they ask sorting
