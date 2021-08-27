#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e6;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    ll c = 0;
    cin >> n;
    vector<ll> v(n);
    //vector<ll>V(n);
    ll g = 0;
    for(ll &i : v) cin >> i;

    if (v[0] > 0)
    {
        g = 0;
    }
    else
    {
        g = 1;
    }
    //ll j = n - 1;

    for (ll i = 1; i < n ; i++)
    {

        if (g == 0)
        {
            if (v[i] < 0)
            {
                g = 1;
            }
            else
            {
                c++;
                g = 1;
            }
        }
        else
        {
            if (v[i] > 0)
            {
                g = 0;
            }
            else
            {
                c++;
                g = 0;
            }
        }
    }

    ll c1=0;

    if (v[0] < 0)
    {
        g = 0;
    }
    else
    {
        g = 1;
    }

    for (ll i = 1; i < n ; i++)
    {

        if (g == 0)
        {
            if (v[i] > 0)
            {
                g = 1;
            }
            else
            {
                c1++;
                g = 1;
            }
        }
        else
        {
            if (v[i] < 0)
            {
                g = 0;
            }
            else
            {
                c1++;
                g = 0;
            }
        }
    }
    cout<<c1<<'\n';
    cout << min(c,c1);
}