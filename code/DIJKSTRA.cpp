#include<bits/stdc++.h>
using namespace std;
int V,E,s;
vector<pair<int,int>> v[1001];
bool visited[1001];
int parents[1001];
void DIJKSTRA(int s){
    vector<int> dp(V+1,1e9);
    dp[s]=0;
    for(auto x:v[s]){
        dp[x.first]=x.second;
    }
    for(int i=1;i<=V;i++) parents[i]=s;
    int n=V;
    while(n>0){
        int res=1e9;
        int u=-1;
        for(int i=0;i<=V;i++){
            if(i!=s&&!visited[i]&&res>dp[i]){
                res=dp[i];
                u=i;
            }
        }
        if(u==-1) break;
        visited[u]=true;
        for(auto x:v[u]){
            if(!visited[x.first]&&dp[x.first]>res+x.second){
                dp[x.first]=res+x.second;
                parents[x.first]=u;
            }
        }
        n--;
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
    memset(parents,0,sizeof(parents));
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