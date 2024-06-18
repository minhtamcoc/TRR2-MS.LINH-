#include<bits/stdc++.h>
using namespace std;
int a[101][101];
int n;
int s;
void EULER(){
    stack<int> st,ce;
    st.push(s);
    while(!st.empty()){
        int k=st.top();
        int ok=0;
        for(int i=1;i<=n;i++){
            if(a[k][i]==1){
                st.push(i);
                ok=1;
                a[k][i]=0;
                break;
            }
        }
        if(ok==0){
            st.pop();
            ce.push(k);
        }
    }
   while(!ce.empty()){
    int k=ce.top();
    ce.pop();
    cout<<k<<" ";
   }
}
int main(){
    cin>>n>>s;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    EULER();
    return 0;
}