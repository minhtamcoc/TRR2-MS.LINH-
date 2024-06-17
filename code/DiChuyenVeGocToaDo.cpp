#include<bits/stdc++.h>
using namespace std;
int n,m;
long long dp[1001][1001];
void solve(){
	cin>>n>>m;
	for(int i=0;i<=m;i++) dp[0][i]=1;
	for(int i=0;i<=n;i++) dp[i][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[i][j]=dp[i][j-1]+dp[i-1][j];
		}
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