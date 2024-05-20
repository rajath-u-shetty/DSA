---
id: 3-MajorityElement
aliases: 
tags: 
area: Algorithms
project: DSA-Notes
---
#### On 20-05-2024 at 00:13

# The Problem Statement

if count of a number is grater than n/2
## Brute Force Approach

```
[2,2,3,3,1,2,2]
for(int i=0;i<n;i++){
	cnt = 0;
		for(int j=0;j<n;j++){
		if(arr[j] == arr[i]){
		cnt++;
		}
	}
	if(cnt > n/2) return a[i];
}
```
## Better Approach

using Hashing

```
map<int, int> mpp;
for(int i=0;i<n;i++){
	mpp[arr[i]++];
}

for(auto it: mpp){
	if(it.second() > (n / 2)){
		return it.first()
	}
}
```
TC - O(nlogn) = O(N)
SC - O(N)
## Optimal Approach


```
int cnt = 0;
int ele;
for(int i=0;i<n;i++){
	if(cnt==0){
		cnt=1;
		ele=arr[i];
	}else if(arr[i] == ele){
		cnt++;
	}else{
		cnt--;
	}
}


//verification
int cnt1=0;
for(int i=0;i<n;i++){
if(arr[i] = ele) cnt1++;
//the last assigned element is counted
}
if(cnt1 > n/2) return ele;
```

TC - O(N) + O(N) //verfication
SC = O(1)