#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// oset Operations: order_of_key(k) -> Number of elements strictly smaller than k, find_by_order(k) -> kth element in the set
 
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
int tt=1;
 
const long double PI = 3.141592653589793238462643383279502884197169399;
 
template <typename A, typename B> string to_string(pair<A, B> p);
template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p);
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string) s); }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}
template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res.push_back(static_cast<char>('0' + v[i]));
    }
    return res;
}
template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}
#ifndef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 0
#endif
 
// Find Set LSB = (x&(-x)), isPowerOfTwo = (x & (x-1))
 
void solve()
{
    ll n,l,i,c=0,m;
    cin>>n>>l;
    vector<ll> v(n);
    fo(i,n)
    cin>>v[i];
    sort(all(v));
    m=v[n-1];
    for(i=1;i<=m;i++)
    {
        auto it=lower_bound(v.begin(),v.end(),i);
        int a=it-v.begin();
        c+=(n-a);
        if(c>=l)
        {
            cout<<i;
            return;
        }
    }
    cout<<-1;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cout << fixed << setprecision(10);
    
    int tt=1;
    //cin >> tt;
    
    while(tt--){
        solve();
    }
}