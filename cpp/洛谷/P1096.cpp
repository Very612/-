#include<bits/stdc++.h>
using namespace std;
string highMulti(string a,string b){
    string s;
    int la=a.size(),lb=b.size(),c[la+lb]={0},d=la+lb,t=0;
    for(int i=la-1;i>=0;i--){
        for(int j=lb-1;j>=0;j--){
            c[d-i-j-2]+=(a[i]-'0')*(b[j]-'0');
        }
    }
    for(int i=0;i<=d-2;i++){
        c[i]>=10 ? t=c[i],c[i]%=10,c[i+1]+=t/10 :  c[i]=c[i];
    }
    for(int i=0;i<=d-1;i++){
        if(i==d-1&&c[i]==0){
            break;
        }
        s+=c[i]+'0';
    }
    reverse(s.begin(),s.end());
    return s;
}
string mi(int n){
    string res="1",b="2";
    while(n>0){
        if(n&1){
            res=highMulti(res,b);
        }
        b=highMulti(b,b);
        n/=2;
    }
    int cnt=res.size()-1;
    int t=res[cnt]-'0'-1;res[cnt]=t+'0'; 
    return res;
}
int main(){
    int n;
    cin>>n;
    cout<<highMulti(mi(n),"2");
}