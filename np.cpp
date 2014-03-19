#include <stdio.h>

int main()
{
    int n, i, j;
    scanf("%d", &n);

    int op1[n * n][5];
    int index1 = 1;

    int op2[n * n][5];
    int index2 = 1;

    int a[n + 1][n + 1];

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
            op1[(i - 1) * n + j][0] = 0;
            op1[(i - 1) * n + j][1] = 0;
            op1[(i - 1) * n + j][2] = 0;
            op1[(i - 1) * n + j][3] = 0;
            op1[(i - 1) * n + j][4] = 0;

            op2[(i - 1) * n + j][0] = 0;
            op2[(i - 1) * n + j][1] = 0;
            op2[(i - 1) * n + j][2] = 0;
            op2[(i - 1) * n + j][3] = 0;
            op2[(i - 1) * n + j][4] = 0;
        }
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (a[i][j] != 0) {
                if (j > 1)
                if (a[i][j] != a[i][j - 1]) {
                    op1[index1][0] = a[i][j];
                    op1[index1][1] = i;
                    op1[index1][2] = i;
                    op1[index1][3] = j;
                    op1[index1][4] = j;
                    index1++;
                } else {
                    op1[index1][4]++;
                }
                else {
                    op1[index1][0] = a[i][j];
                    op1[index1][1] = i;
                    op1[index1][2] = i;
                    op1[index1][3] = j;
                    op1[index1][4] = j;
                    index1++;
                }
            }
        }
    }

    for (j = 1; j <= n; j++) {
        for (i = 1; i <= n; i++) {
            if (a[i][j] != 0) {
                if (j > 1)
                if (a[i][j] != a[i][j - 1]) {
                    op2[index2][0] = a[i][j];
                    op2[index2][1] = i;
                    op2[index2][2] = i;
                    op2[index2][3] = j;
                    op2[index2][4] = j;
                    index2++;
                } else {
                    op2[index2][4]++;
                }
                else {
                    op2[index2][0] = a[i][j];
                    op2[index2][1] = i;
                    op2[index2][2] = i;
                    op2[index2][3] = j;
                    op2[index2][4] = j;
                    index2++;
                }
            }
        }
    }
    
    if (index1 > index2) {
        printf("%d\n", index1);
        for (i = 1; i <= index1; i++) {
            printf("%d %d %d %d %d", op1[i][0], op1[i][1], op1[i][2], op1[i][3], op1[i][4]);
        }
    }

    if (index1 < index2) {
        printf("%d\n", index2);
        for (i = 1; i <= index2; i++) {
            printf("%d %d %d %d %d", op1[i][0], op1[i][1], op1[i][2], op1[i][3], op1[i][4]);
        }
    }

    return 0;
}