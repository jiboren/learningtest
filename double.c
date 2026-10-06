#include <stdio.h>
int main (){
//1.定义float，double，long double 数据类型的变量
//float 单精度小数（精确的小数点后6位）windows占4个字节
  float a =3.14f;
  printf("%f\n",a);
  //double双精度小数（精确度小数点后15位）windows占8个字节
  double b=89.64;
  printf("%.15f\n",b);
//利用sizeof



  return 0 ;

}