#include<stdio.h>

/**
  请使用递归定义此函数，将输入的一行字符逆序输出。
  字符的输入和输出用getchar和putchar函数
 **/
void myrever(void)
{
	/**********  Begin  **********/
    char c=getchar();
    if( c!=EOF )
      myrever();
    else
      return ;
    putchar(c);
    return ;
    /**********  End  **********/
}
