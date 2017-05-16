#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void FillInc(int, int *);
void FillDec(int, int *);
void FillRand(int, int *);
long long int CheckSum(const int *, int);
int RunNumber(int *, int);
void PrintMas(int *, int);

int main(){
    int n;
    srand(time(NULL));
    printf("\nВведите размер убывающего массива: ");
    scanf("%d", &n);
    printf("\n");
    int A[n];
    FillDec(n,A);
    printf("\nСерий: %d", RunNumber(A,n));
    return 0;
}

void FillInc(int a, int *A){
    int i;
    A[0]=rand()-(RAND_MAX-RAND_MAX/2);
    for(i=1; i<a; i++){
        A[i]=rand()-(RAND_MAX-RAND_MAX/2);
        while(A[i-1]>A[i]){
            A[i]=rand()-(RAND_MAX-RAND_MAX/2);
        }
    }
    for(i=0;i<a;i++){
	printf("%d ",A[i]);//проверка
    }//*/
}

void FillDec(int a, int * A){
    int i;
    A[0]=rand()-(RAND_MAX-RAND_MAX/2);
    for(i=1; i<a; i++){
        A[i]=rand()-(RAND_MAX-RAND_MAX/2);
        while(A[i-1]<A[i]){
            A[i]=rand()-(RAND_MAX-RAND_MAX/2);
        }
    }
    for(i=0;i<a;i++){
	printf("%d ",A[i]);//проверка
    }//*/
}

void FillRand(int a, int * A){
    int i;
    for(i=1; i<a; i++){
        A[i]=rand()-(RAND_MAX-RAND_MAX/2);
    }
/*    for(i=0;i<a;i++){
	printf("%d ",A[i]);//проверка
    }*/
}

long long int CheckSum(const int *arr, int n){
    int i;
    long long int sum=0;
    for(i=0;i<n;i++){
        sum+=arr[i];
    }
    return sum;
}

int RunNumber(int *a, int n){
    int i, count=1;
    for(i=0;i<n-1;i++){
	if(a[i]<=a[i+1]){
	    count++;
	}
    }
    return count;
}

void PrintMas(int *a, int n){
    int i;
    for(i=0;i<n;i++){
	printf("%d ",a[i]);
    }
}