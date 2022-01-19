#include<bits/stdc++.h>
using namespace std;

const long long mx = 1e9;

signed main(){

    long long tt;
    cin >> tt;
    while(tt--){
        long long a, b, k, l, r, len, c[100], val, cnt, result, pos, number[100], st[100];
        cin >> a >> b >> k;
        
        memset(c, 0, sizeof(c));
        memset(number, 0, sizeof(number));
        memset(st, 0, sizeof(st));

        string intera = to_string(a);
        string interb = to_string(a + b*mx);

        long long lowdig = (int)intera.size(), highdig = (int)interb.size(), L = 0, R = mx;

        for(long long i = lowdig; i <= highdig; i++){
            long long l = L, r = R;
            while(r-l-1 > 0){
                long long m = (l + r)/2;
                string inter = to_string(a+(m*b));
                if((int)inter.size()>i) r = m;
                else l = m;
            }
            for(long long m=min(r + 10, R); m >= max(L, r-10); m--){
                string inter = to_string(a+m*b);
                if((int)inter.size() == i){
                    number[i] = L;
                    c[i] = (m - L + 1);
                    L = m+1;
                    break;
                }
                if(R < L)break;
            }
        }

        long long ans = 0;

        for(long long i=lowdig; i<=highdig; i++){
            ans += c[i] * i;
            if(ans >= k){
                ans-=c[i] * i;
                k-=ans;
                pos = k / i;
                if(k % i != 0) {
                    cnt = 0;
                    k %= i;
                    val = a + b * (number[i] + pos);
                    while(val > 0){
                        st[cnt] = val % 10;
                        val /= 10;
                        cnt++;
                    }
                    reverse(st, st + cnt);
                    result = st[k - 1];
                }
                else {
                    val = a + b * (number[i] + pos - 1);
                    result = val % 10;
                }

                cout<< result << '\n';
                break;
            }
        }
    }

    return 0;
}