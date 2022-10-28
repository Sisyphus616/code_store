#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
//2022-8-27   尝试一次
using namespace std;

string dc( int a ){						//构建分治函数
    int sum;
    string ret;
    for( int i=0 ; pow(2,i)<=a ; i++ )
        if( pow(2,i+1)>a ){
            if( i==0 )
                ret="2(0)";
            if( i==1 )
                ret="2";
            if( i==2 )
                ret="2(2)";
            if( i>2 ){
                ret="2(";
                ret+=dc(i);
                ret+=")";
            }
            sum=pow(2,i);
        }
    int b=a-sum;
    if( b!=0 ){
        ret+="+";
        ret+=dc(b);
    }
    return ret;
}

int main() {
    int n;
    cin>>n;
    cout<<dc(n);
    return 0;
}
