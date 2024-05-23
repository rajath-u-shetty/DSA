#include <climits>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
  vector<int> arr = {};
  int n = arr.size();

  // BRUTE
  // for (int i = 0; i < n; i++) {
  //   int count = 0;
  //   int x = arr[i];
  //   while (ls(arr, x + 1) == true) {
  //     x = x + 1;
  //     count++;
  //   }
  // }
  
  // BETTER
  // sort(arr.begin(), arr.end());
  // int lastSmaller = INT_MIN;
  // int count = 0;
  // int longest = 1;
  // for (int i = 0; i < n; i++) {
  //   if (arr[i] - 1 == lastSmaller) {
  //     count += 1;
  //     lastSmaller = arr[i];
  //   } else if (lastSmaller != arr[i]) {
  //     count = 1;
  //     lastSmaller = arr[i];
  //   }
  // }

  // OPTIMAL
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
  return 0;
}
