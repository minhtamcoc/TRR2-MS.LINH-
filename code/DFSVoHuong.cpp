#include<bits/stdc++.h>
using namespace std;
int V,E,s;
vector<pair<int,int>> v[1001];
bool visited[1001];
void DIJKSTRA(int s){
    int dp[1001];
    int parents[1001];
    for(int i=1;i<=V;i++){
        dp[i]=1e9;
        parents[i]=s;
    }
    dp[s]=0;
    int n=V;
    while(n--){
        int du=1e9;
        int idx=-1;
        for(int i=1;i<=V;i++){
            if(!visited[i]&&du>dp[i]){
                du=dp[i];
                idx=i;
                
            }
        }
        visited[idx]=true;
        if(idx==-1) break;
        for(auto x:v[idx]){
            if(!visited[x.first]&&dp[x.first]>du+x.second){
                dp[x.first]=du+x.second;
                parents[x.first]=idx;
            }
        }
    }
    for(int i=1;i<=V;i++){
        int idx=i;
        while(idx!=s){
            cout<<idx<<"<-";
            idx=parents[idx];
        }
        cout<<s<<":"<<dp[i]<<endl;
    }
}
void solve(){
    cin>>V>>E>>s;
    memset(v,0,sizeof(v));
    memset(visited,false,sizeof(visited));
    for(int i=1;i<=E;i++){
        int x,y,z;
        cin>>x>>y>>z;
        v[x].push_back({y,z});
        v[y].push_back({x,z});
    }
    DIJKSTRA(s);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}