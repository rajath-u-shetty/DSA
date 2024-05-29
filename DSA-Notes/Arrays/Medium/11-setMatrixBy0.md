---
id: 11-setMatrixBy0
aliases: []
tags: []
area: Algorithms
project: DSA-Notes
---
#### On 28-05-2024 at 23:50

# The Problem Statement

an n*n array will be given and we have to rotate it by 90 degree's

[1 2 3       [7 4 1 
 4 5 6   ->   8 5 2 
 7 8 9]       9 6 3]

*  _ ,J         J, _
* [0,0] -> [0,3]
* [0,1] -> [1,3]
* [0,2] -> [2,3]
* here j pattern is same


## Brute Force Approach

```cpp
vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
int n = arr.size(); 
vector<vector<int>> ans(n, vector<int>(n));
for (int i = 0; i < n; i++){
	for (int j = 0; j < n; j++){
		 ans[j][n - i - 1] = arr[i][j];
	}
}
```

TC - O(N^2)
SC - O(N^2)
## Optimal Approach


*  the first step is to find the transpose of the matrix i.e interchanging rows and columns 
* next is to reverse each row

[1 2 3        [1 4 7         [ 7 4 1
 4 5 6   ->  2 5 8.  ->    8 5 2
 7 8 9]        3 6 9]         9 6 3]

```cpp
int vector<int> arr = {};
  int n = arr.size();
  for(int i=0;i<n;i++){//O(n/2)
    for(int j=i+1;j<n;j++){// O(n/2)
      swap(arr[i][j], arr[j][i]);
    }
  }
  

  for(int i=0;i<n;i++){//O(n*n/2)
    reverse(arr[i].begin(), arr[].end());
  }
  return 0;
}
```

TC - O(n*n/2)
