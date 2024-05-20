---
id: 2-Sorting0,1,2
aliases: 
tags: 
area: Algorithms
project: DSA-Notes
---
#### On 19-05-2024 at 23:06

# The Problem Statement

sorting an array which consists of 0's 1's and 2's
`arr = [0,1,2,0,1,2,1,2,0,0,0,1]`

## Brute Force Approach

using sorting algorithm like merge sort
TC - O(nlogn)
## Better Approach

count the number of 0,1, and 2's and manually update them in the array

```
int cnt0 = 0;
int cnt1 = 0;
int cnt2 = 0;
for(int i=0;i<n;i++){
	if(arr[i] == 0){
		cnt0++;
	}else if(arr[i] == 2){
		cnt1++;
	}else{
		cnt2++;
	}
}
for(int i=0;i<cnt0;i++) arr[i] = 0;
for(int i=cnt0;i<cnt0+cnt1;i++) arr[i] = 1;
for(int i=cnt0+cnt1;i<n;i++) arr[i] = 2;
```
TC - O(2N)
## Optimal Approach

### Dutch National Flag Algorithm

3-pointer approach.

here
1. [0...low-1]=0
2. [low...mid-1]]=1
3. [mid..high]=unsorted
4. [high+1...n-1]=2

`[0,1,1,0,1,2,1,2,0,0,0]`
```
//Alogorithm
if (a[mid] == 0) {
	swap(a[low], a[mid]);
	mid++;
	low++;
}

if(a[mid] == 1) {
	mid++;
}

if( a[mid] == 2){
	swap(a[mid], a[high]);
	high--;
}
```

code 

```
int low=0 ,mid=0 ,high = n-1;
while(mid <= high){
	if(arr[mid] == 0){
		swap(arr[low], arr[mid]);
		low++;
		mid++;
	}
	if(arr[mid] == 1){
		mid++;
	}
	if(arr[mid] == 2){
		swap(arr[mid], arr[high]);
		high--;
	}
}
```

TC - O(N)
SC - O(1)