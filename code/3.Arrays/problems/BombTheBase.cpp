#include <bits/stdc++.h>
using namespace std;
// if the strength of i'th element is less than x then all the previous indexesnbefore the ith elemt is destroyedd and
// count of the destroyed elemsnts is given

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int ans=0;
        for(int i = n-1; i >= 0; i--)
        {
            if(a[i] < x)
            {
                ans = i+1;
                break;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
