#include<stdio.h>
#include<time.h>
#define N 3

void seiretu(int kumi,int *num){
	int i,kari,j,k;
	for(j=0;j<kumi;j++){
		for(i=j;i<N-kumi;i+=kumi){
			kari=num[i];
			for(k=i;k<N-kumi;k+=kumi){
				if(kari>num[i+k]){
					num[k]=num[k+kumi];
				}else{
					num[k]=kari;
				}
			}
			//printf("num[%d] ",i);
		}
		printf("\n");
	}
}

void myPrint(int *num){
	int i;
	for(i=0;i<N;i++){
		printf("%d ",num[i]);
	}
	printf("\n");
}

int main(void){
	int i,num[N];

	srand((unsigned)time(NULL));
	for(i=0;i<N;i++){
		num[i]=rand()%(N+1);
	}

	myPrint(num);

	int h=1;
	while(h<=((N-9)/9)){
		h=3*h + 1;
	}
	while(h>0){
		printf("%d\n",h);
		seiretu(h,num);
		h=(h-1)/3;
	}
	myPrint(num);


}
