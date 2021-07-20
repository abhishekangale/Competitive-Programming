#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// oset Operations: order_of_key(k) -> Number of elements strictly smainter than k, find_by_order(k) -> kth element in the set
 
#define uint unsigned long long int
#define int long long int
#define pb push_back
#define eb emplace_back
#define aint(x) x.begin(),x.end()
#define pii pair<int, int>
#define pint pair<int, int>
#define vi vector<int>
#define vb vector<bool>
#define vd vector<double>
#define vint vector<int>
#define vpii vector<pii>
#define vpint vector<pint>
#define vvi vector<vi>
#define vvint vector<vint>
#define vvb vector<vb>
#define vs vector<string>
#define puint pair<uint, uint>
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
const int N = 18; 
vector<vector<int>> graph,parent;
vector<int> level,ok(100005, -1);
set<int> spec;
vector<vector<int>> par(100005, vector<int>(N, -1));
vector<int> lvl(100005);
void dfs(int u, int par, int lvl) {
    level[u] = lvl;
    parent[u][0] = par;
    for (auto to : graph[u]) {
        if (to == par) continue;
        dfs(to, u, lvl + 1);
    }
}

void dfs2(int u, int par) {
    for (auto to : graph[u]) {
        if (to == par) continue;
        dfs2(to, u);
        if (ok[to] != -1) {
            ok[u] = ok[to];
        }
    }
    if (ok[u] == -1) {
        if (spec.count(u)) {
            ok[u] = u;
        }
    }
}
void solve() {
    int n, k, a;
    cin >> n >> k >> a;
    a--;
    vector<vector<int>> graph(n);
    set<int> spec;
    for (int i = 0; i < k; i++) {
        int temp;
        cin >> temp;
        temp--;
        spec.insert(temp);
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(a, -1, 0);
    for (int level = 1; level < N; level++) {
        for (int i = 0; i < n; i++) {
            if (par[i][level - 1] != -1) {
                par[i][level] = par[par[i][level - 1]][level - 1];
            }
        }
    }
    dfs2(a, -1);
    vector<int> ans1(n), ans2(n);
    for (int node = 0; node < n; node++) {
        if (ok[node] != -1) {
            ans1[node] = lvl[node];
            ans2[node] = ok[node];
            continue;
        }
        int curr = node;
        int last = N - 1;
        while (1) {
            int flag = 0;
            int temp_last;
            for (int lvl = last; lvl >= 0; lvl--) {
                int u = par[curr][lvl];
                temp_last = lvl;
                if (u == -1) continue;
                if (ok[u] == -1) {
                    curr = u;
                    flag = 1;
                    break;
                }
            }
            if (!flag) {
                curr = par[curr][0];
                last = temp_last;
                break;
            }
        }
        int d1 = lvl[curr];
        int d2 = lvl[node] - lvl[curr];
        ans1[node] = d1 - d2;
        ans2[node] = ok[curr];
    }
    for (int i = 0; i < n; i++) {
        cout << ans1[i] << " ";
    }
    cout << '\n';
    for (int i = 0; i < n; i++) {
        cout << ans2[i] + 1 << " ";
    }
    cout << '\n';
    graph.clear();
    parent.clear();
    level.clear();
    ok.clear();
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