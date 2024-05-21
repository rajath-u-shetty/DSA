#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> arr;
  int n = arr.size();
  arr = {7, 1, 5, 3, 6, 4};
  int mini = arr[0];
  int profit = 0, cost = 0;
  for (int i = 1; i < n; i++) {
    cost = arr[i] - cost;
    profit = max(cost, profit);
    mini = min(mini, arr[i]);
  }
  cout << profit;
  return 0;
}
