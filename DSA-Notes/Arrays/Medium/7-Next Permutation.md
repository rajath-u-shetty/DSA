---
id: 7-Next Permutation
aliases: 
tags: 
area: Algorithms
project: DSA-Notes
---
#### On 23-05-2024 at 00:31

# The Problem Statement
## Brute Force Approach

1. generate all possible combinations in a sorted manner
2. do a linear search to find the given question
3. the next index is the required output.

TC = O(N! * N)
## Better Approach

using inbuilt STL library. next_permutation(a.begin(), a.end())
## Optimal Approach

1. Longer prefix match
		eg.`arr = [2, 1, 5, 4, 3, 0, 0]`
		we check from that last index in an incremental order to find a greater number.
		
	```cpp
[2 1 5 4 3 0 0]// changing last two digits makes no difference
		[2 1 5 4 0 3 0]// similar with the last 3
		[2 5 1 4 3 0 0]// we can get greater combination only if we move the last 6 digits.
		find the breakpoint where the right element is greater than left one.
		the condidtion is arr[i] < arr[i+1] //which is not true till number 1 when coming from last.
		```
		

```cpp
in arr =  [1,2,3,4,5]
//the breakpoint is at the last position
[1,2,3,5,4] //optimal answer
```
2. in order to find the immediate next combination we have to find a number thats greater than 1 but is the smallest among others.
	`[2 3 _ _ _ _ _]` fill up the remaing places.
	`[2 3 0 0 1 4 5]` this is the closest one.
3. arrange the elements in ascending order.

* [2 1 _ _ _ _ _] // 5 4 3 0 0
* here after the break point we have to arrange the numbers in ascending order
* we swap 1 and 3
* [ 2 3 _ _ _ _ _ ] // 5 4 1 0 0
* this is in descending order so reverse it 

code :
```cpp
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
```

TC - O(3N)
SC - O(1)