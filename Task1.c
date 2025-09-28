#include<stdio.h>
#include<string.h>

int LCS_length(char *X, char *Y) {
    int m = strlen(X);
    int n = strlen(Y);

    int c[m + 1][n + 1]; 

    for (int i = 0; i <= m; i++) {
        c[i][0] = 0;
    }
    for (int j = 0; j <= n; j++) {
        c[0][j] = 0;
    }


    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
           
            if (X[i - 1] == Y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
            }
          
            else {
                if (c[i - 1][j] >= c[i][j - 1]) {
                    c[i][j] = c[i - 1][j];
                } else {
                    c[i][j] = c[i][j - 1];
                }
            }
        }
    }
  
    return c[m][n];
}

int main() {
    char X[] = "AGCCCTAAGGGCTACCTAGCTT";
    char Y[] = "GACAGCCTACAAGCGTTAGCTTG";

    printf("Length of LCS is %d\n", LCS_length(X, Y)); 

    return 0;
}