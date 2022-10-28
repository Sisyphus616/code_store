#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
//2022-8-31   尝试两次
/****************************************************************************
附注:我的卡塔兰数博客网址https://blog.csdn.net/m0_71926297/article/details/126620073?spm=1001.2014.3001.5501
 ****************************************************************************/
using namespace std;

long long int f( int n ){						//生成卡塔兰数
    long long int ans;
    if( n==1 )
        ans=1;
    if( n==2 )
        ans=2;
    if( n>2 ){
        long long int a=1,b=1;
        if( n%2==0 ){
            for( int i=n+3 ; i<=2*n ; i+=2 )
                a*=i;
            a*=pow( 2 , n/2 );
            for( int i=1 ; i<n/2+1 ; i++ )
                b*=i;
        }
        if( n%2!=0 ){
            for( int i=n+2 ; i<2*n ;i+=2 )
                a*=i;
            a*=pow( 2 , n/2 );
            for( int i=1 ; i<=n/2+1 ; i+=1 )
                b*=i;
        }
        ans=a/b;
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    cout<<f(n);
    return 0;
}
