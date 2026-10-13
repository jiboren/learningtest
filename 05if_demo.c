#include<stdio.h>
int main(){
    int number;
    printf("请输入氪金总额度：");
    scanf("%d",&number);
    if(number<=99&&number>=1){
        printf("尊贵的VIP1");
    }
     else if(number>=100&&number<=499){
        printf("尊贵的VIP2");
        }
    else if(number>=500&&number<=999){
        printf("尊贵的VIP3");
    }
    else if(number>=1000&&number<=1999){
        printf("尊贵的VIP4");
    }
    else if(number>=2000&&number<=5000){
        printf("尊贵的VIP5");
    }
    else{
        printf("尊贵的vip5");
    }




    return 0;
}