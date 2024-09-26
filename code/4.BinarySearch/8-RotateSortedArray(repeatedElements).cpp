#include <iostream>
#include <vector>

using namespace std;

int searchInARotatedSortedArrayII(vector<int> &arr, int target) {
  int n = arr.size();
  int low = 0;
  int high = n - 1;
  int mid;
  while (low <= high) {
    mid = (low + high) / 2;
    if (arr[mid] == target) {return mid;}
    //the only diff b/w previous i.r no repeated code is the below condidtion   
    //if the elements in high low and mid is same the it shrinks the search space
    if(arr[mid] == arr[low] == arr[high]){
      low++;
      high--;
      continue;
    }
    if (arr[mid] <= arr[high]) {
      if (arr[mid] <= target && target <= arr[high]) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    } else {
      if (arr[low] <= target && target <= arr[mid]) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
  }
  return -1;
}

int main() {
  vector<int> arr = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
  int k = 7;
  int ans = searchInARotatedSortedArrayII(arr, k);
  cout << ans;
  if (!ans)
    cout << "Target is not present.\n";
  else
    cout << "Target is present in the array.\n";
  return 0;
}

