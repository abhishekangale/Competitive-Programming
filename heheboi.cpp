#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
signed main()
{
    int t = 0;
    cin >> t;
    ll h = (t * (t + 1))/ 2;
    vector<ll> ve;
    set<ll> ve2;
    int count = 0;
    if (h % 2 != 0)
    {
        cout << "NO" << '\n';
    }
    else
    {
      //  int c = 0;
        h = h / 2;
        cout << "YES" << '\n';
        for (int i = 0; i < t; i++)
        {
            ve2.insert(i + 1);
        }
        for (int i = t; i > 0; i--)
        {
            if (h - i >= 0)
            {
                ve.push_back(i) ;
                h -= i;
                ve2.erase(i);
            
            }
        }
       
       cout << (int)ve.size() << '\n';
       sort(ve.begin(),ve.end());
        for (int i = 0; i <  ve.size() ; i++)
        {
            cout << ve[i] << " ";
        }
        cout<<'\n';
        cout << (int)ve2.size() << '\n';
        for (auto i : ve2)
        {
            cout << i << " ";
        }
        cout << '\n';
    }
    
}