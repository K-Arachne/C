#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 20000
#define myFor(x) for(i=0;i<x;i++)

int main(void){
	srand((unsigned) time(NULL));
	clock_t t_start,t_end;
	t_start=clock();

	int intI[N];
	int i;

	printf("----------before---------\n");

	myFor(N){
		intI[i]=rand()%(N+1);
		printf("%d ",intI[i]);
		/*if(i%30==0){
                        printf("\n");
                }*/
	}
	printf("\n計算中");
	int jadge = 1;
	while(jadge){
		jadge=0;
		myFor(N-1){
			if(intI[i]>intI[i+1]){
				//入れ替えの処理
				int kari = intI[i];
				intI[i] = intI[i+1];
				intI[i+1] = kari;
				//入れ替えが発生したトリガを1
				jadge=1;
			}
		}
		//printf(".");
	}
	
	printf("\n----------After----------\n");

	myFor(N){
		printf("%d ",intI[i]);
		/*if(i%30==0){
			printf("\n");
		}*/
	}

	t_end = clock();
	printf("time = %f s\n",(double)(t_end-t_start)/CLOCKS_PER_SEC);
	return 0;
}
