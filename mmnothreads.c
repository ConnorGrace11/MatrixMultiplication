#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char* argv[]) {
    char *a = argv[1];
    int testInteger = atoi(a);
    int random[testInteger][testInteger];
    int i, o;

    for(o = 0; o<testInteger; o++)
        for(i = 0; i<testInteger; i++)
                random[o][i] = rand() % 15;
    int rslt[testInteger][testInteger];

    printf("Multiplication of matrices is: \n\n");
    int R1=testInteger;
    int R2=testInteger;
    int C1=testInteger;
    int C2=testInteger;
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            rslt[i][j] = 0;

            for (int k = 0; k < R2; k++) {
                rslt[i][j] += random[i][k] * random[k][j];
            }
            printf("%d\t", rslt[i][j]);
        }

        printf("\n");
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Total time used is %lf seconds", cpu_time_used);
    printf("\n");


    return 0;
}
