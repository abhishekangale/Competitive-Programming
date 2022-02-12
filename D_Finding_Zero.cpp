#include <bits/stdc++.h>

using namespace std;

// #define endl "\n"
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

void yash56244()
{
    int n;
    cin >> n;
    int pos = 3, mx = 0, cnt = 0;
    bool f = 0;
    for(int i = 0; i <= n - 3; i++){
        int ind;
        cout << "? 1 2 " << (i + 3) << endl;

        cin >> ind;
        if(ind == mx){
            cnt++;
        }
        else if(ind > mx){
            ind = max(ind, mx);
            pos = (i + 3);
            cnt = 1;
        }
        if(cnt == n - 2){
            f = 1;
	    }

    }
    
    if(f){
        cout << "! 1 2" << endl;
        return;
	}

    int query = pos;
    cnt = 1;
    for(int i = 2; i <= n; i++){
        if(i != query){
            int ind;
            cout << "? 1 " << query << " " << i << endl;
            cin >> ind;
            if(ind == mx){
                cnt++;
            }
            else if(ind > mx){
                ind = max(ind, mx);
                pos = i;
                cnt = 1;
            }
        }
    }
    if(cnt == n - 2)pos = 1;

    cout << "! " << query << " " << pos << endl; 
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