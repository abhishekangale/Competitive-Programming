#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    string s1;
    int n = s.size();
    for(int i=0; i<n; i++){
        s1+=s[i];
        int temp = stoll(s1);
        temp = temp%7;
        s1 = to_string(temp);
    }
    cout << s1;
    
    return 0;
}