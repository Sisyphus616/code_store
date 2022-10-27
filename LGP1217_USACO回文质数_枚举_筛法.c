#include<stdio.h>
#include<string.h>
#include<math.h>
//2022-8-18 2022-9-02 尝试十次
void isprime(int prime[]){						//筛法判断质数
    for( int i=0 ; i<=10000000 ; i++ )
        prime[i]=1;
    for( int i=2 ; i<=10000000 ; i++ ){
        if( prime[i]==0 ) 
            continue;
        for( int j=2*i ; j<10000000 ; j+=i )
            prime[j]=0;
    }
}

int ispalindrome( int a ){						//从尾至头读入a2，判断回文数
    int sum=0,a2=a;
    while(a2>0){
        sum=sum*10+a2%10;
        a2/=10;
    }
    if( sum==a )
        return 1;
    return 0;
}

int main()
{
    int a,b;
    int prime[10000000];
    isprime(prime);								//构建质数表
    scanf("%d %d",&a,&b);
    if( a%2==0 )
        a++;
    if( b>=10000000 )
        b=9999999;
    for( int i=a ; i<=b ; i+=2 ){				//判断顺序会影响最终评测时长
        int len=log10(i)+1;						//数学知识，先判断长度，这一项最简单
        if( len%2==0&&i!=11 )
            continue;
        if( ispalindrome(i)==0 )				//再判回文（其实筛法的判断质数要比判断回文数快）
            continue;
        if( prime[i]==0 )						//判质数
            continue;
        printf("%d\n",i);
    }
    return 0;
}
