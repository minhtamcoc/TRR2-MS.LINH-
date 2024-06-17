#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1005][1005];
int dp[1005][1005];
int dx[3]={0,1,1};
int dy[3]={1,0,1};
bool issafe(int x,int y){
	if(x>=1&&x<=n&&y>=1&&y<=m) return true;
	return false;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	memset(dp,-1,sizeof(dp));
	dp[1][1]=0;
	queue<pair<int,int>> q;
	q.push({1,1});
	while(!q.empty()){
		pair<int,int> tmp=q.front();
		q.pop();
		int x=tmp.first;
		int y=tmp.second;
		for(int k=0;k<3;k++){
			int x1=x+dx[k];
			int y1=y+dy[k];
			int ans=0;
			if(issafe(x1,y1)){
				 ans=abs(a[x][y]-a[x1][y1]);
			}
			if(ans>0){
				int x2=x+ans*dx[k];
				int y2=y+ans*dy[k];
				if(issafe(x2,y2)&&dp[x2][y2]==-1){
					q.push({x2,y2});
					dp[x2][y2]=dp[x][y]+1;
				}
			}
		}
		if(dp[n][m]!=-1) break;
	}
	cout<<dp[n][m]<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--){
	solve();
	}
	return 0;
}