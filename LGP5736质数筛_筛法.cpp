#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
//2022-10-27	尝试一次
using namespace std;

int prime[100001],a[101]={0};					//创建质数筛和读入数组

int main(){
    int n;
    cin>>n;
    for( int i=2 ; i<100001 ; i++ )
        prime[i]=1;
    for( int i=2 ; i<100001 ; i++ )				//筛法实现
        if( prime[i]==1 )
            for( int j=i*2 ; j<100001 ; j+=i )
                prime[j]=0;
    for( int i=0 ; i<n ; i++ ){
        cin>>a[i];
        if( prime[a[i]]==0 )
            a[i]=0;
    }
    int lena;
    for( lena=n-1 ; a[lena]==0 ; lena-- );		//判断数组长度最新方法
    for( int i=0 ; i<=lena ; i++ )
        if( a[i]!=0 ){
            cout<<a[i];
            if( i!=lena-1 )
                cout<<" ";
        }
    return 0;
}
