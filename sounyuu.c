#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 10
#define myFor(x) for(i=0;i<x;i++)

void myPrint(int num[]){
	int i;
	myFor(N){
		printf("%d ",num[i]);
	}
	printf("/n");
}

int main(void){
	srand((unsigned) time(NULL));

	int intI[N];
	int i;

	printf("----------before---------\n");

	myFor(N){
		intI[i]=rand()%(N+1);
	}
	myPrint(intI);
	printf("計算中");

	int kari,j;
	myFor(N-1){
		kari = intI[i+1];
		for(j=i;j>=0;j--){
			if(intI[j]>kari){
				intI[j+1] = intI[j];
			}else{
				break;
			}
			intI[j]=kari;
		}
	}


	printf("\n----------After----------\n");
	myPrint(intI);

	return 0;
}
