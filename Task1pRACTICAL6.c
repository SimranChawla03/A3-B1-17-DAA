#include <stdio.h>
#include <float.h>

#define MAX 100

int main() {
    int n, i, j, k, l;
    float p[MAX + 1], q[MAX + 1], e[MAX + 2][MAX + 2], w[MAX + 2][MAX + 2];
    int root[MAX + 2][MAX + 2];

    printf("Enter number of keys: ");
    scanf("%d", &n);

    int keys[MAX + 1];
    printf("Enter %d keys:\n", n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &keys[i]);
    }

    printf("Enter %d probabilities for keys (p):\n", n);
    for (i = 1; i <= n; i++) {
        scanf("%f", &p[i]);
    }

    printf("Enter %d probabilities for dummy keys (q):\n", n + 1);
    for (i = 0; i <= n; i++) {
        scanf("%f", &q[i]);
    }

    for (i = 1; i <= n + 1; i++) {
        e[i][i - 1] = q[i - 1];
        w[i][i - 1] = q[i - 1];
    }

    for (l = 1; l <= n; l++) {
        for (i = 1; i <= n - l + 1; i++) {
            j = i + l - 1;
            e[i][j] = FLT_MAX;
            w[i][j] = w[i][j - 1] + p[j] + q[j];
            for (k = i; k <= j; k++) {
                float cost = e[i][k - 1] + e[k + 1][j] + w[i][j];
                if (cost < e[i][j]) {
                    e[i][j] = cost;
                    root[i][j] = k;
                }
            }
        }
    }

    printf("\nMinimum expected search cost: %.4f\n", e[1][n]);
    return 0;
}
