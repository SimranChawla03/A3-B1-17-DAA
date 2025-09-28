#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int main() {
    char S[] = "AABCBDC";
    int n = strlen(S);

    int dp[n + 1][n + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (S[i - 1] == S[j - 1] && i != j) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Backtracking to find the LRS string
    char lrs[dp[n][n] + 1];
    lrs[dp[n][n]] = '\0';
    int k = dp[n][n];
    int i = n;
    int j = n;

    while (i > 0 && j > 0) {
        if (S[i - 1] == S[j - 1] && i != j) {
            lrs[k - 1] = S[i - 1];
            i--;
            j--;
            k--;
        } else if (dp[i - 1][j] >= dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    printf("The length of the Longest Repeating Subsequence is: %d\n", dp[n][n]);
    printf("LRS = %s\n", lrs);

    return 0;
}