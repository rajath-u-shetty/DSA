#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int c[n], t[n];

    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    int at = 100000;
    int tr = 100000;
    int attr = 100000;

    for (int i = 0; i < n; i++) {
        if (t[i] == 1) {
            tr = min(tr, c[i]);
        } else if (t[i] == 2) {
            at = min(at, c[i]);
        } else if (t[i] == 3){
            attr = min(attr, c[i]);
        }
    }

    int minTotalCost = min(tr + at, attr);
    cout<< minTotalCost << "\n";
    return 0;
}



// Workers
// Read problems statements in Mandarin chinese, Russian and Vietnamese as well.
// There are 
// N
// N workers; each worker is of one of the following three types:
//
// A translator translates some text from Chef's language to another language.
// An author writes some text in Chef's language.
// An author-translator can both write a text in Chef's language and translate it to another language.
// Chef wants to have some text written and translated into some language (different from Chef's language). Chef can't do either of those tasks, but he can hire workers. For each 
// i
// i (
// 1
// ≤
// i
// ≤
// N
// 1≤i≤N), if he hires the 
// i
// i-th worker, he must pay that worker 
// c
// i
// c 
// i
// ​
//   coins.
//
// Help Chef find the minimum total number of coins he needs to pay to have a text written and translated. It is guaranteed that it is possible to write and translate a text.
//
// Input Format
// The first line of the input contains a single integer 
// N
// N denoting the number of workers.
// The second line contains 
// N
// N space-separated integers 
// c
// 1
// ,
// c
// 2
// ,
// .
// .
// .
// ,
// c
// N
// c 
// 1
// ​
//  ,c 
// 2
// ​
//  ,...,c 
// N
// ​
//   denoting the numbers of coins Chef has to pay each hired worker.
// The third line contains 
// N
// N space-separated integers 
// t
// 1
// ,
// t
// 2
// ,
// .
// .
// .
// ,
// t
// N
// t 
// 1
// ​
//  ,t 
// 2
// ​
//  ,...,t 
// N
// ​
//   denoting the types of workers. For each valid 
// i
// i, the 
// i
// i-th worker is a translator if 
// t
// i
// =
// 1
// t 
// i
// ​
//  =1, an author if 
// t
// i
// =
// 2
// t 
// i
// ​
//  =2 or an author-translator if 
// t
// i
// =
// 3
// t 
// i
// ​
//  =3.
// Output Format
// Print a single line containing one integer — the minimum number of coins Chef has to pay.
// Constraints
// 1
// ≤
// N
// ≤
// 1
// ,
// 000
// 1≤N≤1,000
// 1
// ≤
// c
// i
// ≤
// 100
// ,
// 000
// 1≤c 
// i
// ​
//  ≤100,000 for each valid 
// i
// i
// 1
// ≤
// t
// i
// ≤
// 3
// 1≤t 
// i
// ​
//  ≤3 for each valid 
// i
// i
// Subtasks
// Subtask #1 (15 points): all workers are author-translators
//
// Subtask #2 (85 points): original constraints
//
// Sample 1:
// Input
// Output
// 5
// 1 3 4 6 8
// 1 2 1 2 3
// 4
// Explanation:
// Chef can hire 2 workers: worker 1, who is a translator, and worker 2, who is an author. In total, he pays them 
// 1
// +
// 3
// =
// 4
// 1+3=4 coins.
