#include <bits/stdc++.h>
using namespace std;
//if the elements's previous or next element is same then remove it

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> frames(n);

        for (int i = 0; i < n; i++) {
            cin >> frames[i];
        }

        int minFrames = n;
        for (int i = 0; i < n - 1; i++) {
            if (frames[i] == frames[i + 1]) {
                minFrames--;
            }
        }

        cout << minFrames << endl;
    }

    return 0;
}

//
//
// Compress the Video
// Chef recorded a video explaining his favorite recipe. However, the size of the video is too large to upload on the internet. He wants to compress the video so that it has the minimum size possible.
//
// Chef's video has 
// N
// N frames initially. The value of the 
// i
// t
// h
// i 
// th
//   frame is 
// A
// i
// A 
// i
// ​
//  . Chef can do the following type of operation any number of times:
//
// Choose an index 
// i
// i 
// (
// 1
// ≤
// i
// ≤
// N
// )
// (1≤i≤N) such that the value of the 
// i
// t
// h
// i 
// th
//   frame is equal to the value of either of its neighbors and remove the 
// i
// t
// h
// i 
// th
//   frame.
// Find the minimum number of frames Chef can achieve.
//
// Input Format
// First line will contain 
// T
// T, the number of test cases. Then the test cases follow.
// The first line of each test case contains a single integer 
// N
// N - the number of frames initially.
// The second line contains 
// N
// N space-separated integers, 
// A
// 1
// ,
// A
// 2
// ,
// …
// ,
// A
// N
// A 
// 1
// ​
//  ,A 
// 2
// ​
//  ,…,A 
// N
// ​
//   - the values of the frames.
// Output Format
// For each test case, output in a single line the minimum number of frames Chef can achieve.
//
// Constraints
// 1
// ≤
// T
// ≤
// 1000
// 1≤T≤1000
// 1
// ≤
// N
// ≤
// 1
// 0
// 5
// 1≤N≤10 
// 5
//  
// 1
// ≤
// A
// i
// ≤
// 1
// 0
// 6
// 1≤A 
// i
// ​
//  ≤10 
// 6
//  
// Sum of 
// N
// N over all test cases does not exceed 
// 2
// ⋅
// 1
// 0
// 5
// 2⋅10 
// 5
//  .
// Sample 1:
// Input
// Output
// 4
// 1
// 5
// 2
// 1 1
// 3
// 1 2 3
// 4
// 2 1 2 2
// 1
// 1
// 3
// 3
// Explanation:
// Test case 
// 1
// 1: There is only one frame with value 
// 5
// 5. Since there are no neighbors, Chef won't remove any frame and the minimum number of frames Chef can achieve is 
// 1
// 1.
//
// Test case 
// 2
// 2: There are two frames where both frames have value 
// 1
// 1. Chef can remove the first frame as the value of the first frame is equal to that of the second frame. The remaining frames have values 
// [
// 1
// ]
// [1]. The minimum number of frames Chef can achieve is 
// 1
// 1.
//
// Test case 
// 3
// 3: There are 
// 3
// 3 frames. All frames have distinct values. Thus, the minimum number of frames Chef can achieve is 
// 3
// 3.
//
// Test case 
// 4
// 4: Chef can remove the fourth frame as the value of the fourth frame is equal to that of the third frame. The remaining frames have values 
// [
// 2
// ,
// 1
// ,
// 2
// ]
// [2,1,2]. Thus, the minimum number of frames Chef can achieve is 
// 3
// 3.
