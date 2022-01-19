#include<bits/stdc++.h>
using namespace std;

vector<string> ans;
// hi there
/* this is a 
    multiline cmt */
void removecomment(vector<string> inp){
    bool multi = 0;
    for(auto s : inp){
        string out;
        bool single = 0;
        for(int i = 0; i < (int)s.size(); i++){
            if(i + 1 < (int)s.size()){
                if(s[i] == '/' && s[i+1] == '/'){
                    single = 1;
                }
                if(s[i] == '/' && s[i+1] == '*'){
                    multi = 1;
                }
                if(s[i] == '*' && s[i+1] == '/'){
                    multi = 0;
                    i+=2;
                    continue;
                }
            }
            
            if(single || multi){
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

    removecomment(inp);
    for(auto i : ans){
        cout << i << '\n';
    }
}