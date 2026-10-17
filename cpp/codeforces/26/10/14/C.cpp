#include<bits/stdc++.h>
using namespace std;
long long T,n,m,a[250100],ans[250100];
int main(){
    cin>>T;
    while(T--){
        long long ans1=0;              
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            ans[i]=ans[i-1]+a[i];
        }
        vector<long long> cnt(m,0);
        for(int j=0;j<=n;j++){
            int i=j-m-1;
            if(i>=0) cnt[ans[i]%m]++;   
            ans1+=cnt[ans[j]%m];       
        }
        cout<<ans1<<'\n';
    }
}
