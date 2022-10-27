#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
//2022-10-23 尝试三次
using namespace std;                        //本题实际上是高精度加减法实现fibonacci数列运算

int main(){
    int ans[5000]={0},a[5000]={0},b[5000]={0},n,lenans;
    cin>>n;
    a[1]=2;                                 //a为f(n-1)，b为f(n-2)，ans为f(n)
    b[1]=1;
    if( n==1 ){                             //初始化
        ans[1]=1;
        lenans=1;
    }
    if( n==2 ){
        ans[1]=2;
        lenans=1;
    }
    for( int i=3 ; i<=n ; i++ ){            //计算数组长度工具，下同，目前已学会单行循环
        int lena,lenb,x=0;
        for( int i=4999 ; i>0 ; i-- ){
            if( a[i]==0 )
                continue;
            lena=i;
            break;
        }
        for( int i=4999 ; i>0 ; i-- ){
            if( b[i]==0 )
                continue;
            lenb=i;
            //cout<<lenb<<endl;
            break;
        }
        int lenmax=max(lena+1,lenb+1);
        for( int i=1 ; i<=lenmax ; i++ ){   //高精度加法运算
            ans[i]=(a[i]+b[i]+x)%10;
            x=(a[i]+b[i]+x)/10;
        }
        for( int i=4999 ; i>0 ; i-- ){
            if( ans[i]==0 )
                continue;
            lenans=i;
            break;
        }
        for( int i=1 ; i<=lenans ; i++ ){   //数值传递，a——>b,ans——>a
            b[i]=a[i];
            a[i]=ans[i];
        }
    }
    for( int i=lenans ; i>=1 ; i-- )        //高位输出
        cout<<ans[i];
    return 0;
}
