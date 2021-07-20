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

void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    vi x(n*m+1),y(n*m+1);
    string ans = "Draw";
    int steps=(int)1e9+5;

    for(int i=1;i<=n*m;i++){ 
        cin>>x[i]>>y[i];
    }

    int l=1,r=n*m;
    while(l<=r){
        int mid = (l+r)/2;
        int maybe=0;
        vector<vector<int>> dp(n+2, vector<int>(m+2,0));
        for(int i=1;i<=mid;i++){
            if(i%2){
                dp[x[i]][y[i]]=1;
            }
            else {
                dp[x[i]][y[i]]=2;
            }
        }
        vector<vector<int>> poss1(n+2, vector<int>(m+2,0));
        vector<vector<int>> poss2=poss1;
        // back-forward
        for(int i=n;i>=1;i--){
            for(int j=1;j<=m;j++){
                if(dp[i][j]==1) poss1[i][j]=poss1[i+1][j]+1;
                else poss1[i][j]=0;
            }
        }
        // back-back
        for(int i=n;i>=1;i--){
            for(int j=m;j>=1;j--){
                if(poss1[i][j]>=k) poss1[i][j]=poss1[i][j+1]+1;
                else poss1[i][j]=0;
                if(poss1[i][j]>=k) maybe=1;
            }
        }
        //back-forward
        for(int i=n;i>=1;i--){
            for(int j=1;j<=m;j++){
                if(dp[i][j]==2) poss2[i][j]=poss2[i+1][j]+1;
                else poss2[i][j]=0;
            }
        }
        // back-back
        for(int i=n;i>=1;i--){
            for(int j=m;j>=1;j--){
                if(poss2[i][j]>=k) poss2[i][j]=poss2[i][j+1]+1;
                else poss2[i][j]=0;
                if(poss2[i][j]>=k) maybe=2;
            }
        }

        if(!maybe){
            l=mid+1;
        }
        else{
            r=mid-1;
            if(mid<steps){
                steps=mid;
                if(maybe==2) ans="Bob";
                else ans="Alice";
            }
        }
    }
    cout<<ans<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cout << fixed << setprecision(10);
    
    int tt=1;
    cin >> tt;
    
    while(tt--){
        solve();
    }
}