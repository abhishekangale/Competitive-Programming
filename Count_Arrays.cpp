#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define FOR(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define FORL(i, a, n) for (int(i) = (a); (i) <= (n); (i)++)
#define FORR(i, a, n) for (int(i) = (a); (i) >= (n); (i)--)
#define FORSQ(i, a, n) for (int(i) = (a); (i) * (i) <= (n); ++(i))
#define FOREACH(a, b) for (auto &(a) : (b))
#define all(v) v.begin(), v.end()
#define SORT(v) sort(ALL(v))
#define log(args...)                             \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
    }
#define logcontainer(container)   \
    for (auto &(e) : (container)) \
        cout << (e) << " ";       \
    cout << endl;
void err(istream_iterator<string> it)
{
}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout << *it << " = " << a << endl;
    err(++it, args...);
}

typedef long long int ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> pll;
typedef vector<pll> vll;
typedef vector<bool> vb;
typedef priority_queue<ll> maxheap;
typedef priority_queue<ll, vl, greater<ll>> minheap;
typedef map<ll, ll> mapll;

const ll inf = 1e18;
const ll mod = 1e9 + 7;
const ll maxn = 2e6 + 5;

struct SCC
{
    ll n;
    vl todo, comp, comps;
    vb vis;
    map<ll, vl> mp;
    vl sz;
    SCC(vvl &adj, vvl &radj)
    {
        n = adj.size();
        comp.resize(n, -1);
        vis.resize(n);
        init(adj, radj);
        FOR(i, n) { mp[comp[i]].push_back(i); }
    }
    void dfs1(ll x, vvl &adj)
    {
        vis[x] = 1;
        FOREACH(y, adj[x])
        {
            if (!vis[y])
                dfs1(y, adj);
        }
        todo.push_back(x);
    }
    void dfs2(ll x, ll v, vvl &radj)
    {
        comp[x] = v;
        FOREACH(y, radj[x])
        {
            if (comp[y] == -1)
                dfs2(y, v, radj);
        }
    }
    void init(vvl &adj, vvl &radj)
    {
        FOR(i, n)
        {
            if (!vis[i])
            {
                dfs1(i, adj);
            }
        }
        reverse(all(todo));
        FOREACH(x, todo)
        {
            if (comp[x] == -1)
            {
                dfs2(x, x, radj), comps.push_back(x);
            }
        }
    }
    void print()
    {

        FOREACH(e, mp)
        {
            if((int)e.second.size() <= 1)continue;
            sz.push_back(e.second.size());
        }
    }
};

unsigned long long power(unsigned long long x,
                                  int y, int p)
{
    unsigned long long res = 1; // Initialize result
 
    x = x % p; // Update x if it is more than or
    // equal to p
 
    while (y > 0)
    {
     
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;
 
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
 
// Returns n^(-1) mod p
unsigned long long modInverse(unsigned long long n, 
                                            int p)
{
    return power(n, p - 2, p);
}
 
// Returns nCr % p using Fermat's little
// theorem.
unsigned long long npr(unsigned long long n,
                                 int r, int p)
{
    // If n<r, then nCr should return 0
    if(r == 0)return 1;
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;
 
    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    unsigned long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;
 
    return ((fac[n] % p
            * modInverse(fac[n - r], p) % p))
           % p;
}
 

void yash56244()
{
    ll n, m;
    cin >> n >> m;
    vvl adj(n), radj(n);
    FOR(i, n)
    {
        ll a;
        cin >> a;
        adj[a - 1].push_back(i);
        radj[i].push_back(a - 1);
    }
    SCC scc(adj, radj);
    scc.print();
    auto vecc = scc.sz;
    int sum = 0;
    for(auto i : vecc)sum += i;
    ll ans = 1;
    // logcontainer(vecc);
    for(auto i : vecc){
        ans *= npr(m, i, mod);
        ans %= mod;
    }
    
    ans *= power(m - 1, n - sum, mod);
    ans %= mod;
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
    {
        yash56244();
    }
    return 0;
}