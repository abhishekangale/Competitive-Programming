#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define lb long double
#define all(x) x.begin(),x.end()
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fo(i,n) for(i=0;i<n;i++)
#define foi(i,a,n) for(i=a;i<n;i++)
#define fod(i,a,n) for(i=n-1;i>=a;i--)
#define     minv(v)     *min_element(v.begin(),v.end())
#define     maxv(v)     *max_element(v.begin(),v.end())
#define mpp map<ll,ll> 
#define pll pair<ll, ll>
#define vll vector<ll>
#define vpll vector<pll>
#define vs vector<string>
#define mod (ll)(1e9+7)
template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;
//  order_of_key (k) : Number of items strictly smaller than k .
// find_by_order(k) : K-th element in a set (counting from zero).
int tt=1;

/* Template taken from tourist*/
string to_string(string s){return '"'+s+'"';}
string to_string(const char* s){return to_string((string)s);}
string to_string(bool b){return(b?"true":"false");}
template<typename A,typename B>
string to_string(pair<A,B>p){return"("+to_string(p.first)+", "+to_string(p.second)+")";}
template<typename A>
string to_string(A v){bool z=true;string r="{";for(const auto &x:v){if(!z){r+=", ";}z=false;r+=to_string(x);}r+="}";return r;}
void debug_out(){cerr << endl;}
template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T){cerr << " " << to_string(H);debug_out(T...);}
#ifndef ONLINE_JUDGE
// #define debug(...) cerr << "[" << #_VA_ARGS_ << "]:", debug_out(_VA_ARGS_)
#else
#define debug(...) 0
#endif

void solve()
{
    ll a,n,m,i,j,k;
    cin>>n>>k;
    vll v[n+1];
    m=n-1;
    while(m--)
    {
        cin>>i>>j;
        v[i].pb(j);
        v[j].pb(i);
    }
    mpp vis,m1,m2;
    vis[1]=1;
    queue<ll> q;
    for(auto e:v[1])
    {

        q.push(e);
        m2[e]=1;
        vis[e]=1;
        m1[e]=e;
        while(!q.empty())
        {
            ll p=q.front();
            q.pop();
            for(auto f:v[p])
            {
                if(!vis[f])
                {
                    q.push(f);
                    vis[f]=1;
                    m1[f]=e;
                }
            }
        }
    }
    // debug(m1);
    // debug(m2);
    while(k--)
    {
        cin>>i>>j;
        if(m2[i]!=1)
        {
            if(m1[i]==m1[j])
            {
                cout<<2<<"\n";
            }
            else
            {
                cout<<1<<"\n";
            }
        }
        else
        {
            cout<<1<<"\n";
        }
    }


   
}
int main()
{
    cout<<setprecision(15);
    fast
    //cin>>tt;
    while(tt--)
    {
       solve();
    }
}