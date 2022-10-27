#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
//2022-10-24程序员节快乐 尝试一次
using namespace std;

int main(){
    int n,S[3000]={0},b[3],x;                         	//a[0]，b（1~50）为乘数，S为结果
    int a[3][3000];
    for( int i=0 ; i<3 ; i++ )
        for( int j=0 ; j<3000 ; j++ )
            a[i][j]=0;
    int lena=1,lens=1,lenb=1,lena1=1,lena2=1;
    a[0][1]=a[1][1]=1;
    cin>>n;
    for( int i=1 ; i<=n ; i++ ){
        x=0;
        b[1]=i%10;
        b[2]=i/10;
        if( b[2]==0 )									//计算b长度
            lenb=1;
        else    lenb=2;
        for( int j=lenb ; j>0 ; j-- )
            for( int k=1 ; k<=lena+1 ; k++ ){         	//两步乘法，记公式就好
                int t=(a[0][k]*b[j]+x);
                a[j][k+j-1]=t%10;						//a[1],a[2]分别为乘法竖式的第一、二行（小学数学多重要啊）
                x=t/10;
            }
        for( int j=2999 ; j>0 ; j-- ){                	//数组长度计算，下同
            if( a[1][j]==0 )
                continue;
            lena1=j;
            break;
        }
        for( int j=2999 ; j>0 ; j-- ){
            if( a[2][j]==0 )
                continue;
            lena2=j;
            break;
        }
        for( int j=1 ; j<=max(lena1,lena2)+1 ; j++ ){	//a[1],a[2]错位高精度相加，结果a[0]即为当前阶乘
            int t=(a[1][j]+a[2][j]+x);
            a[0][j]=t%10;
            x=t/10;
        }
        for( int j=2999 ; j>0 ; j-- ){
            if( a[0][j]==0 )
                continue;
            lena=j;
            break;
        }
        for( int j=2999 ; j>0 ; j-- ){
            if( S[j]==0 )
                continue;
            lens=j;
            break;
        }
        x=0;
        for( int j=1 ; j<=max(lena,lens)+1 ; j++ ){		//阶乘高精度相加，结果给S
            int t=(S[j]+a[0][j]+x);
            S[j]=t%10;
            x=t/10;
        }
    }
    for( int j=2999 ; j>0 ; j-- ){
        if( S[j]==0 )
            continue;
        lens=j;
        break;
    }
    for( int i=lens ; i>0 ; i-- )						//高位输出
        cout<<S[i];
    return 0;
}
