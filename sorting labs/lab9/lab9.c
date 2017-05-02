#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void FillInc(int, int *);
void FillDec(int, int *);
void FillRand(int, int *);
long long int CheckSum(const int *, int);
int RunNumber(int *, int);
void PrintMas(int *, int);
void HeapSort(int A[], int n, int *move, int *compare);
void HeapBuilder(int A[], int n, int L, int *move, int *compare);

//программа сортировки массива целых чисел Heapsort
int main(){
    int n;
    int move=0, compare=0;
    srand(time(NULL));
    printf("\nВведите размер массива: ");
    scanf("%d", &n);
    int *A = (int *)malloc(n*sizeof(int));
// Сортировка случайного массива
    move=0;
    compare=0;
    printf("\n\nСортировка heap rand\n");
    FillRand(n,A);

    PrintMas(A,n);
    printf("\nСерий: %d", RunNumber(A,n));
    printf("\nCheckSum: %Ld\n", CheckSum(A,n));
    HeapSort(A,n,&compare,&move);

    PrintMas(A,n);
    printf("\nСерий: %d", RunNumber(A,n));
    printf("\nCheckSum: %Ld", CheckSum(A,n));
    printf("\nMove: %d Compare: %d", move, compare);
    printf("\nMove+Compare: %d", move+compare);

// Сортировка возрастающего массива
    move=0;
    compare=0;
    printf("\n\nСортировка heap возрастающего массива\n");
    FillInc(n,A);

    PrintMas(A,n);
    printf("\nСерий: %d", RunNumber(A,n));
    printf("\nCheckSum: %Ld\n", CheckSum(A,n));
    HeapSort(A,n,&compare,&move);

    PrintMas(A,n);
    printf("\nСерий: %d", RunNumber(A,n));
    printf("\nCheckSum: %Ld", CheckSum(A,n));
    printf("\nMove: %d Compare: %d", move, compare);
    printf("\nMove+Compare: %d", move+compare);

// Сортировка убывающего массива
    move=0;
    compare=0;
    printf("\n\nСортировка heap убывающего массива\n");
    FillDec(n,A);

    PrintMas(A,n);
    printf("\nСерий: %d", RunNumber(A,n));
    printf("\nCheckSum: %Ld\n", CheckSum(A,n));
    HeapSort(A,n,&compare,&move);

    PrintMas(A,n);
    printf("\nСерий: %d", RunNumber(A,n));
    printf("\nCheckSum: %Ld", CheckSum(A,n));
    printf("\nMove: %d Compare: %d", move, compare);
    printf("\nMove+Compare: %d\n", move+compare);
    free(A);
    return 0;
}

void HeapBuilder(int A[], int n, int L, int *move, int *compare){
    int x=A[L-1], i=L, j;
    *move++;
    while(1){
        j=2*i;//тут логика алгоритма номера алгоритма
        if(j>n) return;
        *compare++;
        if((j<n)&&A[j]<=A[j-1]) j=j+1;
        *compare++;
        if(x<=A[j-1]) return;
        *move++;
        A[i-1]=A[j-1];
        i=j;
    }
    *move++;
    A[i-1]=x;
}

void HeapSort(int A[], int n, int *move, int *compare){
    int L=n/2;
    while(L>0){
        HeapBuilder(A, n, L, move, compare);
        L--;
    }
    int temp;
    while(n>1){
        *move++;
        temp=A[0];
        A[0]=A[n-1];
        A[n-1]=temp;
        n--;
        HeapBuilder(A,n,1, move, compare);
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
    if(a[i]>a[i+1]){
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
