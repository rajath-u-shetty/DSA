#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t; 

    while (t--) {
        int n;
        cin >> n; 
        int prices[2 * n]; 

        for (int i = 0; i < 2 * n; i++) {
            cin >> prices[i];
        }

        map<int, int> priceCount;
        bool isValid = true;

        for (int i = 0; i < 2 * n; i++) {
            priceCount[prices[i]]++;
            if (priceCount[prices[i]] > 2) {
                isValid = false; 
                break;
            }
        }
        if (isValid) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}


// Candies
// Abhi is a salesman. He was given two types of candies, which he is selling in 
// N
// N different cities.
//
// For the prices of the candies to be valid, Abhi's boss laid down the following condition:
//
// A given type of candy must have distinct prices in all 
// N
// N cities.
// In his excitement, Abhi wrote down the prices of both the candies on the same page and in random order instead of writing them on different pages. Now he is asking for your help to find out if the prices he wrote are valid or not.
//
// You are given an array 
// A
// A of size 
// 2
// N
// 2N. Find out whether it is possible to split 
// A
// A into two arrays, each of length 
// N
// N, such that both arrays consist of distinct elements.
//
// Both arrays can have distinct elements only if no element in the original array is repeated more than twice.
//
// Input Format
// The first line of input will contain a single integer 
// T
// T, denoting the number of test cases.
// Each test case consists of two lines of input.
// The first line of each test case contains one integer 
// N
// N, denoting the number of cities
// The second line contains 
// 2
// N
// 2N space-separated integers 
// A
// 1
// ,
// A
// 2
// ,
// …
// ,
// A
// 2
// N
// A 
// 1
// ​
//  ,A 
// 2
// ​
//  ,…,A 
// 2N
// ​
//   — the elements of the array 
// A
// A.
// Output Format
// For each test case output the answer on a new line — Yes if the given array represents a valid list of prices, and No otherwise.
//
// Each letter of the output may be printed in either uppercase or lowercase, i.e, Yes, YES, and yEs will all be treated as equivalent.
//
// Constraints
// 1
// ≤
// T
// ≤
// 1
// 0
// 3
// 1≤T≤10 
// 3
//  
// 1
// ≤
// N
// ≤
// 1
// 0
// 3
// 1≤N≤10 
// 3
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
// The sum of 
// N
// N over all testcases does not exceed 
// 2
// ⋅
// 1
// 0
// 3
// 2⋅10 
// 3
//  
// Sample 1:
// Input
// Output
// 4
// 3
// 4 8 4 6 7 3
// 3
// 4 8 6 8 7 8
// 2
// 2 4 5 3
// 4
// 8 7 9 8 4 6 2 8
// Yes
// No
// Yes
// No
// Explanation:
// Test case 
// 1
// 1: One valid way of assigning prices is as follows:
//
// The first candy can have a price of 
// 4
// 4 in city 
// 1
// 1, 
// 6
// 6 in city 
// 2
// 2, and 
// 8
// 8 in city 
// 3
// 3.
// The second candy can have a price of 
// 4
// 4 in city 
// 1
// 1, 
// 3
// 3 in city 
// 2
// 2, and 
// 7
// 7 in city 
// 3
// 3.
// Since a valid assignment exists, the answer is "Yes".
//
// Test case 
// 2
// 2: No valid set of prices exists that could give this array, since 
// 8
// 8 would be repeated somewhere.
//
// Test case 
// 3
// 3: One way of splitting the prices is 
// [
// 2
// ,
// 5
// ]
// [2,5] and 
// [
// 4
// ,
// 3
// ]
// [4,3].
//
// Test case 
// 4
// 4: No valid set of prices exists that could give this array.
