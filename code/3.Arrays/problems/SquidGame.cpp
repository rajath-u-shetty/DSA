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
