#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// oset Operations: order_of_key(k) -> Number of elements strictly smaller than k, find_by_order(k) -> kth element in the set
 
#define ull unsigned long long int
#define int long long int
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vb vector<bool>
#define vd vector<double>
#define vll vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define vvi vector<vi>
#define vvll vector<vll>
#define vvb vector<vb>
#define vs vector<string>
#define pull pair<ull, ull>
#define F first
#define S second
#define m_p make_pair
 
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
 
const int mod = 1e9 + 7;
 
void solve(){
    int n;
    cin>>n;
    map<int,set<int>> a;
    map<pair<int,int>,vi> zz;
    int ans[n];
    for(int i=0;i<n-2;i++){
        int x,y,z;
        cin>>x>>y>>z;
        a[x].insert(y);
        a[x].insert(z);
        a[y].insert(x);
        a[y].insert(z);
        a[z].insert(x);
        a[z].insert(y);
        int vev[3] = {x,y,z};
        sort(vev,vev+3);
        zz[{vev[0],vev[1]}].pb(vev[2]);
        zz[{vev[1],vev[2]}].pb(vev[0]);
        zz[{vev[0],vev[2]}].pb(vev[1]);
    }
    int mn=INT_MAX;
    int mnx;
    for(auto i:a){
        if(mn>(int)(i.S.size())){
            mn=(int) i.S.size();
            mnx = i.F;
        }
    }
    ans[0]=mnx;
    for(auto x:a[mnx]){
        if(a[x].size()==3){
            mnx=x;
        }
    }
    ans[1]=mnx;
    for(int i=2;i<n;i++){
        int m=ans[i-2];
        int n=ans[i-1];
        int all;
        if(m>n){swap(m,n);}
        if(i==2) ans[i]=*zz[{m,n}].begin();
        else {
            for(auto k:zz[{m,n}]){
                if(k==ans[i-3]){
                    continue;
                }
                else {
                    all = k;
                }
            }
            ans[i]=all;
        }
    }
    for(int i:ans) cout<<i<<" ";
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