#include <stdio.h>
int main(){
    //%%与:并且而且，计算规则：只有两边都成立，那么最终的结果才是成立的,只要有一个结果不成立，最终的结果都是不成立的
    
    int a;//定义变量存储数据
    printf("请输入一个两位数：");
    scanf("%d",&a);
    int b=a%10;
    int c=a/10%10;
    printf("判断结果为：%d\n",b!=7&&c!=7);


    int d;
    printf("请输入一个两位整数：");
    scanf("%d",&d);
    int e=d%10;;
    int f=d/10%10;
    printf("判断结果为：%d",e!=7&&f!=7&&d%7!=0);







    return 0;
}