#include<bits/stdc++.h>
using namespace std;

string encode(string s){
    string ans;
    int n = (int)s.size(); 
    for(int i=0; i<n; i++){
        if(s[i]=='1') {
            ans += "10";
        }
        else {
            ans += "01";
        }
    }
    return ans;
}

string decode(string s){
    string ans;
    int n = (int)s.size(); 
    for(int i=0; i+1<n; i+=2){
        if(s[i]=='0' && s[i+1]=='1') {
            ans += '0';
        }
        else {
            ans += '1';
        }
    }
    return ans;
}

int main() {
    int check;
    cout << "Enter 1 to encode bitstream, 2 to decode it: ";
    cin >> check;
    if(check == 1){
        cout << "Enter bitstream to encode:\n";
        string s;
        cin >> s;
        string enc = encode(s);
        cout << "Encoded string is:\n";
        cout << enc << '\n';
        return 0;
    }
    else if(check == 2){
        cout << "Enter bitstream to decode:\n";
        string s;
        cin >> s;
        string enc = decode(s);
        cout << "Decoded string is:\n";
        cout << enc << '\n';
        return 0;
    }
    else {
        cout <<"Wrong choice\n";
        return 0;
    }
    return 0;
}