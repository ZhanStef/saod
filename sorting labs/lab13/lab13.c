﻿#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void FillInc(int, int *);
void FillDec(int, int *);
void FillRand(int, int *);
void PrintMas(int *, int);
int MasSeries(int *, int);

typedef struct elements_of_list{
    struct elements_of_list * next;
    int data;
}  el;

typedef struct queue{
    el *head;
    el *tail;
} que;

void ArrayToList (el *head, int * Array, int n);
void PrintSpis(el *head);
int ListSeries(el *head);
long CheckSumList(el *p);
long CheckSumArray(const int *, int);
void SpisokFree(el *head);
void MergeSort(el *S);
void Separate(el *head, el *a, el*b, int * n);
void MergeListsToQueue(el *head1, int n1, el *head2, int n2, que *S);
void MoveElemFromListHeadToQueueTail(el *head, el *tail);

int main(){
    int n;
    srand(time(NULL));
    printf("\nQuantity of elements ");
    scanf("%d", &n);
    if(n<=0) return 0;
    int *A = (int *)malloc(n*sizeof(int));

//spisok sluchainix na osnove massiva
    printf("\nArray of rand numbers: ");
    FillRand(n,A);
    PrintMas(A,n);
    printf("\nSeries: %d", MasSeries(A,n));
    printf("\nCheckSum: %ld\n", CheckSumArray(A,n));
//zapisb v spisok
    el *head_list=(el *)malloc(sizeof(el));
    if(head_list==NULL) return -1;
    ArrayToList(head_list, A, n);
    printf("\nList of rand numbers: ");
    PrintSpis(head_list);
    printf("\nSeries: %d", ListSeries(head_list));
    printf("\nCheckSum: %ld\n", CheckSumList(head_list));
//sorting of spisok
    MergeSort(head_list);
    printf("\nList of sorted be Merge numbers: ");
    PrintSpis(head_list);
    printf("\nSeries: %d", ListSeries(head_list));
    printf("\nCheckSum: %ld\n", CheckSumList(head_list));
//mem cleaning
    SpisokFree(head_list);
    head_list=NULL;

    //spisok vozrast na osnove massiva
    printf("\nArray of increase numbers ");
    FillInc(n,A);
    PrintMas(A,n);
    printf("\nSeries: %d", MasSeries(A,n));
    printf("\nCheckSum: %ld\n", CheckSumArray(A,n));
    //zapisb v spisok
    head_list=(el *)malloc(sizeof(el));
    if(head_list==NULL) return -1;
    ArrayToList(head_list, A, n);
    printf("\nList of increase numbers ");
    PrintSpis(head_list);
    printf("\nSeries: %d", ListSeries(head_list));
    printf("\nCheckSum: %ld\n", CheckSumList(head_list));
    SpisokFree(head_list);
    head_list=NULL;

    //spisok ubivaushih na osnove massiva
    printf("\nArray of decrease numbers ");
    FillDec(n,A);
    PrintMas(A,n);
    printf("\nSeries: %d", MasSeries(A,n));
    printf("\nCheckSum: %ld\n", CheckSumArray(A,n));
    //zapisb v spisok
    head_list=(el *)malloc(sizeof(el));
    if(head_list==NULL) return -1;
    ArrayToList(head_list, A, n);
    printf("\nList of decrease numbers ");
    PrintSpis(head_list);
    printf("\nSeries: %d", ListSeries(head_list));
    printf("\nCheckSum: %ld\n", CheckSumList(head_list));
    SpisokFree(head_list);
    head_list=NULL;

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
    for(i=0; i<a; i++){
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

long CheckSumArray(const int *arr, int n){
    int i;
    long sum=0;
    for(i=0;i<n;i++){
        sum+=arr[i];
    }
    return sum;
}

int MasSeries(int *a, int n){
    int i, count=1;
    for(i=0;i<n-1;i++){
    if(a[i]>a[i+1]){
        count++;
    }
    }
    return count;
}

void PrintSpis(el *head){
    printf("\n");
    if(head!=NULL){
        do{
            printf("%d ", head->data);
            if(head->next!=NULL){
                head=head->next;
            }
            else{
                break;
            }
        }while(1);
    }
}

void ArrayToList (el *head, int * A, int n){
    el *p=head, *new;
    p->data=A[0];
    p->next=NULL;
    int i;
    for(i=1; i<n; i++){
        new=(el *)malloc(sizeof(el));
        new->next=p->next;
        p->next=new;
        p=new;
        p->data=A[i];
    }
}

int ListSeries(el *head){
    int series=1;
    el *p=head;
    if (head==NULL) return -1;
    while(1){
        if((p->data)>(p->next->data)) series++;
        if(p->next->next==NULL) return series;
        p=p->next;
    }
}

long CheckSumList(el *p){
    long sum=0;
    while (1) {
        sum+=p->data;
        if(p->next==NULL) return sum;
        p=p->next;
    }
}

void SpisokFree(el *head){
    el * p=head, * del;
    while (1) {
        del=p;
        if(p->next==NULL) break;
        p=p->next;
        free(del);
    }
    free(del);
}

void MergeSort(el *S ){
    el *a=(el *)malloc(sizeof(el*)), *b=(el *)malloc(sizeof(el*));
    int n=0, l, r;
    Separate(S, a, b, &n);
    int p=1;
    que C[2];//=(que *)malloc(sizeof(que*)*2);
    //C[1].head=(el *)malloc(sizeof(el*));
    //C[2].head=(el *)malloc(sizeof(el*));
    while(p<n){
        C[0].tail=C[0].head;
        C[1].tail=C[1].head;
        int i=0;
        int ts=n;
        while(ts>0){
            if(ts>=p){
                l=p;
            }
            else{
                l=ts;
            }
            if(ts>=p){
                r=p;
            }
            else{
                r=ts;
            }
            ts=ts-r;
            MergeListsToQueue(a, l, b, r, &C[i]);
            i=1-i;
        }
        a=C[0].head;
        b=C[1].head;
        p=2*p;
    }
    C[0].tail->next=NULL;
    S=C[0].head;
}

void MergeListsToQueue(el *head1, int n1, el *head2, int n2, que *S){
    el *a=head1, *b=head2;
    while(n1!=0 && n2!=0){
        if(a->data<=b->data){
            MoveElemFromListHeadToQueueTail(head1, S->tail);
            n1--;
        }
        else{
            MoveElemFromListHeadToQueueTail(head2, S->tail);
            n2--;
        }
    }
    while(n1>0){
        MoveElemFromListHeadToQueueTail(head1, S->tail);
        n1--;
    }
    while(n2>0){
        MoveElemFromListHeadToQueueTail(head2, S->tail);
        n2--;
    }
}

void Separate(el *head, el *a, el*b, int *n){
    *n=1;
    a=head;
    b=head->next;
    el *k=a, *p=b;
    while(p!=NULL){
        n++;
        k->next=p->next;
        k=p;
        p=p->next;
    }
}

void MoveElemFromListHeadToQueueTail(el *head, el *tail){
    tail->next=head;
    tail=head;
    head=head->next;
}

void DigitalSort(el **S){
	int j=2;
	que C[10];
	el *p;
	while(j<0){
		int i=0;
		while(i<10){
                        C[0].tail=(el *)&(C[0].head);
		}
                p=*S;
		while(p!=NULL){
			d
		}
	}
}