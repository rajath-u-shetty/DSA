---
id: 4-kadene's Algorithm
aliases: 
tags: 
area: Algorithms
project: DSA-Notes
---
#### On 20-05-2024 at 01:51

# The Problem Statement

Find the maximum sum of the sub-array 
`arr = {-2, -3, 4, -1, -2, 1, 5, -3};`
eg.  ans = 4 + (-1) + (-2) + 1 + 5 = 7. is the largest sub array with max sum


## Brute Force Approach

```cpp
  int maxi = 0;
   for(int i=0;i<n;i++){
     for(int j=i;j<n;j++){
       int sum = 0;
       for(int k=i;k<j;k++){
         sum += arr[k];
         maxi = max(sum, max);
       }
     }
 }
```

TC - O(n^3)

## Better Approach

```cpp
 int maxi = 0;
      for(int i=0;i<n;i++){
      for(int j=1;j<n;j++){
        int sum = 0;
        for(int k=0;k<j;k++){
          sum += arr[j];
          maxi = max(sum, max);
        }
      }
    }

```
 TC - O(n^2)

## Optimal Approach

kadene's algorithm


`arr = {-2, -3, 4, -1, -2, 1, 5, -3};`

1. here on this example first sum = assigned to -2,since its lessser than 0 sum bcms 0 and maxi is -2.
2. next -3 which is also lesser than than 0, hence sum is 0.
3. next is 4 which i sgrter than 0 and hence next ele is added

```cpp
int sum = 0;
  int maxi = INT_MIN;
  for(int i=0;i<n;i++){
    sum += arr[i];
    if(sum >  maxi){
       maxi = sum;
    }
    if(sum < 0){
      sum = 0;
    }
  }
```


follow up question - print sub-arr with max - sum

```cpp
int sum = 0;
  int maxi = INT_MIN;
  for(int i=0;i<n;i++){
  if(sum == 0 ) start = i; //everytime sum bcms 0 we assign the index to start
  
    sum += arr[i];
    if(sum >  maxi){
       maxi = sum;
       arrStart = start,
       arrEnd = i;
    }
    
    if(sum < 0){
      sum = 0;
    }
  }
```