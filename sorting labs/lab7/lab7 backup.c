#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void PrintMas(char arr[], int n);
void RandMas(char arr[], int n);
void ShakerSort(char *A, int n);
int binsearchV1(char *A, int n, char x, int *compare);
int binsearchV2(char *A, int n, char x, int *compare);

int main(){
	char *M;
	int n, compareV1, compareV2;
//	printf("\nВведите размер массива: ");
//	scanf("%d",&n);
	for(n=100;n<=1000;n+=100){
		M=(char *) malloc(sizeof(char)* n);
		RandMas(M,n);
		ShakerSort(M,n);
		compareV1=0;
		binsearchV1(M, n, M[1], &compareV1);
		compareV2=0;
		binsearchV2(M, n, M[1], &compareV2);
		printf("Количество С для массива размером %d для V1=%d, V2=%d", n, compareV1, compareV2);
		free(M);
		M=NULL;
	}
	return 0;
}

int binsearchV1(char *A, int n, char x, int *compare){
		int L=0, R=n-1, med;
		while(L<=R){
			med=(L+R)/2;
			compare++;
			if(A[med]==x){
				return med;
			}
			compare++;
			if(A[med]<x){
				L=med+1;
			}
			else{
				R=med-1;
			}
		}
	return -1;
}

int binsearchV2(char *A, int n, char x, int *compare){
	int L=0, R=n-1, med;
	while(L<R){
		med=(L+R)/2;
		compare++;
		if(A[med]<x){
			L=med+1;
		}
		else{
			R=med;
		}
	}
	compare++;
	if(A[R]==x){
		return R;
	}
	else{
		return -1;
	}
}

void RandMas(char arr[], int n){//генерация массива строковых символов
    srand(time(NULL));
    for(;--n>=0;){
        arr[n]=(char)rand()%26+97;
    }
}

void PrintMas(char arr[], int n){
	int i;
	printf("\n");
	for(i=0;i<n;n++){
		printf(" %c",arr[i]);
	}
}

void ShakerSort(char *A, int n){
    int g, L=0, R=n-1, k=n;//k-последний обмен текущей (j),
	char temp;
    do{
	for(g=R;g>=L+1;g--){
	    if(A[g]>A[g-1]){
		temp=A[g-1];
		A[g-1]=A[g];
		A[g]=temp;
		k=g;
	    }
	}
	L=k;
	for(g=L;g<=R-1;g++){
	    if(A[g]<A[g+1]){
		temp=A[g+1];
		A[g+1]=A[g];
		A[g]=temp;
		k=g;
	    }
	}
	R=k;
    }while(L<R);
}
