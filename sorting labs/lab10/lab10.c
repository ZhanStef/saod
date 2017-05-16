#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void FillInc(int, int *);
void FillDec(int, int *);
void FillRand(int, int *);
long long int CheckSum(const int *, int);
int RunNumber(int *, int);
void PrintMas(int *, int);
void QuickSort(int *A, int L, int R, int *move, int *compare);

int main()
{
	int n;
    int move=0, compare=0;
    srand(time(NULL));
    printf("\nВведите размер массива: ");
    scanf("%d", &n);
    int *A = (int *)malloc(n*sizeof(int));
// Сортировка случайного массива
    move=0;
    compare=0;
    printf("\n\nСортировка Quick rand\n");
    FillRand(n,A);

    PrintMas(A,n);
    printf("\nСерий: %d", RunNumber(A,n));
    printf("\nCheckSum: %Ld\n", CheckSum(A,n));
    QuickSort(A,0,n-1,&compare,&move);

    PrintMas(A,n);
    printf("\nСерий: %d", RunNumber(A,n));
    printf("\nCheckSum: %Ld", CheckSum(A,n));
    printf("\nMove: %d Compare: %d", move, compare);
    printf("\nMove+Compare: %d", move+compare);

// Сортировка возрастающего массива
    move=0;
    compare=0;
    printf("\n\nСортировка Quick возрастающего массива\n");
    FillInc(n,A);

    PrintMas(A,n);
    printf("\nСерий: %d", RunNumber(A,n));
    printf("\nCheckSum: %Ld\n", CheckSum(A,n));
    QuickSort(A,0,n-1,&compare,&move);

    PrintMas(A,n);
    printf("\nСерий: %d", RunNumber(A,n));
    printf("\nCheckSum: %Ld", CheckSum(A,n));
    printf("\nMove: %d Compare: %d", move, compare);
    printf("\nMove+Compare: %d", move+compare);

// Сортировка убывающего массива
    move=0;
    compare=0;
    printf("\n\nСортировка Quick убывающего массива\n");
    FillDec(n,A);

    PrintMas(A,n);
    printf("\nСерий: %d", RunNumber(A,n));
    printf("\nCheckSum: %Ld\n", CheckSum(A,n));
    QuickSort(A,0,n-1,&compare,&move);

    PrintMas(A,n);
    printf("\nСерий: %d", RunNumber(A,n));
    printf("\nCheckSum: %Ld", CheckSum(A,n));
    printf("\nMove: %d Compare: %d", move, compare);
    printf("\nMove+Compare: %d\n", move+compare);
    free(A);
    return 0;
}

void QuickSort(int *A, int L, int R, int *move, int *compare){
	int X=A[L], i=L, j=R, temp;
	while(i<=j){
		while(A[i]<X) i++;
		while(A[j]>X) j--;
		if(i<=j){
			(*move)+=3;
			temp=A[i];
			A[i]=A[j];
			A[j]=temp;
			i++;
			j--;
		}
	}
	if(L<j) QuickSort(A, L, j, move, compare);
	if(i<R) QuickSort(A, i, R, move, compare);
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
