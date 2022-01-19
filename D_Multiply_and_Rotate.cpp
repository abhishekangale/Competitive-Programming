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
// int ans = LLONG_MAX;
// void recurse(int n,int a, int oper){
//     debug(n);
//     if(n==1){
//         ans = min(ans, oper);
//     }
//     if(n < 1)return;
//     string xd = to_string(n);
//     set<int> track;
//     int sz = (int)xd.size();
//     int rotated = 0;
//     while(sz--){
//         if(xd[0] == '0'){
//             rotated++;
//             continue;
//         }
//         int num = stoll(xd);
//         if(num % a == 0){
//             recurse(num/a, a, oper+rotated+1);
//         }
//         rotate(xd.begin(), xd.begin()+1, xd.end());
//         rotated++;
//     }
//     return;
// }

void solve(){
    int a,n;
    cin >> a >> n;
    vi dp(10000005, LLONG_MAX);

    queue<pair<int,int>> q;
    q.push({n, 0LL});

    while (!q.empty()) {
        auto t = q.front(); q.pop();

        if (t.F >= 10 && to_string(t.F)[1] != '0') {
            string ts = to_string(t.F);
            string ts2 = ts.substr(1, (int)(ts.size() - 1)) + ts[0];
            int tl = stoll(ts2);
            if (dp[tl] > t.S + 1) {
                dp[tl] = t.S + 1;
                q.push({tl, t.S + 1});
            }
        }

        if (t.F % a == 0) {
            int ti = t.F / a;
            if (ti == 1) {
                cout << t.S + 1;
                return;
            }
            if (dp[ti] > t.S + 1) {
                dp[ti] = t.S + 1;
                q.push({ti, t.S + 1});
            }
        }
    }

    cout << -1 << '\n';

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