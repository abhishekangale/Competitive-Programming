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

struct asked{
    int x,y,z;
    int val;
};
void solve(){
    int n;
    cin >> n;
    int ans = 0;
    int found = 0;
    vi a(n,-1);
    // imp = 0 , crew = 1
    vector<asked> query;
    int prev;
    cout << "? " << 1 << " " << 2 << " " << 3 << endl;
    
    cin >> prev;
    asked fir;
    fir.x = 1, fir.y = 2, fir.z = 3, fir.val = prev;
    query.pb(fir);
     int fi , sd;
    for(int i=1; i<n; i++){
        int x = i, y = i+1, z = i+2;
        x%=n, y%=n, z%=n;
        int nx;
        cout << "? " << x+1 << " " << y+1 << " " << z+1 << endl;
        cin >> nx;
        asked fir;
        fir.x = x+1, fir.y = y+1, fir.z = z+1, fir.val =nx;
        query.pb(fir);
        if(prev == nx){
            continue;
        }
        else {
            found = z;
            int p = (i-1+n)%n , q = x , r = y , s = z;
            a[p] = prev;
            a[s] = nx;
            int ss;
            cout << "? " << p+1 << " " << q+1 << " " << s+1 << endl;
            cin >> ss;
            a[q] = ss;
            cout << "? " << p+1 << " " << r+1 << " " << s+1 << endl;
            cin >> ss;
            a[r] = ss;
            if(a[p]!=a[q]){
                fi=p;sd=q;
            }
            else if(a[p]!=a[r]){
                fi=p;sd=r;
            }
            else if(a[p]!=a[s]){
                fi=p;sd=s;
            }
            break;
        }
    }
    for(int i = query.size() - 1; i>=0; i--){
        if(query[i].x - 1!=-1) continue;
        
    }
    
    for(int i=found+1; i<found+1+n; i++){
        int j = (i%n);
        if(a[j]!=-1) break;
        cout << "? " << fi+1 << " " << sd+1 << " " << j+1 << endl;
        int res;
        cin >> res;
        a[j] = res;
    }
    int sum = 0;
    for(auto i : a){
        sum+=(i==0);
    }
    cout << "! " << sum << " ";
    vi b;
    for(int i=0; i<n; i++){
        if(a[i] == 0) b.pb(i+1);
    }
    for(auto i : b){
        cout << i << " ";
    }
    cout << endl;

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