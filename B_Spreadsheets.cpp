#include "bits/stdc++.h"
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
    string s;
    cin>>s;
    vi v;
    for(int i=1;i<(int)s.size();i++){
        if(s[i]<='9' && s[i]>='0'){
            if(s[i-1]>'9' || s[i-1]<'0'){
                v.pb(1);
            }
        }
    }
    // debug(v);
    if(v.size()<=1){
        int i=0;
        string s1;
        string ans;
        int num=0;
        while(s[i]>'9' || s[i]<'0'){
            s1+=s[i];
            i++;
        }
        reverse(all(s1));
        int m=s1.size();
        for(int j=0;j<m;j++){
            num+=(s1[j]-'A'+1)*pow(26,j);
        }
        ans+='R';
        for(i;i<s.size();i++){
            ans+=s[i];
        }
        ans+='C';
        ans+=to_string(num);
        cout<<ans<<'\n';

    }
    else {
        int i=1;
        string ans;
        string s2;
        while(s[i]<='9' && s[i]>='0'){
            s2+=s[i];
            i++;
        }
        string s3;
        i++;
        // debug(s2);
        for(i;i<s.size();i++){
            s3+=s[i];
        }
        int gg=stoll(s3);
        string ans2;
        // debug(gg);
        int j=0;
        while(gg>0){
            ans2+=char((gg%26+'A'-1));
            gg/=26;
            j++;
        }
        reverse(all(ans2));
        ans2+=s2;
        cout<<ans2<<'\n';
    }
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