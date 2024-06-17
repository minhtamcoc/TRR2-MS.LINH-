#include<bits/stdc++.h>
using namespace std;
int V,E;
vector<int> v[1001];// danh sach ke
bool visited[1001];
vector<pair<int,int>> canh;
void DFS(int u,int a,int b){
    visited[u]=true;
    for(auto x:v[u]){
         if((x==a&&u==b)||(x==b&&u==a)) continue;
        if(!visited[x]){
            DFS(x,a,b);
        }
    }
}
void BFS(int u,int a,int b){
    queue<int> q;
    q.push(u);
    visited[u]=true;
    while(!q.empty()){
        int k=q.front();
        q.pop();
        for(auto x:v[k]){
            if((x==a&&k==b)||(k==a&&x==b)) continue;
            if(!visited[x]){
                visited[x]=true;
                q.push(x);
            }
        }
    }
}
void solve(){
    cin>>V>>E;
    memset(v,0,sizeof(v));
    canh.clear();
    for(int i=1;i<=E;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
        canh.push_back({x,y});
    }
    for(auto x:canh){
        int a=x.first;
        int b=x.second;
        int cnt=0;
        memset(visited,false,sizeof(visited));
        for(int i=1;i<=V;i++){
            if(!visited[i]){
                cnt++;
                BFS(i,a,b);
            }
        }
        if(cnt>1){
            if(a>b) cout<<b<<" "<<a<<" ";
            else cout<<a<<" "<<b<<" ";
        }
    }
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}