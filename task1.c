#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;

  
    printf("Введіть розмір матриці N: ");
    scanf("%d", &N);


    double **A = (double **)malloc(N * sizeof(double *));
    for (int i = 0; i < N; i++) {
        A[i] = (double *)malloc(N * sizeof(double));
    }


    printf("Введіть елементи матриці у форматі кількість чисел яке має бути рівним кількості елементів матриці(ви задали їх вище), кожне число розділяєте пробілом, далі натискаєте ентер і вводите наступну кількість чисел і так по всім рядкам(!!приклад можна подивитися у файлі help.txt ):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

   
    printf("Найбільші елементи кожного рядка матриці:\n");
    for (int i = 0; i < N; i++) {
        double max = A[i][0]; 
        for (int j = 1; j < N; j++) {
            if (A[i][j] > max) {
                max = A[i][j];
            }
        }
        printf("Рядок %d: %lf\n", i + 1, max);
    }

   
    for (int i = 0; i < N; i++) {
        free(A[i]);
    }
    free(A);

    return 0;
}


