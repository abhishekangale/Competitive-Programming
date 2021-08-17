#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {    
    ll n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int x = 0, y = n-1;

    for(int k = 0; k < n; k++){
        if(k%2==0){
            cout << a[x] <<" ";
            x++;
        }
        else {
            cout << a[y] << " ";
            y--;
        }
    }

    return 0;
}