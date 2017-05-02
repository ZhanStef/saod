#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//программа сортировки массива целых чисел Heapsort
int main(){
    int n;
    int move=0, compare=0;
    srand(time(NULL));
    printf("\nВведите размер массива: ");
    scanf("%d", &n);
//    printf("v\n");
    int *A = (int *)malloc(n*sizeof(int));
//    FillInc(n,A);
//    PrintMas(A,n);
// Сортировка случайного массива 
    move=0;
    compare=0;
    printf("\n\nСортировка shaker rand\n");
    FillRand(n,A);

    PrintMas(A,n);
    printf("\nСерий: %d", RunNumber(A,n));
    printf("\nCheckSum: %Ld\n", CheckSum(A,n));
    ShakerSort(A,n,&compare,&move);

    PrintMas(A,n);
    printf("\nСерий: %d", RunNumber(A,n));
    printf("\nCheckSum: %Ld", CheckSum(A,n));
    printf("\nMove: %d Compare: %d", move, compare);
    printf("\nMove+Compare: %d", move+compare);

// Сортировка возрастающего массива
    move=0;
    compare=0;
    printf("\n\nСортировка shaker возрастающего массива\n");
    FillInc(n,A);

    PrintMas(A,n);
    printf("\nСерий: %d", RunNumber(A,n));
    printf("\nCheckSum: %Ld\n", CheckSum(A,n));
    ShakerSort(A,n,&compare,&move);

    PrintMas(A,n);
    printf("\nСерий: %d", RunNumber(A,n));
    printf("\nCheckSum: %Ld", CheckSum(A,n));
    printf("\nMove: %d Compare: %d", move, compare);
    printf("\nMove+Compare: %d", move+compare);

// Сортировка убывающего массива
    move=0;
    compare=0;
    printf("\n\nСортировка shaker убывающего массива\n");
    FillDec(n,A);

    PrintMas(A,n);
    printf("\nСерий: %d", RunNumber(A,n));
    printf("\nCheckSum: %Ld\n", CheckSum(A,n));
    ShakerSort(A,n,&compare,&move);

    PrintMas(A,n);
    printf("\nСерий: %d", RunNumber(A,n));
    printf("\nCheckSum: %Ld", CheckSum(A,n));
    printf("\nMove: %d Compare: %d", move, compare);
    printf("\nMove+Compare: %d\n", move+compare);
    free(A);
    return 0;
}

void HeapBuilder(int A[], int n, int L){
    int x=A[L-1], i=L, j;
    while(1){
        j=2*i;//тут логика алгоритма номера алгоритма
        if(j>n) return;
        if((j<n)&&A[j]<=A[j-1]) j=j+1;
        if(x<=A[j-1]) return;
        A[i-1]=A[j-1];
        i=j;        
    }
    A[i-1]=x;
}

void HeapSort(int A[], int n){
    int L=n/2;
    while(L>0){
        HeapBuilder(A[],n,L);
        L--;
    }
    int R=n, temp;
    while(R>1){
        temp=A[0];
        A[0]=A[R-1];
        A[R-1]=temp;
        R--;
        HeapBuilder(A[],n,R);
    }
}

void FillRand(int a, int * A){
    int i;
    for(i=1; i<a; i++){
        A[i]=(rand()%201-100);
    }
/*    for(i=0;i<a;i++){
	printf("%d ",A[i]);//проверка
    }*/
}

void FillInc(int n, int *A){
    FillRand(n,A);
    int i, k, min, temp;
    for(i=0;i<n-1;i++){
//minimal search
        min=i;
        for(k=i+1;k<n;k++){
            if(A[k]<A[min]){
            min=k;
            }		
        }
        temp=A[i];
        A[i]=A[min];
        A[min]=temp;
    }
}


void FillDec(int n, int *A){
    FillRand(n,A);
    int i, k, max, temp;
    for(i=0;i<n-1;i++){
//maximal search
        max=i;
        for(k=i+1;k<n;k++){
            if(A[k]>A[max]){
            max=k;
            }		
        }
        temp=A[i];
        A[i]=A[max];
        A[max]=temp;
    }
}
