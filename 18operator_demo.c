#include<stdio.h>
int main(){
int i=3;

printf("%d\n",(i=3,i++,++i,i+5));

int a;
printf("请输入一个整数:");
scanf("%d",&a);
a=a>=0?a:-a;
printf("结果是:%d",(a=a%3,a*10));





    return 0;}