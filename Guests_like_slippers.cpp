#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAX=1e6+10;
const ll sz=4e5;
ll BITree[MAX] = {0};
const ll mod=998244353;
ll summ(ll index)
{
 ll sum = 0;
 
 index = index + 1;
 
 while (index>0)
 {
  sum += BITree[index];
        sum%=mod;
  index -= index & (-index);
 }
 return sum%mod;
}
 
void updateBIT(ll n, ll index, ll val)
{
 index = index + 1;
 
 while (index <= n)
 {
 BITree[index] += val;
 BITree[index]%=mod;
 
 index += index & (-index);
 }
}
 
void solve(){
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    for(ll i=0;i<MAX;i++)
        BITree[i]=0;
    for(ll i=0;i<n;i++){
        updateBIT(sz,a[i],summ(a[i]-1)+1);
    }
    for(int i=37; i<=50; i++){
        cout << BITree[i] << '\n';
    }
}
int main(){
    ll t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}