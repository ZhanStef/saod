#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void FillInc(int, int *);
void FillDec(int, int *);
void FillRand(int, int *);
long long int CheckSum(const int *, int);
int RunNumber(int *, int);
void PrintMas(int *, int);
void SelectSort_adv(int *, int , int *, int *);
void SelectSort(int *, int , int *, int *);

int main(){
    int n;
    int move, compare;
    srand(time(NULL));
    printf("\nВведите размер массива: ");
    scanf("%d", &n);
    printf("\n");
    int A[n];
//Сортировка случайного массива улучшенная
    move=0;
    compare=0;
    printf("\n\nСортировка случайного массива улучшенная\n");
    FillRand(n,A);

    PrintMas(A,n);
    printf("\nСерий: %d", RunNumber(A,n));
    printf("\nCheckSum: %Ld\n", CheckSum(A,n));
    SelectSort_adv(A,n,&compare,&move);

    PrintMas(A,n);
    printf("\nСерий: %d", RunNumber(A,n));
    printf("\nCheckSum: %Ld", CheckSum(A,n));
    printf("\nMove: %d Compare: %d", move, compare);

// Сортировка случайного массива обычным алгоритмом выборки
    move=0;
    compare=0;
    printf("\n\nСортировка обычным алгоритмом выборки\n");
    FillRand(n,A);

    PrintMas(A,n);
    printf("\nСерий: %d", RunNumber(A,n));
    printf("\nCheckSum: %Ld\n", CheckSum(A,n));
    SelectSort(A,n,&compare,&move);

    PrintMas(A,n);
    printf("\nСерий: %d", RunNumber(A,n));
    printf("\nCheckSum: %Ld", CheckSum(A,n));
    printf("\nMove: %d Compare: %d", move, compare);

// Сортировка обычным алгоритмом выборки возрастающего массива
    move=0;
    compare=0;
    printf("\n\nСортировка обычным алгоритмом выборки возрастающего массива\n");
    FillInc(n,A);

    PrintMas(A,n);
    printf("\nСерий: %d", RunNumber(A,n));
    printf("\nCheckSum: %Ld\n", CheckSum(A,n));
    SelectSort(A,n,&compare,&move);

    PrintMas(A,n);
    printf("\nСерий: %d", RunNumber(A,n));
    printf("\nCheckSum: %Ld", CheckSum(A,n));
    printf("\nMove: %d Compare: %d", move, compare);

// Сортировка обычным алгоритмом выборки убывающего массива
    move=0;
    compare=0;
    printf("\n\nСортировка обычным алгоритмом выборки убывающего массива\n");
    FillDec(n,A);

    PrintMas(A,n);
    printf("\nСерий: %d", RunNumber(A,n));
    printf("\nCheckSum: %Ld\n", CheckSum(A,n));
    SelectSort(A,n,&compare,&move);

    PrintMas(A,n);
    printf("\nСерий: %d", RunNumber(A,n));
    printf("\nCheckSum: %Ld", CheckSum(A,n));
    printf("\nMove: %d Compare: %d", move, compare);

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
/*    for(i=0;i<a;i++){
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
/*    for(i=0;i<a;i++){
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

void SelectSort_adv(int *A, int n, int *compare, int *move){
    int i, k, min,temp;
    *move=0;
    *compare=0;
    for(i=0;i<n-1;i++){
//minimal search
	min=i;
	for(k=i+1;k<n;k++){
	    (*compare)++;
	    if(A[k]<A[min]){
		min=k;
	    }
	}
        (*compare)++;
	if(A[i]!=A[min]){
	    temp=A[i];
	    A[i]=A[min];
	    A[min]=temp;
	    (*move)=(*move)+3;
	}
    }
}

void SelectSort(int *A, int n, int *compare, int *move){
    int i, k, min,temp;
    *move=0;
    *compare=0;
    for(i=0;i<n-1;i++){
//minimal search
	min=i;
	for(k=i+1;k<n;k++){
	    (*compare)++;
	    if(A[k]<A[min]){
		min=k;
	    }
	}
	temp=A[i];
	A[i]=A[min];
	A[min]=temp;
	(*move)=(*move)+3;
    }
}
