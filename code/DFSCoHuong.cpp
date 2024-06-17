#include<bits/stdc++.h>
using namespace std;
int V,E,U;
vector<int> a[1001];
bool visited[1001];
void dfs(int U){
    cout<<U<<" ";
    visited[U]=true;
    for(auto x:a[U]){
        if(!visited[x]){
            dfs(x);
        }
    }
}
void ins(){
    cin>>V>>E>>U;
    memset(a,0,sizeof(a));
    memset(visited,false,sizeof(visited));
    for(int i=1;i<=E;i++){
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
    }
    dfs(U);
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