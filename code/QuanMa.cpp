#include<bits/stdc++.h>
using namespace std;
int dx[8]={-1,-1,1,1,2,2,-2,-2};
int dy[8]={2,-2,2,-2,-1,1,1,-1};
void solve(int x1,int y1,int x2,int y2){
    queue<pair<int,int>> q;
    int c[10][10];
    memset(c,-1,sizeof(c));
    q.push({x1,y1});
    c[x1][y1]=0;
    while(!q.empty()){
        pair<int,int> tmp=q.front();
        q.pop();
        int x=tmp.first;
        int y=tmp.second;
        for(int k=0;k<8;k++){
            int u=x+dx[k];
            int t=y+dy[k];
            if(c[u][t]==-1&&u>=1&&u<=8&&t>=1&&t<=8){
                c[u][t]=c[x][y]+1;
                q.push({u,t});
            }
        }
        if(c[x2][y2]!=-1) break;
    }
    cout<<c[x2][y2]<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string a,b;
        cin>>a>>b;
        int x1=a[0]-96;
        int y1=a[1]-'0';
        int x2=b[0]-96;
        int y2=b[1]-'0';
        solve(x1,y1,x2,y2);
    }
    return 0;
}