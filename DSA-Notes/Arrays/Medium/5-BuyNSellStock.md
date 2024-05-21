---
id: 5-BuyNSellStock
aliases: []
tags: []
area: Algorithms
project: DSA-Notes
---
#### On 21-05-2024 at 20:06

# The Problem Statement

`arr={7, 1, 5, 3, 6, 4}`
we have an array where each number represents the price os a stock. The aim is to buy the stock at its lowest point and sell it at the heighest with max profit.

## Optimal Approach

Dp based question, DP is basically remebering the pas, here we are remembering arr[i] in mini.

```cpp
vector<int> arr;
  int n = arr.size();
  arr = {7, 1, 5, 3, 6, 4};
  int mini = arr[0];
  int profit = 0, cost = 0;
  for (int i = 1; i < n; i++) {
    cost = arr[i] - cost;
    profit = max(cost, profit);
    mini = min(mini, arr[i]);
    // here we are remebering the value of mini throughout the loop  
  }
  cout << profit;
  return 0;
}
 
```
