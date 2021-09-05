#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fastIO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define ppb pop_back
#define PI 3.141592653589793238462
#define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) { cerr << t; }
// void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T> void _print(vector <T> v);
template <class T> void _print(vector <T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
// template ends here

int toEast(char dir, int clock, int antiClock) {
    if (dir == 'N') {
        return min(1 * clock, 3 * antiClock);
    }
    if (dir == 'S') {
        return min(3 * clock, 1 * antiClock);
    }
    if (dir == 'W') {
        return min(2 * clock, 2 * antiClock);
    }

    return 0;
}
int toWest(char dir, int clock, int antiClock) {
    if (dir == 'N') {
        return min(3 * clock, 1 * antiClock);
    }
    if (dir == 'S') {
        return min(1 * clock, 3 * antiClock);
    }
    if (dir == 'E') {
        return min(2 * clock, 2 * antiClock);
    }
    return 0;
}

void solve() {
    int testCase = 1;
    cin >> testCase;
    while (testCase--) {
        int n, x, y;
        string s;
        cin >> n >> s >> x >> y;

        int eastArr[n], westArr[n];
        for (int i = 0;i < n;i++) {
            int prevEast = (i - 1 >= 0) ? eastArr[i - 1] : 0;
            eastArr[i] = prevEast + toEast(s[i], x, y);

            int prevWest = (i - 1 >= 0) ? westArr[i - 1] : 0;
            westArr[i] = prevWest + toWest(s[i], x, y);
        }

        int minNum = eastArr[n-1], westMax = westArr[n - 1];
        debug(westMax);
        for (int i = 0;i < n + 1;i++) {
            int westMinus = 0, eastAdd = 0;
            if (i - 1 >= 0 && i - 1 < n) {
                westMinus = westArr[i - 1];
                eastAdd = eastArr[i - 1];
            }

            int temp = westMax - westMinus + eastAdd;
            debug(temp);
            if (temp < minNum) {
                minNum = temp;
            }
        }
        // debug(minNum);
        cout << minNum << endl;
    }
}

signed main() {
    fastIO();
    solve();
    return 0;
}