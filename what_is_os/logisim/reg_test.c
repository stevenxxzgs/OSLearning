#include <stdio.h>
#include <stdbool.h>

int main() {
    bool x = 0;  // 初始值
    bool y = 0;  // 初始值
    bool z = 0;  // 初始值

    int N = 16;  // 循环次数

    for (int i = 0; i < N; i++) {
        // 计算下一个状态
        bool x1 = x & !z | z&(x ^ y);
        bool y1 = y ^ z;
        bool z1 = !z;

        // 更新 x, y, z
        x = x1;
        y = y1;
        z = z1;

        // 输出当前状态
        printf("Iteration %d: x = %d, y = %d, z = %d\n", i + 1, x, y, z);
    }

    return 0;
}