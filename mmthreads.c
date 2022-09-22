#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAT_SIZE 1000
#define MAX_THREADS 10000

int i,j,k;           //Parameters For Rows And Columns
int matrix1[MAT_SIZE][MAT_SIZE]; //First Matrix
int matrix2[MAT_SIZE][MAT_SIZE]; //Second Matrix
int result [MAT_SIZE][MAT_SIZE]; //Multiplied Matrix

typedef struct parameters {
    int x,y;
}args;

void* mult(void* arg){

    args* p = arg;

    //Calculating Each Element in Result Matrix Using Passed Arguments
    for(int a=0;a<j;a++){
        result[p->x][p->y] += matrix1[p->x][a]*matrix2[a][p->y];
    }
    //sleep(3);

    //End Of Thread
    pthread_exit(0);
}


int main(int argc, char* argv[]){

    for(int x=0;x<10;x++){
        for(int y=0;y<10;y++){
            matrix1[x][y] = 0;
            matrix2[x][y] = 0;
            result[x][y] = 0;
        }
    }
    char *a = argv[1];
    i = atoi(a);
    j = i;

    for(int x=0;x<i;x++){
        for(int y=0;y<j;y++){
            matrix1[x][y] = rand() % 15;
        }
    }

    k = j;

    for(int x=0;x<j;x++){
        for(int y=0;y<k;y++){
            matrix2[x][y] = rand() % 15;
        }
    }


    printf("\n --- Matrix 1 ---\n\n");
    for(int x=0;x<i;x++){
        for(int y=0;y<j;y++){
            printf("%5d",matrix1[x][y]);
        }
        printf("\n\n");
    }

    printf(" --- Matrix 2 ---\n\n");
    for(int x=0;x<j;x++){
        for(int y=0;y<k;y++){
            printf("%5d",matrix2[x][y]);
        }
        printf("\n\n");
    }


    //Multiply Matrices Using Threads

    pthread_t thread[MAX_THREADS];

    int thread_number = 0;

    args p[i*k];

    //Start Timer
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    for(int x=0;x<i;x++){
        for(int y=0;y<k;y++){

            p[thread_number].x=x;
            p[thread_number].y=y;

            int status;

            //Create Specific Thread For Each Element In Result Matrix
            status = pthread_create(&thread[thread_number], NULL, mult, (void *) &p[thread_number]);

            //Check For Error
            if(status!=0){
                printf("Error In Threads");
                exit(0);
            }

            thread_number++;
        }
    }


    //Wait For All Threads Done

    for(int z=0;z<(i*k);z++)
        pthread_join(thread[z],NULL );

    end = clock();
    cpu_time_used = ((double) (end-start)) / CLOCKS_PER_SEC;
    //Print Result

    printf(" --- Multiplied Matrix ---\n\n");
    for(int x=0;x<i;x++){
        for(int y=0;y<k;y++){
            printf("%5d", result[x][y]);
        }
        printf("\n\n");
    }


    //Calculate Total Time

    printf("Time Elapsed : %.2f Sec\n\n", cpu_time_used);

    return 0;
}
