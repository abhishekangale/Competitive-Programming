// frog jumps
// make sure you change variable names and add unnecessary stuffs

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
int minjumps(vector<int> arr, int n){
    if (n <= 1)
        return 0;
    if (arr[0] == 0)
        return -1;
    int maxReach = arr[0];
    int step = arr[0];
    int jump = 1;
    int i = 1;
    for (i = 1; i < n; i++) {
        if (i >= n-1)
            return jump;
        maxReach = max(maxReach, i + arr[i]);
        step--;
        if (step == 0) {
            jump++;
            step = maxReach - i;
        }
    }
    return jump;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=0;i<n;i++)cin>>a[i];
    a[n]=1;
    cout<<minjumps(a,n+1);
}