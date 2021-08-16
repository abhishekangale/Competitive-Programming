#include<bits/stdc++.h>
using namespace std;

int main() {

    long long n, k;
    cin >> n >> k;
    long long a[n];
    long long sum = 0;
    for(int i=0 ; i < n ; i++){
        cin >> a[i];
    }

    sort(a , a+n);

    reverse(a , a+n);
    
    for(int i=0 ; i < k ; i++) {

        if(a[i] >= 0) {
            sum += a[i];
        }
        else {
            break;
        }
    }

    cout << sum;

    return 0;
}