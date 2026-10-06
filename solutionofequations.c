#include <stdio.h>
#include <math.h>

double f(double a, double b, double c, double d, double x) {
    return ((a * x + b) * x + c) * x + d;
}

double df(double a, double b, double c, double x) {
    return (3 * a * x + 2 * b) * x + c;
}

int main(void) {
    double a, b, c, d;

    printf("请输入 a、b、c、d：");
    if (scanf("%lf %lf %lf %lf", &a, &b, &c, &d) != 4) {
        printf("输入无效。\n");
        return 1;
    }

    if (!isfinite(a) || !isfinite(b) ||
        !isfinite(c) || !isfinite(d)) {
        printf("系数必须是有限数值。\n");
        return 1;
    }

    if (a == 0) {
        printf("a 为 0，这不是三次函数。\n");
        return 1;
    }

    printf("这是三次函数，至少有一个实数零点。\n");

    /* 逐步扩大区间，直到区间两端函数值异号 */
    double left = -1.0;
    double right = 1.0;
    double fl, fr;
    int found = 0;

    for (int i = 0; i < 1024; i++) {
        fl = f(a, b, c, d, left);
        fr = f(a, b, c, d, right);

        if (isnan(fl) || isnan(fr)) {
            break;
        }

        if (fl == 0) {
            printf("零点约为：%.4f\n", left);
            return 0;
        }
        if (fr == 0) {
            printf("零点约为：%.4f\n", right);
            return 0;
        }

        if ((fl < 0 && fr > 0) || (fl > 0 && fr < 0)) {
            found = 1;
            break;
        }

        left *= 2.0;
        right *= 2.0;

        if (!isfinite(left) || !isfinite(right)) {
            break;
        }
    }

    if (!found) {
        printf("系数范围过大，无法找到可计算的区间。\n");
        return 1;
    }

    double x = left / 2.0 + right / 2.0;

    /* 牛顿迭代；不合适时使用区间中点 */
    for (int i = 0; i < 1000; i++) {
        double mid = left / 2.0 + right / 2.0;
        double halfWidth = right / 2.0 - left / 2.0;

        if (halfWidth < 5e-11) {
            x = mid;
            break;
        }

        double slope = df(a, b, c, x);
        double next = mid;

        if (isfinite(slope) && fabs(slope) > 1e-14) {
            double newton = x - f(a, b, c, d, x) / slope;

            /* 只有牛顿步留在区间中间部分时才采用 */
            if (isfinite(newton) &&
                newton > mid - 0.8 * halfWidth &&
                newton < mid + 0.8 * halfWidth) {
                next = newton;
            }
        }

        double fn = f(a, b, c, d, next);

        if (fn == 0) {
            x = next;
            break;
        }

        if ((fl < 0 && fn < 0) || (fl > 0 && fn > 0)) {
            left = next;
            fl = fn;
        } else {
            right = next;
            fr = fn;
        }

        x = next;
    }

    printf("零点约为：%.4f\n", x);
    return 0;
}