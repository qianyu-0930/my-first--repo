#include <stdio.h>
#include <stdlib.h>

/* 蒙特卡洛法估算圆周率：往单位正方形里撒点，统计落在四分之一圆内的比例
 * ASC 味小注：这个循环是纯串行的，等你学了 OpenMP，一行 #pragma 就能并行加速 */
#define N 1000000

int main(void)
{
    long long inside = 0;
    for (long long i = 0; i < N; i++) {
        double x = (double)rand() / RAND_MAX;
        double y = (double)rand() / RAND_MAX;
        if (x * x + y * y <= 1.0)
            inside++;
    }
    printf("N = %lld, pi ≈ %f\n", N, 4.0 * inside / N);
    return 0;
}
