#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ull unsigned long long int
#define int long long int
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
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

const int mod = 1e9 + 7;
int possible_part(vector<int> arr, int n)
{
    int sum = 0;
    int i, j;
    for (i = 0; i < n; i++)
        sum += arr[i];
    if (sum % 2 != 0)
        return 0;
    bool part[n + 1][sum / 2 + 1];
    for (i = 0; i <= sum / 2; i++)
        part[0][i] = 0;
    for (i = 0; i <= n; i++)
        part[i][0] = 1;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= sum / 2; j++)
        {
            part[i][j] = part[i - 1][j];
            if (j >= arr[i - 1])
                part[i][j] = part[i][j] ||
                             part[i - 1][j - arr[i - 1]];
        }
    }

    return part[n][sum / 2];
}

void solve()
{
    int n;
    cin >> n;
    vi z;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        z.pb(x);
    }
    if (possible_part(z, n) == 1)
    {
        for (int i = 0; i < n; i++)
        {
            vector<int> b = z;
            b.erase(b.begin() + i);
            if (possible_part(b, n - 1) == 0)
            {
                cout << 1;
                cout << '\n';
                cout<<i+1;
                return;
            }
        }
    }
    cout << 0;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << fixed << setprecision(10);

    int tt = 1;
    //cin >> tt;

    while (tt--)
    {
        solve();
    }
}