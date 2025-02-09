#include<bits/stdc++.h>
using namespace std;
// find the combinations of the sum annd check who will get the highes money
// for every person to win the remaining evryone should die.. hence find which combination except ooone element will
// give max profit

int main() {
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        int sum = 0;
        int smallest_element = 1e6;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            sum += v[i];
            smallest_element = min(smallest_element, v[i]);
        }
        cout << sum - smallest_element << "\n";
    }
    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
// 	// your code goes here
//     int t,n;
//     cin >> t;
//     while(t--){
//         cin >> n;
//         int arr[n];
//         int mini=INT_MAX;
//         for(int i=0;i<n;i++){
//             cin >> arr[i];
//             if(arr[i] < mini){
//                 mini = arr[i];
//             }
//         }
//         
//         int cnt=0;
//         int sum=0;
//         for(int i=0;i<n;i++){
//             if(arr[i] == mini){
//                 cnt++;
//             }
//             if(arr[i] != mini){
//                 sum+=arr[i];
//             }
//         }
//         
//         
//         cout << sum+((cnt-1)*mini) << endl;
//     }
// }
//
// The Squid Game
// "Let the games begin."
//
// Squid Game has become a blockbuster hit and the frontman is now finding it difficult to accommodate all the participants in Squid Game 2.0. So, he decided that he will allow only those participants who could solve the following problem.
//
// There are a total of 
// N
// N players who are competing in the Squid Game, numbered from 
// 1
// 1 to 
// N
// N. When the 
// i
// th
// i 
// th
//   player gets eliminated from the game, 
// A
// i
// A 
// i
// ​
//   amount of money is added to the prize pool. The game is played until 
// N
// −
// 1
// N−1 players get eliminated, and the only player left is declared as the winner. The winner gets all the money present in the prize pool.
//
// You are given an array 
// A
// A consisting of 
// N
// N elements, where 
// A
// i
// A 
// i
// ​
//   denotes the prize money added to the prize pool when the 
// i
// th
// i 
// th
//   player gets eliminated from the game. Find the maximum prize that the winner can get, given that you can choose any player to be the winner.
//
// Input Format
// The first line of input contains a single integer 
// T
// T, denoting the number of test cases. The description of 
// T
// T test cases follows.
// The first line of each test case contains an integer 
// N
// N, denoting the number of players.
// The second line of each test case contains 
// N
// N space-separated integers 
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
//  , denoting the amount of money added to the prize pool when the 
// i
// th
// i 
// th
//   (
// 1
// ≤
// i
// ≤
// N
// 1≤i≤N) player dies.
// Output Format
// For each test case, output in a single line the maximum prize that the winner can get, given that you can choose any player to be the winner.
//
// Constraints
// 1
// ≤
// T
// ≤
// 1000
// 1≤T≤1000
// 2
// ≤
// N
// ≤
// 1
// 0
// 5
// 2≤N≤10 
// 5
//  
// 0
// ≤
// A
// i
// ≤
// 1
// 0
// 4
// 0≤A 
// i
// ​
//  ≤10 
// 4
//  
// The sum of 
// N
// N across all test cases does not exceed 
// 1
// 0
// 6
// 10 
// 6
//  .
// Sample 1:
// Input
// Output
// 3
// 3
// 3 1 2
// 5
// 1 1 1 1 1
// 6
// 3 6 4 2 5 1
// 5
// 4
// 20
// Explanation:
// Test Case 1:
//
// If we choose the first player to be the winner, he will win the game when the second and third players die. Hence, the amount of money won by him will be 
// 1
// +
// 2
// =
// 3
// 1+2=3.
// If we choose the second player to be the winner, he will win the game when the first and third players die. Hence, the amount of money won by him will be 
// 3
// +
// 2
// =
// 5
// 3+2=5.
// If we choose the third player to be the winner, he will win the game when the first and second players die. Hence, the amount of money won by him will be 
// 3
// +
// 1
// =
// 4
// 3+1=4.
// Therefore, we can clearly see that the maximum amount of money that can be won by any player is 
// 5
// 5.
//
// Test Case 2: Irrespective of who is chosen, the winner will always win an amount of 
// 4
// 4.
//
// Test Case 3: If we choose the sixth player to be the winner, the amount won by him will be 
// 3
// +
// 6
// +
// 4
// +
// 2
// +
// 5
// =
// 20
// 3+6+4+2+5=20. It can be proven that if we choose any other player to be the winner, the amount is less than 
// 20
// 20. Hence, the maximum amount of money that can be won by any player is 
// 20
// 20.
