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
int side(int x1,int x2,int y1, int y2,int x,int y,int x0,int y0){
   int val1= (((y - y1)*(x2-x1)) - ((y2-y1)*(x - x1)));
   int val2= (((y0 - y1)*(x2-x1)) - ((y2-y1)*(x0 - x1)));
   if(val1*val2 >=0) return 1;
   else return 0;
} 
void solve(){
    vector<pair<int,int>> sq1(4),sq2(4);
    for(auto &i:sq1){
        cin>>i.F>>i.S;
    }
    for(auto &i:sq2){
        cin>>i.F>>i.S;
    }
    int ar1 = (sq1[1].F-sq1[0].F)*(sq1[1].F-sq1[0].F) + (sq1[1].S-sq1[0].S)*(sq1[1].S-sq1[0].S);
    int ar2 = (sq2[1].F-sq2[0].F)*(sq2[1].F-sq2[0].F) + (sq2[1].S-sq2[0].S)*(sq2[1].S-sq2[0].S);
    if(ar1>ar2){
        swap(sq1,sq2);
    }
    int ans=1;
    for(int i=0;i<4;i++){
        int x=sq1[i].F,y=sq1[i].S;
        int x0=sq1[(i-1+4)%4].F,y0=sq1[(i-1+4)%4].S;
        for(int j=0;j<4;j++){
            int x1,y1,x2,y2;
            if(j==0){
                x1=sq2[0].F;
                x2=sq2[3].F;
                y1=sq2[0].S;
                y2=sq2[3].S;
                
            }
            else {
                x1=sq2[i].F;
                x2=sq2[i-1].F;
                y1=sq2[i].S;
                y2=sq2[i-1].S;
            }
            int val = side(x1,x2,y1,y2,x,y,x0,x1);
            debug(val);
            ans&=val;
        }
    }
    cout<<ans;
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