#include<bits/stdc++.h>
using namespace std;

vector<string> ans;
vector<pair<string,string>> macros;

void catchmacros(vector<string> inp){
    vector<string> all;
    for(auto s : inp){
        stringstream ss(s);
        string word;
        while (ss >> word) {
            all.push_back(word);
        }
    }

    for(int i = 0; i < (int)all.size()-2 ; i++){
        if(all[i] == "#define"){
            macros.push_back({all[i+1], all[i+2]});
        }
    }

}

void removemacros(vector<string> inp){
    for(auto s : inp){
        stringstream ss(s);
        string word;
        while (ss >> word) {
            bool found = 0;
            for(auto macr : macros){
                if(macr.first == word.substr(0, (int)macr.first.size())){
                    cout << macr.second;
                    for(int j = (int)macr.first.size(); j < (int)word.size(); j++){
                        cout << word[j];
                    }
                    cout << " ";
                    found = 1;
                    break;
                }
            }
            if(!found)
                cout << word << ' ';
        }
        cout << '\n';
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

    // removemacros(inp);
    catchmacros(inp);
    removemacros(inp);
    for(auto i : ans){
        cout << i << '\n';
    }
}