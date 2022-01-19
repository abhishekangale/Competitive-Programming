#include<bits/stdc++.h>
using namespace std;

vector<string> ans;

void removewhitespace(vector<string> inp){
    for(auto s : inp){
        string out;
        bool f = 0;
        for(int i = 0; i < (int)s.size(); i++){
            if(s[i] == ' '){
                continue;
            }
            else {
                out += s[i];
            }
        }
        ans.push_back(out);
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string s;
    bool single = 0, multi = 0;
    vector<string> inp;
    while(getline(cin,s)){
        inp.push_back(s);
    }

    removewhitespace(inp);
    for(auto i : ans){
        cout << i << '\n';
    }
}