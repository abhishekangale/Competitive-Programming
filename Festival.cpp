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
    int d,n,k;
    cin>>d>>n>>k;
    vector<vector<int>> a(n);
    for(int i=0;i<n;i++){
        int ax,bx,cx;
        cin>>ax>>bx>>cx;
        a.pb({ax,bx,cx});
    }
    
    vector<multiset<vector<int>>> range(d+2);
    for(int i=0;i<n;i++){
        vi hehe=a[i];
        range[a[i][1]].insert(hehe);
        hehe[0]*=-1;
        range[a[i][2]+1].insert(hehe);
    }
    vi ans(d+2,0);
    
    // debug(range);
    multiset<vector<int>> ms;
    multiset<vector<int>, greater<vector<int>>> pq;
    int sum=0;
    for(int i=1;i<=d;i++){
        for(auto j:range[i]){
            if(j[0]>0){
                if(ms.size()<k){
                    ms.insert(j);
                    sum+=j[0];
                    while(1){
                        if(ms.size()==k || pq.empty()) break;
                        auto xd=*pq.begin();
                        sum+=xd[0];
                        ms.insert(xd);
                        pq.erase(xd);
                        
                    }
                }
                else {
                    ms.insert(j);
                    sum+=j[0];
                    auto gg=*ms.begin();
                    sum-=gg[0];
                    ms.erase(gg);
                    
                    pq.insert(gg);
                }
                
            }
            else if(j[0]<0){
                vi hehe=j;
                hehe[0]*=-1;
                if(ms.find(hehe)!=ms.end()){
                    ms.erase(hehe);
                    sum-=hehe[0];
                }
                if(pq.find(hehe)!=pq.end()){
                    pq.erase(hehe);
                }
                
            }
        }
        ans[i]=sum;
        // cerr << i << '\n';
        debug(ms);
        debug(pq);
    }
    // debug(ans);
    int anss=INT_MIN;
    for(int i=1;i<=d;i++){
        anss=max(anss,ans[i]);
    }
    cout<<anss<<'\n';
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cout << fixed << setprecision(10);
    
    int tt=1;
	cin >> tt;
    for (auto case_num = 1; case_num <= tt; ++ case_num) {
        cout << "Case #" << case_num << ": ";
        solve();
    }
}