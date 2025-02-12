#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        string s,s1;
        cin >> s >> s1;
        for(int i=0;i<s.length();i++){
            if(s[i] == s1[i]){
                cout << 'G';
            }else{
                cout << "B";
            }
        }
        cout << endl;
    }
}


// Wordle
// Chef invented a modified wordle.
//
// There is a hidden word 
// S
// S and a guess word 
// T
// T, both of length 
// 5
// 5.
//
// Chef defines a string 
// M
// M to determine the correctness of the guess word. For the 
// i
// t
// h
// i 
// th
//   index:
//
// If the guess at the 
// i
// t
// h
// i 
// th
//   index is correct, the 
// i
// t
// h
// i 
// th
//   character of 
// M
// M is 
// G
// G.
// If the guess at the 
// i
// t
// h
// i 
// th
//   index is wrong, the 
// i
// t
// h
// i 
// th
//   character of 
// M
// M is 
// B
// B.
// Given the hidden word 
// S
// S and guess 
// T
// T, determine string 
// M
// M.
//
// Input Format
// First line will contain 
// T
// T, number of test cases. Then the test cases follow.
// Each test case contains of two lines of input.
// First line contains the string 
// S
// S - the hidden word.
// Second line contains the string 
// T
// T - the guess word.
// Output Format
// For each test case, print the value of string 
// M
// M.
//
// You may print each character of the string in uppercase or lowercase (for example, the strings 
// BgBgB
// BgBgB, 
// BGBGB
// BGBGB, 
// bgbGB
// bgbGB and 
// bgbgb
// bgbgb will all be treated as identical).
//
// Constraints
// 1
// ≤
// T
// ≤
// 1000
// 1≤T≤1000
// ∣
// S
// ∣
// =
// ∣
// T
// ∣
// =
// 5
// ∣S∣=∣T∣=5
// S
// ,
// T
// S,T contain uppercase english alphabets only.
// Sample 1:
// Input
// Output
// 3
// ABCDE
// EDCBA
// ROUND
// RINGS
// START
// STUNT
// BBGBB
// GBBBB
// GGBBG
// Explanation:
// Test Case 
// 1
// 1: Given string 
// S
// =
// ABCDE
// S=ABCDE and 
// T
// =
// EDCBA
// T=EDCBA. The string 
// M
// M is:
//
// Comparing the first indices, 
// A
// ≠
// E
// A=E, thus, 
// M
// [
// 1
// ]
// =
// B
// M[1]=B.
// Comparing the second indices, 
// B
// ≠
// D
// B=D, thus, 
// M
// [
// 2
// ]
// =
// B
// M[2]=B.
// Comparing the third indices, 
// C
// =
// C
// C=C, thus, 
// M
// [
// 3
// ]
// =
// G
// M[3]=G.
// Comparing the fourth indices, 
// D
// ≠
// B
// D=B, thus, 
// M
// [
// 4
// ]
// =
// B
// M[4]=B.
// Comparing the fifth indices, 
// E
// ≠
// A
// E=A, thus, 
// M
// [
// 5
// ]
// =
// B
// M[5]=B.
// Thus, 
// M
// =
// BBGBB
// M=BBGBB.
// Test Case 
// 2
// 2: Given string 
// S
// =
// ROUND
// S=ROUND and 
// T
// =
// RINGS
// T=RINGS. The string 
// M
// M is:
//
// Comparing the first indices, 
// R
// =
// R
// R=R, thus, 
// M
// [
// 1
// ]
// =
// G
// M[1]=G.
// Comparing the second indices, 
// O
// ≠
// I
// O=I, thus, 
// M
// [
// 2
// ]
// =
// B
// M[2]=B.
// Comparing the third indices, 
// U
// ≠
// N
// U=N, thus, 
// M
// [
// 3
// ]
// =
// B
// M[3]=B.
// Comparing the fourth indices, 
// N
// ≠
// G
// N=G, thus, 
// M
// [
// 4
// ]
// =
// B
// M[4]=B.
// Comparing the fifth indices, 
// D
// ≠
// S
// D=S, thus, 
// M
// [
// 5
// ]
// =
// B
// M[5]=B.
// Thus, 
// M
// =
// GBBBB
// M=GBBBB.
