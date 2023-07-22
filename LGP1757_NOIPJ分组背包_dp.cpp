// 2023.7.22 2次尝试

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,a[1001],b[1001],c[1001]={0};//总数，总重，重量，价值，组内个数
    int x,group[101][1001],temp;        //暂时记录组数，分组
    cin>>m>>n;
    for( int i=1 ; i<=n ; i++ ){
        cin>>a[i]>>b[i]>>x;
        temp = max(x,temp);             //记录最大组数
        c[x] ++;
        group[x][c[x]] = i;             //x组的第c[x]个的编号为i
    }
    int dp[1001]={0};
    for( int i=1 ; i<=temp ; i++ )      //组数
        for( int k=m ; k>=0 ; k-- )     //容量
            for( int j=1 ; j<=c[i] ; j++ )
                if( k>=a[group[i][j]] )
                    dp[k] = max(dp[k],dp[k-a[group[i][j]]]+b[group[i][j]]);
    cout<<dp[m];
    return 0;
}

// 注意：分组背包遍历次序为先组再容量再组内个数
// 01背包是先个数再容量
