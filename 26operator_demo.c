#include<stdio.h>
int main(){
int blood =200;
int injury ;
int recovery ;
printf("请输入您所受的伤害和恢复值（用空格分隔）:");

blood=blood-injury+recovery;
if (blood<200){
    printf("您的血量为：%d\n",blood);

}
if (blood>=200){
    printf("您的血量为:200\n");
}
printf("请输入苹果中虫子的数量:");
int worm ;
scanf("%d",&worm);
if(worm>=1){

    printf("小明将会扔掉水果");
}
if(worm<1){
    printf("小明将会吃下水果");
}



    return 0;
}
