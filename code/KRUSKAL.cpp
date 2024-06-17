#include<bits/stdc++.h>
using namespace std;
int V,E;
vector<pair<int,int>> v[1001];
vector<pair<int,int>> T;
int parents[1001];
struct canh{
    int a,b,c;
};
bool cmp(canh x,canh y){
    return x.c<y.c;
}
void solve(){
    cin>>V>>E;
    memset(v,0,sizeof(v));
    canh ds[E+1];
    for(int i=1;i<=E;i++){
        cin>>ds[i].a>>ds[i].b>>ds[i].c;
        v[ds[i].a].push_back({ds[i].b,ds[i].c});
        v[ds[i].b].push_back({ds[i].a,ds[i].c});
    }
    sort(ds+1,ds+1+E,cmp);
    int idx=1;
    int ans=0;
    for(int i=1;i<=V;i++){
        parents[i]=i;
    }
    while(T.size()<V-1){
        if(parents[ds[idx].a]!=parents[ds[idx].b]){
            ans+=ds[idx].c;
            T.push_back({ds[idx].a,ds[idx].b});
            int old=parents[ds[idx].b];
            for(int i=1;i<=V;i++){
                if(parents[i]==old){
                    parents[i]=parents[ds[idx].a];
                }
            }
        }
        idx++;
    }
    cout<<ans<<endl;
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