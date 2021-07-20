#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define A first
#define B second
#define lb long double
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fo(i,n) for(i=0;i<n;i++)
#define mpp map<ll,ll>m;
#define vec vector<ll>v;
#define mod (ll)(1e9+7)
int t=1;
 
void solve()
{
    ll i,j,n,co=0;
    string s,s1="";
    cin>>s;
    n=s.size();
    map<char,ll> m;
    fo(i,n)
    m[s[i]]++;
    for(char c='A';c<='Z';c++)
    {
        if(m[c]==0)
        {
            ++co;
            s1+=c;
        }
    }
    j=0;
    fo(i,n)
    {
        if(s[i]=='?')
        {
            if(co>0)
            {
                s[i]=s1[j];
                ++j;
                --co;
            }
            else
            s[i]='A';
        }
    }
    if(co==0)
    cout<<s;
    else
    cout<<-1;
 
}
int main()
{
    fast
    //cin>>t;
    while(t--)
    {
        solve();
    }
}