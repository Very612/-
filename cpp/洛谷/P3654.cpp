#include<bits/stdc++.h>
using namespace std;
int r,c,k,x[4]={-1,0,1,0},y[4]={0,1,0,-1},ans;
char a[150][150];
queue<pair<int,int>>q;
map<pair<int,int>,bool>p;
bool judge(int x,int y){
    if(x<0||x>=r||y<0||y>=c){
        return 0;
    }
    return 1;
}
int main(){
    cin>>r>>c>>k;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>a[i][j];
            if(a[i][j]=='.'){
                q.push({i,j});
            }
        }
    }
    while(!q.empty()){
        auto t=q.front();q.pop();
        int t1=t.first,t2=t.second,cnt=1;
        p[{t1,t2}]=1;
        if(cnt<k){
            for(int i=0;i<4;i++){
                cnt=1;
                int x1=t1+x[i],y1=t2+y[i];
                if(!judge(x1,y1)||p[{x1,y1}]){continue;}
                if(a[x1][y1]=='.'){
                    cnt++;
                    while(cnt<k){
                        x1+=x[i],y1+=y[i];
                        if(!judge(x1,y1)||a[x1][y1]!='.'){break;}
                        cnt++;
                    }
                }               
                if(cnt>=k){
                    ans++;
                }
            }
        }else{
            ans++;
        }
    }
    cout<<ans;
}