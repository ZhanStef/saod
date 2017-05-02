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
void BubbleSort(int *A, int n, int *compare, int *move);
void ShakerSort(int *A, int n, int *compare, int *move);

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
// Сортировка случайного массива bublesort
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

// Сортировка bublesort возрастающего массива
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

// Сортировка bublesort убывающего массива
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
/*//ниже убрано тк это не работало из-за того что rand() не попадал на больше или меньше 
// те не мог подобрать следующий элемент массива
void FillInc(int a, int *A){
    int i;
    A[0]=rand()-(RAND_MAX-RAND_MAX/2);
    for(i=1; i<a; i++){
printf("%d\n",i);
fflush(stdout);
        A[i]=rand()-(RAND_MAX-RAND_MAX/2);
        while(A[i-1]>=A[i]){
            A[i]=rand()-(RAND_MAX-RAND_MAX/2);
        }
    }
/*    for(i=0;i<a;i++){
	printf("%d ",A[i]);//проверка
    }
}

void FillDec(int a, int * A){
    int i;
    A[0]=rand()-(RAND_MAX-RAND_MAX/2);
    for(i=1; i<a; i++){
        A[i]=rand()-(RAND_MAX-RAND_MAX/2);
        while(A[i-1]<=A[i]){
            A[i]=rand()-(RAND_MAX-RAND_MAX/2);
        }
    }
/*    for(i=0;i<a;i++){
	printf("%d ",A[i]);//проверка
    }
}
*/
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

void BubbleSort(int *A, int n, int *compare, int *move){
    *move=0;
    *compare=0;
    int i, g, temp;
    for(i=0;i<n-1;i++){
	for(g=n-1;g>i;g--){
//printf("сравнение шт: %d ",*compare);
	    *compare=*compare+1;
	    if(A[g]<A[g-1]){
		temp=A[g-1];
		A[g-1]=A[g];
		A[g]=temp;
		*move=*move+3;
	    }
	}
    }
}

void ShakerSort(int *A, int n, int *compare, int *move){
    *move=0;
    *compare=0;
    int g, temp, L=0, R=n-1, k=n;//k-последний обмен текущей (j),
    do{
	for(g=R;g>=L+1;g--){
	    *compare=*compare+1;
	    if(A[g]<A[g-1]){
		temp=A[g-1];
		A[g-1]=A[g];
		A[g]=temp;
		*move=*move+3;
		k=g;
	    }
	}
	L=k;
	for(g=L;g<=R-1;g++){
	    *compare=*compare+1;
	    if(A[g]>A[g+1]){
		temp=A[g+1];
		A[g+1]=A[g];
		A[g]=temp;
		*move=*move+3;
		k=g;
	    }
	}
	R=k;
    }while(L<R);
}