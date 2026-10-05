#include <stdio.h>
int main(){
//1定义short int long longlong 的四种数据类型的变量
//格式：数据类型 变量名
//short 短整型 2B
short a=10;
printf("%d\n",a);
//int 整数32位 4字节
int b =100;
printf("%d\n",b);
//long 类型 长整型 4个字节（windows）
long c = 15L;
printf("%ld\n",c);
//long long(c99) 超长整型 windows 8个字节（19位数）
long long d =8964LL;
printf("%lld\n",d);



//2.利用sizeof测量每一种数据类型占用对少字节,sizeof(变量名/数据类型)
//short
printf("%zu\n",sizeof(a));
printf("%zu\n",sizeof(short));
//int
printf("%zu\n",sizeof(b));
printf("%zu\n",sizeof(int));
//long
printf("%zu\n",sizeof(c));
printf("%zu\n",sizeof(long));
//long long
printf("%zu\n",sizeof(d));
printf("%zu\n",sizeof(long long));


return 0;



}