//01背包倒搜

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int v[26],w[26];
    for( int i=1 ; i<=m ; i++ )
        cin>>v[i]>>w[i];
    int dp[30001]={0};
    for( int i=1 ; i<=m ; i++ )
        for( int j=n ; j>=v[i] ; j-- ){
            dp[j]=max(dp[j],dp[j-v[i]]+v[i]*w[i]);
        }
    cout<<dp[n];
    return 0;
}
