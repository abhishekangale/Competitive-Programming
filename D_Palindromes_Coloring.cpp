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
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> a(26, 0);
    for(auto i : s){
        a[i-'a']++;
    }
    sort(a.rbegin(), a.rend());
    // int l = 1, r = n;
    // int ans = 1;
    // while(l <= r){
    //     int mid = (l+r)/2;
    //     multiset<int> b;
    //     for(auto i : a){
    //         b.insert(-i);
    //     }
    //     bool f = 1;
    //     for(int i = 0; i < k; i++){
    //         int len = mid;
    //         bool odd = 0;
    //         while(len > 0){
    //             int del = LLONG_MIN;
    //             int fin = -1;
    //             for (auto j : b){
    //                 if ((-j) % 2 == 1 && odd == 0) {
    //                     int need = min(len, (-j));
    //                     del = j;
    //                     fin = j + need;
    //                     len -= need;
    //                     odd = true;
    //                     break;
    //                 }
    //             }
    //             if (del == LLONG_MIN) {
    //                 for (auto j : b) {
    //                     if ((-j) % 2 == 0) {
    //                         int need = min(len, (-j));
    //                         del = j;
    //                         fin = j + need;
    //                         len -= need;
    //                         if (need % 2) odd = 1;
    //                         break;
    //                     }
    //                 }
    //             }
    //             if (del == LLONG_MIN) break;
    //             if (fin < 0) b.insert(fin);
    //             b.erase(b.find(del));
    //         }
    //         if(len){
    //             f = 0;
    //             break;
    //         }
    //     }
    //     if(f){
    //         ans = mid;
    //         l = mid + 1;
            
    //     } 
    //     else r = mid - 1;
    // }
    int ans = 0;
    int twos = 0, ones = 0;
    for(int i=0; i<26; i++){
        twos += (a[i]/2);
        a[i] %= 2;
    }
    if(twos == 0){
        cout << 1 << '\n';
        return;
    }
    ans = (twos/k)*2;
    int remain = twos - ((twos/k)*k);
    
    // debug(remain);
    for(int i=0; i<26; i++){
        ones += (a[i] == 1);
    }

    int x = ones + remain*2;
    if(x >= k)ans++;
    
    cout << max(ans, 1LL) << '\n';
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