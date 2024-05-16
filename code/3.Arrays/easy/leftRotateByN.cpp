// #include<iostream>
// using namespace std;

// void leftRotate(int arr[], int n, int d){
//     d = d % n;
//     int temp[d];

//     for(int i=0;i<d;i++){
//         temp[i]=arr[i];
//     }

//     for(int i=d;i<n;i++){
//         arr[i-d] = arr[i];
//     }

//     for(int i=d+1;i<n;i++){
//         arr[i] = temp[i-(n-d)];
//     }

// }

// int main(){
//     int d;
//     cin >> d;
//     int n;
//     cin >> n;
//     int arr[n];

//     for(int i=0;i<=n;i++){
//         cin >> arr[i];
//     }

//     leftRotate(arr, n, d);

// }

#include<iostream>
using namespace std;


int main(){
    int d;
    cin >> d;
    int n;
    cin >> n;
    int arr[n];

    for(int i=0;i<=n;i++){
        cin >> arr[i];
    }

    d = d % n;
    reverse(arr.begin(), arr.end());
    reverse(arr.begin(), arr.begin()+d);
    reverse(arr.begin()+d, arr.end());
}