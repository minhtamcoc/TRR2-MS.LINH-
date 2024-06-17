#include<bits/stdc++.h>
using namespace std;
int V,E;
vector<pair<int,int>> v[1001];
vector<pair<int,int>> T;
bool visited[1001];
void PRIM(int u){
    visited[u]=true;
    int ans=0;
    while(T.size()<V-1){
        int idx=-1;
        int k=-1;
        int res=1e9;
        for(int i=1;i<=V;i++){
            if(visited[i]){
                for(auto x:v[i]){
                    if(!visited[x.first]&&res>x.second){
                        res=x.second;
                        idx=x.first;
                        k=i;
                    }
                }
            }
        }
        visited[idx]=true;
        ans+=res;
        T.push_back({k,idx});
    }
    cout<<ans<<endl;
}
void solve(){
    cin>>V>>E;
    memset(v,0,sizeof(v));
    memset(visited,false,sizeof(visited));
    for(int i=1;i<=E;i++){
        int x,y,z;
        cin>>x>>y>>z;
        v[x].push_back({y,z});
        v[y].push_back({x,z});
    }
    PRIM(1);
    T.clear();
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}