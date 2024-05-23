---
id: 9-LongestConsecutiveSequence
aliases: 
tags: 
area: Algorithms
project: DSA-Notes
---
#### On 24-05-2024 at 00:43

# The Problem Statement

re-arrange the given array and find the length of the max consecutive numbers.
`arr={102, 4, 100, 1, 101, 3, 2, 1, 1}`
## Brute Force Approach

we use linear search to check is the next number exists for eaxh number

```cpp
for (int i = 0; i < n; i++) {
     int count = 0;
     int x = arr[i];
     while (ls(arr, x + 1) == true) {
       x = x + 1;
       count++;
     }
}
 
```

TC - O(N^2)
SC - O(1)
## Better Approach

* first sort the arr so that it can be ascending order
* arr = [1, 1, 1, 2, 2, 3, 3 , 4, 4, 100, 101, 102, 102]
* longest = [1,2,3,4]
* create a variable lastSmaller whose value is int-min
* in first iteration arr[0] the condition checks if the previous number of the number exists which is flase for first element. count is initialized and lastSmall  bcms 1
* in second itr, Number != lastnumber so count is re-intialized
* when loop reaches 2 the arr[i] - 1 == lastSmaller so counter increses. this happens in 3 and 4 also.

```cpp
sort(arr.begin(), arr.end());
int lastSmaller = INT_MIN;
int count = 0;
int longest = 1;
for (int i = 0; i < n; i++) {
	 if (arr[i] - 1 == lastSmaller) {
	   count += 1;
	   lastSmaller = arr[i];
	 } else if (lastSmaller != arr[i]) {
	   count = 1;
	   lastSmaller = arr[i];
	 }
 }
```

TC - O(nlogn) + O(n)
SC. - O(1)
## Optimal Approach

* first we add all the elements into an unordered set so that only unique elements remain.
* |           102         |
* |               4         |
* |            100        |
* |                1         |
* |             101        |
* |                3         |
* |_ _ _ _ _  2 _  _ |
* we run for loop to check for elements if they are the first element of the sequence
* first 102 -> 101 lesser than 102 exists so we do check.
* 4 -> 3 exists.
* 100 -> 99 does not exits and greater elements 101 exists so we check all the consecutive sequnce after 100.
* same with 1 as its the first number and 0 does not exist
* no for 103, 3, and 2

```cpp
if (n == 0)
    return 0;
  int longest = 1;
  unordered_set<int> st;
  for (int i = 0; i < n; i++) {
    st.insert(arr[i]);
  }

  for (auto it : st) {
    if (st.find(it - 1) == st.end()) {
      int count = 1;
      int x = it;
      while (st.find(x + 1) != st.end()) {
        x++;
        count++;
      }
      longest = max(longest, count);
    }
  }
```

TC - O(N) + O(N * X)
SC - O(N)// if all elements are unique