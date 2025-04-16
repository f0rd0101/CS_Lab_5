#include <stdio.h>
#include <stdlib.h>

int main() {
    int M, N;

    printf("Введіть кількість рядків M: ");
    scanf("%d", &M);
    printf("Введіть кількість стовпців N: ");
    scanf("%d", &N);

    double **A = (double **)malloc(M * sizeof(double *));
    for (int i = 0; i < M; i++) {
        A[i] = (double *)malloc(N * sizeof(double));
    }

    double *B = (double *)malloc(M * N * sizeof(double));
    int positive_count = 0;
    double product_of_negatives = 1;
    double sum_of_negatives = 0;
    int has_negative = 0;

    printf("Введіть елементи матриці(приклад у help.txt):\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i][j] > 0) {
                B[positive_count++] = A[i][j];
            } else if (A[i][j] < 0) {
                sum_of_negatives += A[i][j];
                if (has_negative == 0) {
                    product_of_negatives = A[i][j];
                    has_negative = 1;
                } else {
                    product_of_negatives *= A[i][j];
                }
            }
        }
    }

    printf("Масив B з додатними елементами:\n");
    for (int i = 0; i < positive_count; i++) {
        printf("%lf ", B[i]);
    }
    printf("\n");

    if (has_negative) {
        printf("Сума від'ємних елементів: %lf\n", sum_of_negatives);
        printf("Добуток від'ємних елементів: %lf\n", product_of_negatives);
    } else {
        printf("В матриці немає від'ємних елементів.\n");
    }

    for (int i = 0; i < M; i++) {
        free(A[i]);
    }
    free(A);
    free(B);

    return 0;
}
