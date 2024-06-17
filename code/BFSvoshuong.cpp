#include<bits/stdc++.h>
using namespace std;
int V,E,u;
vector<int> v[1001];
bool l[1001];
void bfs(int u){
    queue<int> q;
    q.push(u);
   l[u]=true;
    while(!q.empty()){
        int k=q.front();
        q.pop();
        cout<<k<<" ";
        for(int x:v[k]){
            if(!l[x]){
                q.push(x);
                l[x]=true;
            }
        }
    }
}
void ins(){
    cin>>V>>E>>u;
    memset(v,0,sizeof(v));
    memset(l,false,sizeof(l));
    for(int i=1;i<=E;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
    }
    bfs(u);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        ins();
        cout<<endl;
    }
    return 0;
}