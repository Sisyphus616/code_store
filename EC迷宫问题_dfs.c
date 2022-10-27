#include<stdio.h>

int q,p,a[51][51],book[51][51]={0};     //a为迷宫,book为行走路线

void dfs(int x,int y){                  //深度优先算法实现走迷宫
    int next[4][2]={ {0,1}, //向右
    /*行走方式*/      {1,0},//向下
                     {0,-1},//向左
                     {-1,0}};//向上
    int tx,ty;                          //尝试的坐标，防止全局变量x，y改变
    if(x==q&&y==p){
        for( int i=1 ; i<=p ; i++ )
            for( int j=1 ; j<=q ; j++ ){
                printf("%d",book[j][i]);//输出可能路径
                if( j!=q )
                    printf(" ");
                else    printf("\n");
            }
        return ;
    }
    for( int k=0 ; k<=3 ; k++ ){
        tx=x+next[k][1];
        ty=y+next[k][0];
        if(tx<1||tx>q||ty<1||ty>p)      //检查是否走到迷宫外
            continue;
        if( a[tx][ty]==1&&book[tx][ty]==0 ){
            book[tx][ty]=1;
            dfs(tx,ty);                 //递归尝试下一个点
            book[tx][ty]=0;             //尝试结束（无论是否成功）消除标记
        }
    }
    return ;
}

int main(){
    scanf("%d %d",&p,&q);
    for( int i=1 ; i<=p ; i++ )
        for( int j=1 ; j<=q ; j++ )
            scanf("%d",&a[j][i]);       //读入迷宫
    book[1][1]=1;                       //起点位置
    dfs(1,1);                           //起点1,1
    return 0;
}
