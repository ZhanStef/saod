#include <stdio.h>
#include <stdlib.h>
void FillInc(int a);
void FillDec(int a);
void FillRand(int a);
long long int CheckSum(const int *arr, int n);

main(){
int a=10;
FillInc(a);
return 0;
}

void FillInc(int a){
    int A[a], i;
    A[0]=rand()-(RAND_MAX-RAND_MAX/2);
    for(i=1; i<a; i++){
        A[i]=rand()-(RAND_MAX-RAND_MAX/2);
        while(A[i-1]>A[i]){
            A[i]=rand()-(RAND_MAX-RAND_MAX/2);
        }
    }
/*    for(i=0;i<a;i++){
	printf("%d ",A[i]);//проверка
    }*/
}

void FillDec(int a){
    int A[a], i;
    A[0]=rand()-(RAND_MAX-RAND_MAX/2);
    for(i=1; i<a; i++){
        A[i]=rand()-(RAND_MAX-RAND_MAX/2);
        while(A[i-1]<A[i]){
            A[i]=rand()-(RAND_MAX-RAND_MAX/2);
        }
    }
/*    for(i=0;i<a;i++){
	printf("%d ",A[i]);//проверка
    }*/
}

void FillRand(int a){
    int A[a], i;
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
    return sum;
    }
}

