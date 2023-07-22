//2023-7-22 尝试2次

#include<bits/stdc++.h>
using namespace std;

int prime[1001];
void isprime(){				//筛法
    for( int i=2 ; i<1001 ; i++ )
        prime[i] = 1;
    for( int i=2 ; i<1001 ; i++ ){
        if( prime[i] )
            for( int j=2*i ; j<1001 ; j+=i )
                prime[j] = 0;
    }
    prime[0] = 1;           //特判
}

int main(){
    isprime();
    int n;
    cin>>n;
    long long int dp[1001]={1,0};	//边界值
    for( int i=2 ; i<=n ; i++ ){
        if( prime[i] )
            for( int j=i ; j<=n ; j++ ){
                dp[j] += dp[j-i];	//完全背包状态转移方程
            }
    }
    cout<<dp[n];
    return 0;
}

// 注：本题为完全背包问题
