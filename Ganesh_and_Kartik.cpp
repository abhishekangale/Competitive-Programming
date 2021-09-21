#include <bits/stdc++.h>
using namespace std;

const int MAXA = 1e7;

vector<int> primes;
int mind[MAXA + 1];

int main() {

    for (int i = 2; i <= MAXA; ++i) {
        if (mind[i] == 0) {
            primes.emplace_back(i);
            mind[i] = i;
        }
        for (auto &x : primes) {
            if (x > mind[i] || x * i > MAXA) break;
            mind[x * i] = x;
        }
    }
    
    int T;
    cin >> T;
    while (T --> 0) {
        int n, k;
        cin >> n;
        vector<int> a(n, 1);
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            int cnt = 0, last = 0;
            while (x > 1) {
                int p = mind[x];
                if (last == p) {
                    ++cnt;
                } else {
                    if (cnt % 2 == 1) a[i] *= last;
                    last = p;
                    cnt = 1;
                }
                x /= p;
            }
            if (cnt % 2 == 1) a[i] *= last;
        }
        
        int L = 0, ans = 1;
        int gg=INT_MIN;
        map<int, int> last;
        for (int i = 0; i < n; ++i) {
            if (last.find(a[i]) != last.end() && last[a[i]] >= L) {
                ++ans;
                gg=max(gg,i-L);
                L = i;
            }

            
            last[a[i]] = i;
        }
        cout << gg << '\n';
    }
    
    return 0;
}