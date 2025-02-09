#include <bits/stdc++.h>
using namespace std;
//if the elements's previous or next element is same then remove it

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> frames(n);

        for (int i = 0; i < n; i++) {
            cin >> frames[i];
        }

        int minFrames = n;
        for (int i = 0; i < n - 1; i++) {
            if (frames[i] == frames[i + 1]) {
                minFrames--;
            }
        }

        cout << minFrames << endl;
    }

    return 0;
}
