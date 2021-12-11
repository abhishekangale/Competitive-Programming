#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    // 10^9
    long long sum = 0;
    for(int i=0; i<n; i++){
        sum+=i;
    }

    // O(sqrt(n))
    long long ans = (n*(n+1))/2;
    // O(n) -> O(1)
    // sum of natural number till n = (n*(n+1))/2
    cout << sum;

    return 0;
}