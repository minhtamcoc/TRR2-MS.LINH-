#include<bits/stdc++.h>
using namespace std;
int n;
char a[101][101];
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    int c[n+1][n+1];
    memset(c,-1,sizeof(c));
    c[x1][y1]=0;
    queue<pair<int,int>> q;
   if(a[x1][y1]!='X'&&a[x2][y2]!='X') q.push({x1,y1});
    while(!q.empty()){
        pair<int,int> tmp=q.front();
        int i=tmp.first;
        int j=tmp.second;
        q.pop();
        int cnt=0;
        for(int k=i-1;k>=0;k--){ // len tren
            if(a[k][j]!='X'&&c[k][j]==-1){
                q.push({k,j});
                c[k][j]=c[i][j]+1;
            }
            else break;
        }
        for(int k=i+1;k<n;k++){ // xuong duoi
            if(a[k][j]!='X'&&c[k][j]==-1){
                q.push({k,j});
                c[k][j]=c[i][j]+1;
            }
            else break;
        }
        for(int k=j-1;k>=0;k--){
            if(a[i][k]!='X'&&c[i][k]==-1){
                q.push({i,k});
                c[i][k]=c[i][j]+1;
            }
            else break;
        }   
        for(int k=j+1;k<n;k++){
            if(a[i][k]!='X'&&c[i][k]==-1){
                q.push({i,k});
                c[i][k]=c[i][j]+1;
            }
            else break;
        }
        if(c[x2][y2]!=-1) break;
    }   
    cout<<c[x2][y2]<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}