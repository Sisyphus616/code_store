#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
//2022-8-31		尝试三次
using namespace std;

int main()
{
    int pos;
    float m[100],v[100],Max=0;
    float k[100],T,N;
    cin>>N>>T;
    for( int i=0 ; i<N ; i++ ){
        cin>>m[i]>>v[i];
        k[i]=v[i]*1.0/m[i];
    }
    float vnow=0,mnow=0;
    while( mnow<T ){
        for( int i=0 ; i<N ; i++ )
            if( k[i]>Max ){
                Max=k[i];
                pos=i;
            }
        if( Max==0 )
            break;
        if( mnow+m[pos]<T ){
            mnow+=m[pos];
            vnow+=v[pos];
            k[pos]=0;
            Max=0;
        }
        else{
            vnow+=v[pos]*1.0*(T-mnow)/m[pos];
            mnow=T;
        }
    }
    printf("%.2f",vnow);
    return 0;
}
