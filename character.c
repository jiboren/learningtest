#include <stdio.h>
int main (){
    //定义char类型的变量
    //取值范围ASCII码表中所有的内容windows1个字节
    char c1= 'A';
    printf("%c\n",c1);
    char c2 = 'a';
    printf("%c\n",c2);
    char c3 = '1' ;
    printf("%c\n",c3);
    printf("%zu\n",sizeof(c1));


    return 0;


  

}