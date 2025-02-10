#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        for(int i=0; i<n; i++)
        {
            if(arr[i]>k) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}











// Red Light, Green Light
// “You won’t get caught if you hide behind someone.”
//
// Sang-Woo advises Gi-Hun to hide behind someone to avoid getting shot.
//
// Gi-Hun follows Sang-Woo's advice and hides behind Ali, who saved his life earlier. Gi-Hun and Ali both have the same height, 
// K
// K. Many players saw this trick and also started hiding behind Ali.
//
// Now, there are 
// N
// N players standing between Gi-Hun and Ali in a straight line, with the 
// i
// th
// i 
// th
//   player having height 
// H
// i
// H 
// i
// ​
//  . Gi-Hun wants to know the minimum number of players who need to get shot so that Ali is visible in his line of sight.
//
// Note:
//
// Line of sight is a straight line drawn between the topmost point of two objects. Ali is visible to Gi-Hun if nobody between them crosses this line.
// Even if there are some players who have the same height as that of Gi-Hun and Ali, Ali will be visible in Gi-Hun's line of sight.
// Gi-Hun and Ali have the same height.
// Input Format
// The first line of input contains a single integer 
// T
// T, denoting the number of test cases. The description of 
// T
// T test cases follows.
// The first line of each test case contains two space-separated integers 
// N
// N and 
// K
// K, denoting the total number of players between Gi-Hun and Ali and the height of both of them respectively.
// The second line of each test case contains 
// N
// N space-separated integers, denoting the heights of the players between Gi-Hun and Ali.
// Output Format
// For each test case, output in a single line the minimum number of players who need to get shot so that Ali is visible in Gi-Hun's line of sight.
//
// Constraints
// 1
// ≤
// T
// ≤
// 1
// 0
// 5
// 1≤T≤10 
// 5
//  
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
// K
// ≤
// 1
// 0
// 6
// 1≤K≤10 
// 6
//  
// 1
// ≤
// H
// i
// ≤
// 1
// 0
// 6
// 1≤H 
// i
// ​
//  ≤10 
// 6
//   for every 
// 1
// ≤
// i
// ≤
// N
// 1≤i≤N.
// The sum of 
// N
// N across all test cases does not exceed 
// 5
// ⋅
// 1
// 0
// 5
// 5⋅10 
// 5
//  .
// Sample 1:
// Input
// Output
// 3
// 4 10
// 2 13 4 16
// 5 8
// 9 3 8 8 4
// 4 6
// 1 2 3 4
// 2
// 1
// 0
// Explanation:
// Test Case 1: Gi-Hun and Ali have height 
// 10
// 10. For Ali to be visible to Gi-Hun, the second person (with height 
// 13
// 13) and the fourth person (with height 
// 16
// 16) need to get shot. Hence, the minimum number of players who need to get shot is 
// 2
// 2.
//
// Test Case 2: Gi-Hun and Ali have height 
// 8
// 8. For Ali to be visible to Gi-Hun, the first person (with height 
// 9
// 9) needs to get shot. Hence, the minimum number of players who need to get shot is 
// 1
// 1.
//
// Test Case 3: Nobody needs to get shot because everyone is shorter than Gi-Hun and Ali.
