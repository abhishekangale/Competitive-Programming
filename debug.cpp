#include<bits/stdc++.h>
using namespace std;

int main(){
    int h,m,h1,m1;
    cin >> h >> m >> h1 >> m1;
    int x;
    cin >> x;
    int time1 = h*60 + m;
    int time2 = h1*60 + m1;
    cout << x*60 - (time2-time1);
}