// #include<iostream>
// using namespace std;

// int mian(){
//     cin >> n;
//     int a[n];

//     for(int i=0;i<=n;i++){
//         cin >> a[i];
//     }

//     map<long long,int> preSumMap;
//     long long sum = 0;
//     int maxLen = 0;
//     for(int i=0;i<a.size();i++){
//         sum += a[i];
//         if(sum == k){
//             maxLen = max(maxLen, i+1);
//         }

//         long long rem = sum - k;
//         if(preSumMap.find(rem) != preSumMap.end()){
//             int len = i - preSumMap[rem];
//             maxLen = maxLen(maxLen, len);
//         }
            
//         if(preSumMap.find(sum) == preSumMap.end()){
//             preSumMap[rem] = i;
//         }
//     }

//     return maxLen;
// }

#include<iostream>
using namespace std;

int main(){
    int n,k;
    cin >> k;
    cin >> n;
    int arr[n];

    for(int i=0;i<=n;i++){
        cin >> arr[i];
    }

    int left = 0, right = 0;
    int sum = a[0];
    int len = 0;

    while (right < n){

        while(sum > k && left <= right){
            sum -= a[left];
            left++;
        }

        if(sum == k){
            len = max(len,right - left + 1);
        }

        right++;
        sum += a[right];
    }

    cout << len;
    
}