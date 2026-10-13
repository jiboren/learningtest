#include <stdio.h>
int main (){
   
    //练习数据拆分，需求：键盘录入一个三位数，将其拆分为各位，是为，百位后，打印在控制台
    int a;
    printf("请输入一个三位数：");
    scanf("%d",&a);
       int c=a%10;
       int b=(a/10-c/10)%10;
       int x=(a/10-c/10);
       int d=x/10-b/10;


       printf("个位是：%d",c);
       printf("十位是：%d",b);
       printf("百位是：%d",d);
       //标准答案：
       int num ;
       printf("请输入一个三位数：");
       scanf("%d",&num);
       //拆分
       int ge=num%10;
       int shi=num/10%10;
       int bai=num/100;
       printf("个位是：%d\n",ge);
       printf("十位是：%d\n",shi);
       printf("百位是：%d",bai);


return 0;










}