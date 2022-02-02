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

// int KnapSack(vi val, vi wt, int n, int W)
// {
//     // matrix to store final result
//     int mat[2][W+1];
//     memset(mat, 0, sizeof(mat));
 
//     // iterate through all items
//     int i = 0;
//     while (i < n) // one by one traverse each element
//     {
//         int j = 0; // traverse all weights j <= W
 
//         // if i is odd that mean till now we have odd
//         // number of elements so we store result in 1th
//         // indexed row
//         if (i%2!=0)
//         {
//             while (++j <= W) // check for each value
//             {
//                 if (wt[i] <= j) // include element
//                     mat[1][j] = max(val[i] + mat[0][j-wt[i]],
//                                     mat[0][j] );
//                 else           // exclude element
//                     mat[1][j] = mat[0][j];
//             }
 
//         }
//         else
//         {
//             while(++j <= W)
//             {
//                 if (wt[i] <= j)
//                     mat[0][j] = max(val[i] + mat[1][j-wt[i]],
//                                      mat[1][j]);
//                 else
//                     mat[0][j] = mat[1][j];
//             }
//         }
//         i++;
//     }
//     return (n%2 != 0)? mat[0][W] : mat[1][W];
// }
vi op((int)(1e3 + 5), LLONG_MAX);
void pre(){
    op[1] = 0;
    for(int i = 2; i < 1e3 + 5; i++){
        {
            int oper = 0;
            int a = 1, b = i, x = a;
            while(a < b){
                int x = a;
                int l = 1, r = a;
                while(l <= r){
                    int mid = (l+r)/2;
                    if(a + (a/mid) <= b){
                        x = mid;
                        r = mid - 1;
                    }
                    else {
                        l = mid + 1;
                    }
                }
                oper++;
                a += a/x;     
            }
            op[i] = oper;
        }
    }

    for(int i = 2; i < 1e3+5; i++){
        for(int j = 1; j < i; j++){
            int oper = 0;
            int a = j, b = i;
            while(a < b){
                int x = a;
                int l = 1, r = a;
                while(l <= r){
                    int mid = (l+r)/2;
                    if(a + (a/mid) <= b){
                        x = mid;
                        r = mid - 1;
                    }
                    else {
                        l = mid + 1;
                    }
                }
                oper++;
                a += a/x;     
            }
            // debug(j,i,oper);

            op[i] = min(op[i], op[j] + oper);
        }
    }

    
}




void solve(){
    int n, k;
    cin >> n >> k;
    vi oper(n, 0), b(n), c(n);
    for(auto &i : b)cin >> i;
    for(auto &i : c)cin >> i;
    vi a(n, 1);
    for(int i = 0; i < n; i++){
        oper[i] = op[b[i]];
    }

    // debug(oper);
    int most = 0;
    for(auto i : c){
        most += i;
    }
    
    int sum = 0;
    for(auto i : oper){
        sum += i;
    }

    if(k >= sum){
        cout << most << '\n';
        return;
    }
    k = min(k , sum);
    int dp[k + 1];
    memset(dp, 0, sizeof(dp));
 
    for (int i = 0; i < n; i++) {
        for (int w = k; w >= 0; w--) {
            if (oper[i] <= w)
                dp[w] = max(dp[w],
                            dp[w - oper[i]] + c[i]);
        }
    }

    cout << dp[k] << '\n';
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cout << fixed << setprecision(10);
    pre();
    int tt=1;
    cin >> tt;
    
    while(tt--){
        solve();
    }
}