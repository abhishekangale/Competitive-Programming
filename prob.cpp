#include<bits/stdc++.h>
using namespace std;

#define int long long 

signed main(){
    int n;
    cin>>n;
    int a[n];
    int mn=LLONG_MAX;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i>0){a[i]+=a[i-1];}
        mn=min(mn,a[i]);
    }
    cout<<mn;
}