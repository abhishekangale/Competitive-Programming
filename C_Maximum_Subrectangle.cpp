#include <bits/stdc++.h>
using namespace std;

#define for0(i, n) for (int i = 0; i < (int)(n); i++)
#define for1(i, n) for (int i = 1; i <= (int)(n); i++)
#define forc(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)
#define forr0(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define forr1(i, n) for (int i = (int)(n); i >= 1; --i)
#define deb(x) cout << #x << "=" << x << endl
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define tr(x) for(auto it = x.begin(); it != x.end(); it++)
#define fast ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define printclock cerr<< "Time : "<< 1000*(ld) clock()/(ld)CLOCKS_PER_SEC<< "ms\n";
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define inf 1e18
#define mod (long long int)1e6 + 3

typedef long long ll;
typedef pair<int, int> pi;

// void dk_98() {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
// }

bool sorted(int arr[], int n) {
    for (int i = 0; i + 1 < n; i++) {
        if (arr[i + 1] < arr[i]) return false;
    }
    return true;
}

void solve() {
    int n, m; cin >> n >> m;
    int a[n], b[m];
    for0(i, n) cin >> a[i];
    for0(i, m) cin >> b[i];
    ll x; cin >> x;
    ll apref[n], bpref[m];
    apref[0] = a[0]; bpref[0] = b[0];
    for (int i = 1; i < n; i++) apref[i] = apref[i - 1] + a[i];
    for (int i = 1; i < m; i++) bpref[i] = bpref[i - 1] + b[i];
    vector<pair<ll, ll> > vec1, vec2;
    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            ll sum = apref[r];
            if (l > 0) sum -= apref[l - 1];
            vec1.push_back(mp(sum, r - l + 1));
        }
    }
    for (int l = 0; l < m; l++) {
        for (int r = l; r < m; r++) {
            ll sum = bpref[r];
            if (l > 0) sum -= bpref[l - 1];
            vec2.push_back(mp(sum, r - l + 1));
        }
    }
    sortall(vec1); sortall(vec2);
    /*tr(vec1) {
        cout << it->first << " " << it->second << '\n';
    }
    cout << '\n';
    tr(vec2) {
        cout << it->first << " " << it->second << '\n';
    }
    cout << '\n';*/
    ll ans = 0;
    for0(i, vec2.size()) {
        double req =  (double)x / (double)vec2[i].first;
        ll lb = upper_bound(all(vec1), mp(req,2005)) - vec1.begin();
        lb--;
        // deb(req);
        // deb(lb);
        // deb(vec2[i].second * vec1[lb].second);
        if (lb < 0) continue;
        else ans = max(ans, vec2[i].second * vec1[lb].second);
    }
    cout << ans;
}

int main() {
    fast;
    int t = 1; //cin >> t;
    while (t--) {
        solve();
        cout << "\n";
    }
}
