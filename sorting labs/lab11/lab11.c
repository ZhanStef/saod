#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void FillInc(int, int *);
void FillDec(int, int *);
void FillRand(int, int *);
void PrintMas(int *, int);
long long int CheckSum(const int *, int);
int RunNumber(int *, int);
void PrintSpis(el *);

typedef struct elements_of_list{
	struct queue * next;
	int data; 
}  el;

typedef struct queue{
	el *head;
	el *tail;
} que;



int main(){
	int n;
    int move=0, compare=0;
    srand(time(NULL));
    printf("\nВведите размер последовательности: ");
    scanf("%d", &n);
    int *A = (int *)malloc(n*sizeof(int));
//spisok sluchainix na osnove massiva
    FillRand(n,A);
    PrintMas(A,n);
    printf("\nСерий: %d", RunNumber(A,n));
    printf("\nCheckSum: %Ld\n", CheckSum(A,n));
//zapisb v spisok
	int i;
	el *p=(el *)malloc(sizeof(el)), *head_list=p, *new;
	p->data=A[0];
	p->next=NULL;
	for(i=1; i<n; i++){
		new=(el *)malloc(sizeof(el));
		new->next=p->next;
		p->next=new;
		p=new;
		p->data=A[i];
	}
	PrintSpis(head_list);
	return 0;
}

void PrintMas(int *a, int n){
    int i;
    for(i=0;i<n;i++){
    printf("%d ",a[i]);
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

void PrintSpis(el *p){
	printf("\n");
	if((p->next!=NULL) && p!=NULL){
		do{
			printf("%d ", p->data);
			p=p->next;
		}while(p->next!=NULL);
	}
}
