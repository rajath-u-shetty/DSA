#include <bits/stdc++.h>
using namespace std;
// if the strength of i'th element is less than x then all the previous indexesnbefore the ith elemt is destroyedd and
// count of the destroyed elemsnts is given

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int ans=0;
        for(int i = n-1; i >= 0; i--)
        {
            if(a[i] < x)
            {
                ans = i+1;
                break;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}



// Bomb the base
// In Chefland, there are 
// N
// N houses numbered from 
// 1
// 1 to 
// N
// N, 
// i
// t
// h
// i 
// th
//   house has a defence system having strength 
// A
// i
// A 
// i
// ​
//  .
//
// Chef suspects a bomb drop on one of the houses very soon. A bomb with attack strength 
// X
// X can destroy the 
// i
// t
// h
// i 
// th
//   house, if the defence system of the 
// i
// t
// h
// i 
// th
//   house 
// A
// i
// A 
// i
// ​
//  , is strictly less than 
// X
// X.
//
// Also, when the 
// i
// t
// h
// i 
// th
//   house is destroyed due to the bomb, all houses with indices 
// j
// j such that 
// 1
// ≤
// j
// <
// i
// 1≤j<i get destroyed as well irrespective of their defence system.
//
// Given one bomb with attack strength 
// X
// X, find the maximum number of houses that can get destroyed.
//
// Input Format
// The first line will contain 
// T
// T - the number of test cases. Then the test cases follow.
// First line of each test case contains 
// 2
// 2 integers 
// N
// ,
// X
// N,X.
// Second line of test case contains 
// N
// N space separated integers 
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
//  .
// Output Format
// For each test case, output in a single line the maximum number of houses that can get destroyed if the bomb can hit any house.
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
// 1
// 0
// 5
// 1≤N≤10 
// 5
//  
// 1
// ≤
// X
// ≤
// 1
// 0
// 9
// 1≤X≤10 
// 9
//  
// 1
// ≤
// A
// i
// ≤
// 1
// 0
// 9
// 1≤A 
// i
// ​
//  ≤10 
// 9
//  
// Sum of 
// N
// N over all test cases does not exceed 
// 1
// 0
// 5
// 10 
// 5
//  
// Sample 1:
// Input
// Output
// 2
// 8 6
// 4 1 6 1 6 5 6 8
// 2 1
// 3 5
// 6
// 0
// Explanation:
// Test Case 
// 1
// 1: The bomb can only destroy houses 
// 1
// ,
// 2
// ,
// 4
// ,
// 1,2,4, and 
// 6
// 6.
//
// If it hits house 
// 1
// 1, only house 
// 1
// 1 is destroyed.
// If it hits house 
// 2
// 2, houses 
// 1
// 1 and 
// 2
// 2 are destroyed.
// If it hits house 
// 4
// 4, houses 
// 1
// ,
// 2
// ,
// 3
// 1,2,3 and 
// 4
// 4 are destroyed.
// If it hits house 
// 6
// 6, houses 
// 1
// ,
// 2
// ,
// 3
// ,
// 4
// ,
// 5
// ,
// 1,2,3,4,5, and 
// 6
// 6 are destroyed.
// The maximum number of destroyed houses is 
// 6
// 6.
//
// Test Case 
// 2
// 2: The bomb cannot destroy any of the houses as the defence system of each house is not lesser than attack power of bomb. Thus, the total number of destroyed houses is 
// 0
// 0.
