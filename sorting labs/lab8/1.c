#include <stdio.h>
#include <stdlib.h>
#define N 6
#define Len 30

typedef struct spravochnick{
	char fam[Len];
	char name[Len];
	char otech[Len];
	int tel;
} spr;

int FirstSt1(char *st1, char *st2);
void vivod(spr **a, int n);
void Indexing(spr *isx, spr **index, int n);
void SortbyFam(spr **A, int n);
void SortbyName(spr **A, int n);

int main(){
	spr spis[N]={
		{"buЮн","Ын","Инович",8913001},
		{"kКим","Пак","Ынович",8913002},
		{"zsСтефанович","Жан","Андреевич",8913003},
		{"asCтефанович","Пак","Кимовна",8913004},
		{"zaЯкубович","Леонид","Сергеевич",8913005},
		{"gГапонович","Миша","Алексеевич",8913006}
	};
//    vivod(spis, N);
    
    spr **index1=(spr**)malloc(sizeof(spr*)*N);
    Indexing(spis, index1, N);
    printf("\nIndexing check");
    vivod(index1, N);
    printf("\nIndexing checked");
    
    SortbyFam(index1, N);
    vivod(index1, N);
	/*
    spr **index2=(spr**)malloc(sizeof(spr*)*N);
    Indexing(spis, index2, N);
    vivod(spis, N);
   */ 
    return 0;
}

void vivod(spr **a, int n){
	int i;
	printf("\n");
	for(i=0; i<n; i++){
		printf("\n№%d Фамилия:%s, Имя: %s, Отечество: %s, Тел: %d",i+1, a[i]->fam, a[i]->name, a[i]->otech, a[i]->tel);
	}
}

void Indexing(spr *isx, spr **index, int n){
	int i;//this f make array of pointers to spr
	for(i=0; i<n; i++){
		index[i]=isx++;
	}
}

void SortbyFam(spr **A, int n){
	//A[i]->fam
	spr *temp;
	int g, L=0, R=n-1, k=n;//k-последний обмен текущей (j),
	do{
		for(g=R;g>=L+1;g--){
			if(FirstSt1(A[g]->fam,A[g-1]->fam)){
			temp=A[g-1];
			A[g-1]=A[g];
			A[g]=temp;
			k=g;
			}
			vivod(A,n);
		}
		printf("\n Result right to left ");
		vivod(A,n);
		printf("\nКонец справ налево хода\n next: Left to right ");
		L=k;
		for(g=L;g<=(R-1);g++){
			if(FirstSt1(A[g+1]->fam,A[g]->fam)){
			temp=A[g+1];
			A[g+1]=A[g];
			A[g]=temp;
			k=g;
			}
			vivod(A,n);
		}
		printf("\n\n Result left to right");
		vivod(A,n);
		printf("\nКонец left to right \n next:Begin right to left ");
		R=k;
		vivod(A,n);
	}while(L<R);
}
/*
void SortbyName(spr **index, int n){

}

void ShakerSort(int *A, int n){
    int g, temp, L=0, R=n-1, k=n;//k-последний обмен текущей (j),
    do{
	for(g=R;g>=L+1;g--){
	    if(A[g]<A[g-1]){
		temp=A[g-1];
		A[g-1]=A[g];
		A[g]=temp;
		k=g;
	    }
	}
	L=k;
	for(g=L;g<=R-1;g++){
	    if(A[g]>A[g+1]){
		temp=A[g+1];
		A[g+1]=A[g];
		A[g]=temp;
		k=g;
	    }
	}
	R=k;
    }while(L<R);
}
*/
int FirstSt1(char *st1, char *st2){//выводит 1 если 1ая раньше должна стоять и 0 если 2ая раньше анало st1<st2
    int i;
    for(i=0; st1[i]!='\0' && st2[i]!='\0'; i++){
		printf("\n compare:%c < %c",st1[i],st2[i]);
        if(st1[i]==st2[i]) {
            continue;
        }
        else{
            if(st1[i]<st2[i]) {
                return 1;//надо продолжать в вызывающец функции
            }
            else{
                return 0;//st2 раньше должна быть те надо записывать
            }
        }
    }
    if(st1[i]=='\0' && st2[i]=='\0') return 0;
    if(st1[i]!='\0' && st2[i]=='\0'){
        return 0;//st2 короче и надо записывать раньше st1
    }
    else{
        return 1;
    }
}
