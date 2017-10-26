#include<stdio.h>
#include<time.h>
#define N 10

int seiretu(int kumi,int *num[]){
	int i,kari;
	for(i=0;i<N/kumi;i++){
		if(num[i]>num[i+kumi]){
			kari=num[i];
			num[i]=num[i+kumi];
			num[i+kumi]=kari;
		}
	}
}

	int main(void){
		int i,num[N];

		srand((unsigned)time(NULL));
		for(i=0;i<N;i++){
			num[i]=rand()%(N+1);
		}

		int kumi=N/2
	}
