#include<stdio.h>
int main(){
    //1.定义格式：数据类型 变量名 = 值
    int a ;
    //2.赋值/修改值
    a = 10;
    printf("%d\n",a);
    //3.如果定义的时候，已经知道变量中存储的数据
    int b = 20;
    printf("%d\n",b);
    //练习1；两个数相加（变量参与计算）
    //需求：定义两个变量分别存储10和20，邱两个数的和
    int c =10;
    int d  = 20;
    int sum=c+d;
    printf("c+d=%d\n",sum);
    printf("c+d=%d\n",c+d);
    //练习2.用一个变量表示微信余额
    //需求：一开始微信的余额为100元，收到了一个2元的红包
    //思想：经常发生改变的数据，我们可以用变量来表示
    int account =100;
    int total=account+2;
    printf("微信余额为：%d元\n",total);
    //课后练习
    int blood=100;
    int injury=80;
    int recovery=60;
    printf("您的血量为：%d\n",blood-injury+recovery);
    return 0;
}
