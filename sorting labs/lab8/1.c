#include <stdio.h>
#include <stdlib.h>
#define N 4
#define Len 30

typedef struct spravochnick{
	char fam[Len];
	char name[Len];
	char otech[Len];
	int tel;
} spr;

void vivod(spr *a, int n);
void Indexing(spr *isx, spr **index, int n);
void SortbyFam(spr **A, int n);
void SortbyName(spr **A, int n);

int main(){
	spr spis[N]={
		{"Юн","Ын","Инович",8913001},
		{"Ким","Пак","Ынович",8913002},
		{"Стефанович","Жан","Андреевич",8913003},
		{"Cтефанович","Пак","Кимовна",8913004}
	};
    vivod(spis, N);
    
    spr **index1=(spr**)malloc(sizeof(spr*)*N);
    Indexing(spis, index1, N);
    SortbyFam(index1, N);
    vivod(index1[0], N);
 /*
    spr **index2=(spr**)malloc(sizeof(spr*)*N);
    Indexing(spis, index2, N);
    vivod(spis, N);
   */ 
    return 0;
}

void vivod(spr *a, int n){
	int i;
	printf("\n");
	for(i=0; i<n; i++ ,a++){
		printf("\n№%d Фамилия:%s, Имя: %s, Отечество: %s, Тел: %d",i+1,a->fam,a->name,a->otech,a->tel);
	}
}

void Indexing(spr *isx, spr **index, int n){
	int i;
	for(i=0; i<n; i++){
		index[i]=isx++;
	}
}

void SortbyFam(spr **A, int n){
	//A[i]->fam
	spr *temp;
	int g, L=0, R=n-1, k=n, i;//k-последний обмен текущей (j),
    for(i=0; i<Len; i++){
		do{
			for(g=R;g>=L+1;g--){
				if((A[g]->fam[i])<(A[g-1]->fam[i])){
				temp=A[g-1];
				A[g-1]=A[g];
				A[g]=temp;
				k=g;
				}
			}
			L=k;
			for(g=L;g<=R-1;g++){
				if((A[g]->fam[i])>(A[g+1]->fam[i])){
				temp=A[g+1];
				A[g+1]=A[g];
				A[g]=temp;
				k=g;
				}
			}
			R=k;
		}while(L<R);
	}
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
int FirstSt1(char *st1, char *st2){//выводит 1 если 1ая раньше должна стоять и 0 если 2ая раньше
    int i;
    for(i=0;st1[i]!='\0' && st2[i]!='\0'; i++){
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
        return 0;//st2 короче и надо записывать
    }
    else{
        return 1;
    }
}
