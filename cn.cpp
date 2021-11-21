#include<bits/stdc++.h>
using namespace std;
int main(){
    
  	int tt;
    cin >> tt;
    for(int _=0; _<tt; _++){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int mul = 0;
        for(int i=1; i<n; i++){
            if(s[i]==s[i-1])mul++;
        }
        reverse(s.begin(),s.end());
        int ans = 0;
        while(!s.empty()){
            cout << s << '\n';
            cout << mul << '\n';
            ans++;
			if(s.size()<=2) break;
            int cnt = 0;
            if(mul <= 0 ){
                while(s[s.size()-1]==s[s.size()-2]) {s.pop_back();}
                s.pop_back();
            }
            else{
                mul--;
                int x = s.size(),xd=0;
                while(s[x-1]==s[x-2] && x>=2){x--;xd++;}
                if(xd)s.pop_back();
            }
            if(s.size()<=1) break;
            while(s[s.size()-1]==s[s.size()-2]) {s.pop_back();cnt++;}
            s.pop_back();
            mul-=cnt;
            
        }
        cout << ans << '\n';
    }
    return 0;
}