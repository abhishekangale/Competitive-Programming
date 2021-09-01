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
set<int> powx;
int moves(int x,int y){
    set<int> mov;
    set<int> pow2=powx,pow22=powx;
    if(y<=x) swap(x,y);
     y-=x;
    while(x!=0){
        int f=-1;
        for(auto i:pow2){
            if(i<=x) f=i;
        }
        if(f==-1) return -1;
        pow2.erase(f);
        mov.insert(f);
        x-=f;
        
    }
   
    while(y!=0){
        int f=-1;
        for(auto i:pow2){
            if(i<=y) f=i;
        }
        if(f==-1) return -1;
        pow2.erase(f);
        mov.insert(f);
        y-=f;
        
    }
    return mov.size();
} 
void solve(){
    int n,m;
    cin>>n>>m;
    vi a(n);
    int sum=0,ans1=1e9;
    for(auto &i:a)cin>>i,sum+=i;
    vector<pair<int,int>> pairs;
    if(sum%m==0){
        cout<<0<<'\n';
        return;
    }
    for(int i=n-1;i>=0;i--){
        sum-=a[i];
        int sum1=sum;
        if(sum%m==0) if(n-i!=n)pairs.pb({n-i,0});
        for(int j=0;j<(n-i) && j<=i;j++){
            sum1-=a[j];
            if(sum1>0 && sum1%m==0) if(n-i+j+1<n) pairs.pb({n-i,j+1});
        }
    }
    // debug(pairs);
    if(pairs.empty()){
        cout<<-1<<'\n';
        return;
    }
    for(auto i:pairs){
        int ans=moves(i.F,i.S);
        if(ans==-1) continue;
        else ans1=min(ans1,ans);
    }
    if(ans1==1e9) cout<<-1<<'\n';
    else cout<<ans1<<'\n';
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int st=1;
    while(st<=1e12){
        powx.insert(st);
        st*=2;
    }
    cout << fixed << setprecision(10);
    
    int tt=1;
    cin >> tt;
    
    while(tt--){
        solve();
    }
}