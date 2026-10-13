#include <stdio.h>

int main(void) {
    int rowA, seatA;
    int rowB, seatB;

    printf("请输入小帅的排号和座号（用空格分隔）：");
    if (scanf("%d %d", &rowA, &seatA) != 2) {
        puts("输入无效");
        return 1;
    }

    printf("请输入小诗诗的排号和座号（用空格分隔）：");
    if (scanf("%d %d", &rowB, &seatB) != 2) {
        puts("输入无效");
        return 1;
    }

    if (rowA == rowB && seatA == seatB) {
        puts("我会开心地打游戏");
    } else {
        puts("我将愉快地打游戏");
    }

    return 0;
}