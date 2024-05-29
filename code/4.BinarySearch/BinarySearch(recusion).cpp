#include <iostream>
#include <vector>

using namespace std;

int BinarySearch(int arr[], int low, int high, int target) {
  if(low >= high) return;
  int mid = (low + high)/2;
  if (arr[mid] == target)
    return -1;
  if (target <= arr[mid])
    BinarySearch(arr,low,mid+1,target);
  else
    BinarySearch(arr,mid-1,high,target);
}

int main() {
  vector<int> arr = {};
  int n = arr.size();
  int low = 0;
  int high = n - 1;
  int target = 11;
  BinarySearch(arr, low, high, target);
  return 0;
}
