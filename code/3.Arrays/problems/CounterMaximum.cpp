#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here␍
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        int arr[n];
        map<int, int> mpp;
        for(int i=0;i<n;i++){
            cin >> arr[i];
            mpp[arr[i]]++;
        }
        
        int maxi = INT_MIN;
        int val=0;
    for(auto it : mpp){
            if(it.second > maxi)
                maxi = it.second;
                val = it.first;
            }       
        }
        cout << val << " " << maxi << endl;
    }
    
}


// Count of Maximum
// Given an array 
// A
// A of length 
// N
// N, your task is to find the element which repeats in 
// A
// A maximum number of times as well as the corresponding count. In case of ties, choose the smaller element first.
//
// Input Format
// First line of input contains an integer 
// T
// T, denoting the number of test cases. Then follows description of 
// T
// T cases. Each case begins with a single integer 
// N
// N, the length of 
// A
// A. Then follow 
// N
// N space separated integers in next line.
//
// Output Format
// For each test case, output two space separated integers 
// V
// V & 
// C
// C. 
// V
// V is the value which occurs maximum number of times and 
// C
// C is its count.
//
// Constraints
// 1
// ≤
// T
// ≤
// 100
// 1≤T≤100
// 1
// ≤
// N
// ≤
// 100
// 1≤N≤100
// For all i in [1..N] : 
// 1
// ≤
// A
// [
// i
// ]
// ≤
// 10000
// 1≤A[i]≤10000
// Sample 1:
// Input
// Output
// 2
// 5
// 1 2 3 2 5
// 6
// 1 2 2 1 1 2
// 2 2
// 1 3
// Explanation:
// In first case 2 occurs twice whereas all other elements occur only once. In second case, both 1 and 2 occur 3 times but 1 is smaller than 2.
