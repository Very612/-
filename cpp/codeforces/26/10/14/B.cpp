#include<bits/stdc++.h>
using namespace std;
int T,l;string s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>s;
        l=s.size();
        bool p=false,m=false;
        for(int i=1;i<l-1;i++){
            if(s[i-1]==s[i+1]){
                if(s[i]==s[i-1]) p=true;
                else m=true;
                if(p&&m) break;
            }
        }
        cout<<1+p+m<<'\n';
    }
    return 0;
}
