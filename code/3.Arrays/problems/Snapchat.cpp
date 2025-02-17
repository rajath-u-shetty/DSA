#include <bits/stdc++.h>
using namespace std;

// if both person in two arrays send ecah other atleast one snap then they'll have a streak else if there is 0 snpas
// sent then the streak resets to a day

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n],b[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        int ans = 0, cur = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > 0 && b[i] > 0) cur++;
            else cur = 0;
            ans = max(ans, cur);
        }
        cout << ans << "\n";
    }
    return 0;
}


// #include <bits/stdc++.h>␍
// using namespace std;␍
// ␍
// int main() {␍
//     int t;␍
//     cin>>t;␍
//     while(t--){␍
//         int n;␍
//         cin>>n;␍
//         int a[n],b[n];␍
//         for(int i=0;i<n;i++){␍
//             cin>>a[i];␍
//         }␍
//         for(int i=0;i<n;i++){␍
//             cin>>b[i];␍
//         }␍
//         int cnt=0;␍
//         int maxi=0;␍
//         for(int i=0;i<n;i++){␍
//             if(a[i] <= 0 || b[i] <= 0){␍
//                 cnt=0;␍
//             }else{
//                 cnt++;␍
//                 maxi=max(maxi,cnt);␍
//             }
//         }
//     
//     cout << maxi << endl;␍
//     }
// 	// your code goes here␍
//
// }
//
//
//
//
// Snapchat
// The most popular feature on snapchat is Snapchat Streak.
// A streak is maintained between two people if both of them send at least one snap to each other daily.
// If, on any day, either person forgets to send at least one snap, the streak breaks and the streak count is set to 
// 0
// 0.
//
// Chef and Chefina like maintaining their snapchat streak. You observed the snap count of both of them for 
// N
// N consecutive days.
// On the 
// i
// t
// h
// i 
// th
//   day, Chef sent 
// A
// i
// A 
// i
// ​
//   snaps to Chefina while Chefina sent 
// B
// i
// B 
// i
// ​
//   snaps to Chef.
//
// Find the maximum streak count they achieved in those 
// N
// N days.
//
// Input Format
// The first line of input will contain a single integer 
// T
// T, denoting the number of test cases.
// Each test case consists of multiple lines of input.
// The first line of each test case contains an integer 
// N
// N — the number of days you observed.
// The second lines contains 
// N
// N space-separated integers — 
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
//  , the number of snaps Chef sent to Chefina on the 
// i
// t
// h
// i 
// th
//   day.
// The third lines contains 
// N
// N space-separated integers — 
// B
// 1
// ,
// B
// 2
// ,
// …
// ,
// B
// N
// B 
// 1
// ​
//  ,B 
// 2
// ​
//  ,…,B 
// N
// ​
//  , the number of snaps Chefina sent to Chef on the 
// i
// t
// h
// i 
// th
//   day.
// Output Format
// For each test case, output on a new line, the maximum streak count they achieved in those 
// N
// N days.
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
// 1000
// 1≤N≤1000
// 0
// ≤
// A
// i
// ,
// B
// i
// ≤
// 100
// 0≤A 
// i
// ​
//  ,B 
// i
// ​
//  ≤100
// Sample 1:
// Input
// Output
// 4
// 3
// 3 1 2
// 2 4 1
// 2
// 0 0
// 10 10
// 4
// 5 4 0 2
// 3 1 1 0
// 5
// 0 1 1 2 0
// 1 1 0 0 3
// 3
// 0
// 2
// 1
// Explanation:
// Test case 
// 1
// 1: For all 
// 3
// 3 days, both Chef and Chefina sent at least one snap per day. Thus, at the end of third day, the streak count is 
// 3
// 3.
//
// Test case 
// 2
// 2: Chef did not send any snap to Chefina. Thus, at the streak count remains 
// 0
// 0 on both days.
//
// Test case 
// 3
// 3: For the first two days, both Chef and Chefina send at least one snap per day. Thus, at the end of second day, the streak count is 
// 2
// 2.
// On the end of third day, since Chef did not send any snap, the streak count becomes 
// 0
// 0.
// On the end of fourth day, since Chefina did not send any snap, the streak count remains 
// 0
// 0.
//
// Test case 
// 4
// 4:
//
// On the end of first day, since Chef did not send any snap, the streak count remains 
// 0
// 0.
// On second day, both Chef and Chefina sent at least one snap. Thus, the streak count becomes 
// 1
// 1.
// On the end of third day, since Chefina did not send any snap, the streak count becomes 
// 0
// 0.
// On the end of fourth day, since Chefina did not send any snap, the streak count remains 
// 0
// 0.
// On the end of fifth day, since Chef did not send any snap, the streak count remains 
// 0
// 0.
// The maximum streak count over 
// 5
// 5 days is 
// 1
// 1.
