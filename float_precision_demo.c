/*
 * float_precision_demo.c
 * 演示：C 语言里小数运算为什么"不精确"
 * 编译：gcc -Wall float_precision_demo.c -o float_precision_demo.exe
 *
 * 说明：看"真实值"要用 %.17g。
 *       MinGW 的 printf 在超过 17 位有效数字后会补 0（见第 10 段），
 *       用 %.30f 反而会看到假的 0，别被骗。
 */
#include <stdio.h>
#include <float.h>

/* 正确的浮点比较方式：不看"相等"，看"差距是否小于容差" */
static int nearly_equal(double a, double b)
{
    double diff = a - b;
    if (diff < 0) diff = -diff;   /* 不用 fabs，避免依赖数学库 */
    return diff < 1e-9;
}

int main(void)
{
    int i;

    /* ---------- 1. 0.1 存进去的到底是不是 0.1 ---------- */
    printf("=== 1. what is really stored ===\n");
    printf("0.1   as double = %.17g\n", 0.1);
    printf("0.1f  as float  = %.17g\n", (double)0.1f);
    printf("0.2   as double = %.17g\n", 0.2);
    printf("0.5   as double = %.17g   <- 0.5 exact (1/2)\n", 0.5);
    printf("0.25  as double = %.17g   <- 0.25 exact (1/4)\n", 0.25);

    /* ---------- 2. 最经典的：0.1 + 0.2 != 0.3 ---------- */
    printf("\n=== 2. 0.1 + 0.2 == 0.3 ? ===\n");
    double s = 0.1 + 0.2;
    printf("0.1 + 0.2 = %.17g\n", s);
    printf("0.3       = %.17g\n", 0.3);
    printf("s == 0.3  ->  %s\n", (s == 0.3) ? "true" : "false");

    /* ---------- 3. 误差会累积 ---------- */
    printf("\n=== 3. accumulate error ===\n");
    double acc = 0.0;
    for (i = 0; i < 10; i++) acc += 0.1;
    printf("double: 0.1 added 10 times   = %.17g\n", acc);
    printf("acc == 1.0 -> %s\n", (acc == 1.0) ? "true" : "false");

    float facc = 0.0f;
    for (i = 0; i < 100000; i++) facc += 0.1f;
    printf("float : 0.1f added 100000x   = %.6f  (expected 10000.000000)\n",
           (double)facc);

    /* ---------- 4. 大数吃小数 ---------- */
    printf("\n=== 4. big number eats small number ===\n");
    double big = 1e20;
    printf("(1e20 + 1.0) - 1e20 = %.1f   <- should be 1.0\n", (big + 1.0) - big);
    double big2 = 1e16;
    printf("(1e16 + 1.0) - 1e16 = %.1f\n", (big2 + 1.0) - big2);

    /* ---------- 5. float 的有效数字只有 7 位左右 ---------- */
    printf("\n=== 5. float has ~7 significant digits ===\n");
    float f = 16777216.0f;              /* 2^24 */
    printf("float (2^24) + 1      = %.1f   <- adding 1 changes nothing\n",
           (double)(f + 1.0f));
    float g = 167772160.0f;             /* 2^24 * 10 */
    printf("float 167772160 + 10  = %.1f   <- grid step here is 16\n",
           (double)(g + 10.0f));
    printf("FLT_DIG=%d  DBL_DIG=%d  FLT_EPSILON=%.3e  DBL_EPSILON=%.3e\n",
           FLT_DIG, DBL_DIG, (double)FLT_EPSILON, DBL_EPSILON);

    /* ---------- 6. 不是浮点误差，但新手最常踩：整数除法 ---------- */
    printf("\n=== 6. integer division trap (NOT a float problem) ===\n");
    printf("1/2          = %d\n", 1 / 2);
    printf("1.0/2        = %.2f\n", 1.0 / 2);
    printf("1/2.0        = %.2f\n", 1 / 2.0);
    printf("(float)1/2   = %.2f\n", (float)1 / 2);

    /* ---------- 7. 正确做法一：用容差比较 ---------- */
    printf("\n=== 7. how to compare correctly ===\n");
    printf("nearly_equal(0.1+0.2, 0.3) -> %s\n",
           nearly_equal(0.1 + 0.2, 0.3) ? "true" : "false");

    /* ---------- 8. 正确做法二：钱用整数（分）算 ---------- */
    printf("\n=== 8. money: use integers (cents) ===\n");
    long cents = 10 + 20;            /* 0.10 元 + 0.20 元 */
    printf("0.10 + 0.20 yuan = %ld cents = %.2f yuan\n", cents, cents / 100.0);

    /* ---------- 9. 显示也会骗你 ---------- */
    printf("\n=== 9. printf default hides the error ===\n");
    printf("%%f    -> %f\n", s);
    printf("%%.17g -> %.17g   <- this one tells the truth\n", s);

    /* ---------- 10. MinGW printf 的精度上限 ---------- */
    printf("\n=== 10. MinGW printf precision limit ===\n");
    printf("%%.17g -> %.17g\n", 0.1);
    printf("%%.30f -> %.30f   <- real value is ...0555111, not zeros\n", 0.1);
    printf("true value of double 0.1 = 0.1000000000000000055511151231257827\n");

    /* ---------- 11. 工程做法：Kahan 求和，把漂移压回去 ---------- */
    printf("\n=== 11. Kahan summation ===\n");
    double naive = 0.0, kahan = 0.0, comp = 0.0, y, t;
    for (i = 0; i < 1000000; i++) {
        double x = 0.1;
        naive += x;
        y = x - comp;
        t = kahan + y;
        comp = (t - kahan) - y;
        kahan = t;
    }
    printf("naive sum = %.17g\n", naive);
    printf("kahan sum = %.17g\n", kahan);

    return 0;
}
