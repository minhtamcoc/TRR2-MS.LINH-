#include<bits/stdc++.h>
using namespace std;
int V,E,u;
vector<pair<int,int>> v[1001];
int parents[1001];
void BELLMAN_FORD(int u){
    vector<int> dp(V+1,1e9);
    dp[u]=0;
    for(int i=1;i<=V;i++) parents[i]=u;
    for(int k=1;k<=V-1;k++){
        for(int i=1;i<=V;i++){ // u truoc
                for(auto x:v[i]){
                    if(dp[x.first]>dp[i]+x.second){
                        dp[x.first]=dp[i]+x.second;
                        parents[x.first]=i;
                    }
                }
            }
        }
    for(int i=1;i<=V;i++){
        int idx=i;
        while(u!=idx){
            cout<<idx<<"<-";
            idx=parents[idx];
        }
        cout<<u<<":" <<dp[i]<<endl;
    }
}
void solve(){
    cin>>V>>E>>u;
    memset(v,0,sizeof(v));
    memset(parents,0,sizeof(parents));
    for(int i=1;i<=E;i++){
        int x,y,z;
        cin>>x>>y>>z;
        v[x].push_back({y,z});
    }
    BELLMAN_FORD(u);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}