#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int floor(vector<int>& arr, int n, int low, int high, int target) {
    int ans = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] <= target) {
            ans = arr[mid];
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int ceil(vector<int>& arr, int n, int low, int high, int target) {
    int ans = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] >= target) {
            ans = arr[mid];
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(7);
    arr.push_back(8);
    arr.push_back(9);
    int n = arr.size();
    int target = 6;
    int low = 0;
    int high = n - 1;
    int ans1 = floor(arr, n, low, high, target);
    int ans2 = ceil(arr, n, low, high, target);
    cout << ans1 << " " << ans2;
    return 0;
}
