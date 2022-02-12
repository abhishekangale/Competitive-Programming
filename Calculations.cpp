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
int sum(int n , vi &a){
    int ans = -(a[n+2]*a[n+2]) - 4*(a[n+1]*a[n+1]) - 5*(a[n]*a[n]) + 4*a[n+2]*a[n+1] + 2*a[n+2]*a[n] + 1;
    ans /= 4;
    return ans;
}

void multiply(int T[3][3], int M[3][3])
{
    int a, b, c, d, e, f, g, h, i;
    a = T[0][0] * M[0][0] +
        T[0][1] * M[1][0] +
        T[0][2] * M[2][0];
    b = T[0][0] * M[0][1] +
        T[0][1] * M[1][1] +
        T[0][2] * M[2][1];
    c = T[0][0] * M[0][2] +
        T[0][1] * M[1][2] +
        T[0][2] * M[2][2];
    d = T[1][0] * M[0][0] +
        T[1][1] * M[1][0] +
        T[1][2] * M[2][0];
    e = T[1][0] * M[0][1] +
        T[1][1] * M[1][1] +
        T[1][2] * M[2][1];
    f = T[1][0] * M[0][2] +
        T[1][1] * M[1][2] +
        T[1][2] * M[2][2];
    g = T[2][0] * M[0][0] +
        T[2][1] * M[1][0] +
        T[2][2] * M[2][0];
    h = T[2][0] * M[0][1] +
        T[2][1] * M[1][1] +
        T[2][2] * M[2][1];
    i = T[2][0] * M[0][2] +
        T[2][1] * M[1][2] +
        T[2][2] * M[2][2];
    T[0][0] = a;
    T[0][1] = b;
    T[0][2] = c;
    T[1][0] = d;
    T[1][1] = e;
    T[1][2] = f;
    T[2][0] = g;
    T[2][1] = h;
    T[2][2] = i;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            T[i][j] %= mod;
            M[i][j] %= mod;
        }
    }
}
void power(int T[3][3], int n)
{
    if (n == 0 || n == 1)
        return;
    int M[3][3] = {{ 1, 1, 1 },
                   { 1, 0, 0 },
                   { 0, 1, 0 }};
    power(T, n / 2);
    multiply(T, T);
    if (n % 2)
        multiply(T, M);
}
int tribonacci(int n)
{
    int T[3][3] = {{ 1, 1, 1 },
                   { 1, 0, 0 },
                   { 0, 1, 0 }};
    if (n == 0 || n == 1)
        return 0;
    else
        power(T, n - 2);
    return T[0][0];
}

void solve(){
    int n;
    cin >> n;
    vi a(n, -1);
    a[0] = 3, a[1] = 2, a[2] = 1;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == -1)a[i] = a[i-1] + a[i-2] + a[i-3];
        a[i] %= mod;
        ans += a[i]*a[i];
        ans %= mod;
        debug(tribonacci(i+2), a[i]);
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