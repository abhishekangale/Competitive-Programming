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
vector<char> vow = {'a', 'e', 'i', 'o', 'u'};
int cntvowel(string s){
    int cnt = 0;
    for(auto i : s){
        for(auto j : vow){
            cnt += (i == j);
        }
    }
    return cnt;
} 

void solve(){
    int n;
    cin >> n;
    vector<string> a(n);

    map<int, multiset<string>> c[5];
    map<int, vector<string>> b;
    for(auto &i : a){
        cin >> i;
        int cnt = cntvowel(i);
        int m = (int)i.size();
        bool f = 0;
        for(int j = m - 1; j >= 0; j--){
            for(int k = 0; k < 5; k++){
                if(vow[k] == i[j]){
                    c[k][cnt].insert(i);
                    f = 1;
                    break;
                }
            }   
            if(f)break;
        }
    }

    vector<pair<string,string>> same, diff;

    for(int i = 0; i < 5; i++){
        for(auto &inf : c[i]){
            while(inf.S.size() >= 2){
                string s = *inf.S.begin();
                inf.S.erase(inf.S.begin());
                string t = *inf.S.begin();
                inf.S.erase(inf.S.begin());
                same.pb({s, t});
            }
        }
    }

    for(int i = 0; i < 5; i++){
        for(auto inf : c[i]){
            for(auto s : inf.S){
                b[inf.F].pb(s);
            }
        }
    }

    for(auto i : b){
        for(int j = 0; j+1 < (int)i.S.size(); j+=2){
            diff.pb({i.S[j], i.S[j+1]});
        }
    }

    // debug(same);
    // debug(diff);

    if((int)same.size() == 0){
        cout << 0;
        return;
    }

    vector<string> ans;
    while(!diff.empty() && !same.empty()){
        auto x = diff.back();
        auto y = same.back();
        string ff = x.F + " " + y.F + '\n' + x.S + ' ' + y.S + '\n';
        ans.pb(ff);
        diff.pop_back();
        same.pop_back();
    }

    while(same.size() >= 2){
        auto x = same.back();
        same.pop_back();
        auto y = same.back();
        same.pop_back();
        string ff = x.F + " " + y.F + '\n' + x.S + ' ' + y.S + '\n';
        ans.pb(ff);
    }

    cout << (int)ans.size() << '\n';
    for(auto i : ans)cout << i;


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