---
id: 6-Rearrang By Sign
aliases: 
tags: 
area: Algorithms
project: DSA-Notes
---
#### On 21-05-2024 at 23:05

# The Problem Statement
## Brute Force Approach
<<<<<<< Updated upstream
## Better Approach
## Optimal Approach
=======

```cpp
vector<int> posArr;
  vector<int> negArr;
  for(int i=0;i<n;i++){
    if(arr[i] >= 0){
      posArr.emplace_back(arr[i]);
    }else{
      negArr.emplace_back(arr[i]);
    }
  }

  for(int i=0;i<n/2;i++){
    arr[i*2] = posArr[i];
    arr[i*2+1] = negArr[i];
  }
```

Here we are creating two new vectors and storing postive and negative values seperately. Since positive numbers occur at even postion and negative at odd we can do arr[2*i] to access onlllly even positions and arr[2*i+1] for add. i<n/2 bcz each array has only half of the numbers.

TC - O(N) + O(N/2)
SP - O(N)

## Otiiimal Approach


here instead of taking two seperate arrays we take an answer array and in even postion store positive vals and in odd positions negative values.
```cpp
 int posIndex = 0, negIndex = 1;
  vector<int> ansArr;
  for (int i = 0; i < n; i++) {
    if (arr[i] < 0) {
      ansArr[negIndex] = arr[i];
      negIndex += 2;
    } else {
      ansArr[posIndex] = arr[i];
      posIndex += 2;
    }
```
TC - O(N)
SC - O(N)


## Variety 2

Here the number of positive and negative numbers are not same, if any number is left then ppput it in end.

we apply the bruute force method from previos problem. wehere we store positive and negative numbers in seperate arrays. 
`arr = {1, 2, -4, -5, 3, 6}` here the number of positive elements are greater than negative.
`pos arr = [1, 2, 3, 6]` and `neg arr = [-4, -5]`

```cpp
vector<int> pos, neg;
  for (int i = 0; i < n;i++) {
    if (arr[i] < 0) {
      neg.push_back(arr[i]);
    } else {
      pos.push_back(arr[i]);
    }
  }

  if (pos.size() > neg.size()) {
    // pos is greater than neg
    //we store elements till the size of negative array only i.e 2
    // hence 4 elements are stored i.e 2 pos and 2 neg
    for (int i = 0; i < neg.size(); i++) {
      arr[i * 2] = pos[i];
      arr[i * 2 + 1] = neg[i];
    }
    
    // index is the number of elements ine the arr i.e 4 which is double of neg arr size
    int index = neg.size() * 2; // 2*2=4
    for (int i = neg.size(); i < pos.size(); i++) { //start from 2 to 4 i.e size of pos arr
      arr[index] = pos[i];
      index++;
    }
  } else {
    for (int i = 0; i < pos.size(); i++) {
      arr[i * 2] = pos[i];
      arr[i * 2 + 1] = neg[i];
    }

    int index = pos.size() * 2;
    for (int i = pos.size(); i < neg.size(); i++) {
      arr[index] = neg[i];
      index++;
    }

```

TC - O(N) + O(min,max) + O(leftOver) = O(2N)          
SC - O(N)
>>>>>>> Stashed changes
