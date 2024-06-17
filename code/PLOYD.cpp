#include<bits/stdc++.h>
using namespace std;
int D[105][105];
int main(){
   int V,E;
   cin>>V>>E;
   for(int i=1;i<=V;i++){
    for(int j=1;j<=V;j++){
        D[i][j]=1e9;
    }
        D[i][i]=0;
   }
   for(int i=1;i<=E;i++){
        int x,y,z;
        cin>>x>>y>>z;
        D[x][y]=D[y][x]=z;
   }
for(int k=1;k<=V;k++){
    for(int i=1;i<=V;i++){
        for(int j=1;j<=V;j++){
            if(D[i][j]>D[i][k]+D[k][j]){
                D[i][j]=D[i][k]+D[k][j];
            }
        }
    }
}
    int t;
    cin>>t;
    while(t--){
        int u,v;
        cin>>u>>v;
        cout<<D[u][v]<<endl;
    }
    return 0;
}