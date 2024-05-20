---
id: Untitled
aliases: 
tags: 
area: Algorithms
project: DSA-Notes
---
#### On 19-05-2024 at 19:45

# The Problem Statement

this has 2 varieties:

 An array of integers and a target value will be given and we have determine if there exists a sum of 2 numbers which is equal to target 
 
 if target = 14
`int arr = {2,6,5,8,11};`

then sum = 6 + 8
return yes or no if sum is possible

In second variety the sum is possible and u have to return the position of the two numbers.
## Brute Force Approach

`int arr = {2,6,5,8,11};`

we can compare every element with other elements like linear search to get the sum. the slight improvement to it could be that when we check the first two elements 2 and 6 then when i moves to 6 theres no point of checking it with 2 so we can do `j=i+1`

```
for(int i=0;i<n;i++){
	for(int j=i+1;j<n;j++){
		if(arr[i] + arr[j] == k){
		cout >> "true";
		cout >> i >> j ;
		}
	}
}
```
TC - `n^2`

## Better Approach

#### Hashing

we can use hashmap for this where we can store the element as the key and its index as the value

```
map<int, int> mpp;
for(int i=0;i<n;i++){
	int a = arr[i];
	int rem = target - a;
	
	if(mpp.find(rem) != mpp.end()){
	return "YES";// return (mpp[rem], i)
	}
	
	mpp[a] = i;
}
```

`int arr = {2,6,5,8,11};`

first it checks 2 and checks if target - 2 = 12 is present in hashmap..NO then it stores [2,0] in hashmap.

next it moves to 6 and check if 8 is in hashmap...NO then stores [6,1]
next.. [5,2]
when it moves to 8 then 6 is already in hashmap so it return their index

TC - O(N*logn)
SC - O(N) //for hashmap
## Optimal Approach

we can sort the array and then use two pointer approach to solve the problem.

```
int left = 0,right = n-1;
    while(left < right){
    int sum = arr[left] + arr[right]
      if( == target ){
        cout << "YES";
        break;
      }else if(sum < target){
        left++;
      }else {
        right--;
      }
    }
```

left points to first element, right to the last. if their sum = target then return. if sum if < target then we need to increase the value of sum so we do left++. and if its greater the we reduce sum by moving right--.

TC - O(N) + O(nlogn)//for sorting
SC - O(1)
