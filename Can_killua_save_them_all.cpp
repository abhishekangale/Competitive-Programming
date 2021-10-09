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
bool checkPal(int x, int len)
{
    if (x == len)
        return true;
    else if (x > len) {
        if ((x % 2 == 0 && len % 2 == 0)
            || (x % 2 != 0 && len % 2 != 0))
            return true;
    }
    return false;
}
 
// Function to preprocess the string
// for Manacher's Algorithm
string reform(string s)
{
    string s1 = "$#";
 
    // Adding # between the characters
    for (int i = 0; i < s.size(); i++) {
        s1 += s[i];
        s1 += '#';
    }
 
    s1 += '@';
    return s1;
}
 
// Function to find the longest palindromic
// substring using Manacher's Algorithm
bool longestPal(string s, int len)
{
 
    // Current Left Position
    int mirror = 0;
 
    // Center Right Position
    int R = 0;
 
    // Center Position
    int C = 0;
 
    // LPS Length Array
    int P[s.size()] = { 0 };
    int x = 0;
 
    // Get currentLeftPosition Mirror
    // for currentRightPosition i
    for (int i = 1; i < s.size() - 1; i++) {
        mirror = 2 * C - i;
 
        // If currentRightPosition i is
        // within centerRightPosition R
        if (i < R)
            P[i] = min((R - i), P[mirror]);
 
        // Attempt to expand palindrome centered
        // at currentRightPosition i
        while (s[i + (1 + P[i])] == s[i - (1 + P[i])]) {
            P[i]++;
        }
 
        // Check for palindrome
        bool ans = checkPal(P[i], len);
        if (ans)
            return true;
 
        // If palindrome centered at currentRightPosition i
        // expand beyond centerRightPosition R,
        // adjust centerPosition C based on expanded palindrome
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }
 
    return false;
}

void solve(){
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    while(q--){
        int l,r;
        cin >> l >> r;
        --l;--r;
        string test;
        for(int i=l;i<=r;i++){
            test+=s[i];
        }
        int st = test.size();
        test+=test;
        test = reform(test);
        
        bool f = longestPal(test,st);
        if(f) cout<<1<<'\n';
        else cout << 0 << '\n';
    }
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