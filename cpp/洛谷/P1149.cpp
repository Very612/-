#include<bits/stdc++.h>
using namespace std;
long long ans=0,a[10]={6,2,5,5,4,5,6,3,7,6},n;
int judge(int n){
    int k=0;
    if(n>=10){
        while(n>0){
            k+=a[n%10],n/=10;
        }
    }else{
        k+=a[n];
    }
    return k;
}
int main(){
    cin>>n;
    for(int i=0;i<=1000;i++){
        int cnt=judge(i),t=cnt;
        for(int j=i;j<=1000;j++){
            cnt+=judge(j);cnt+=judge(i+j);
            if(cnt==n-4){
                i==j ? ans+=1 : ans+=2;
            }
            cnt=t;
        }
    }
    cout<<ans;
}