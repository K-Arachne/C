#include<stdio.h>
#include<time.h>
#define N 20

void myPrint(int *);

void seiretu(int kumi,int *num){
	int i,kari,j,k;
	for(k=0;k<kumi;k++){
		for(i=k;i<N-kumi;i+=kumi){
			kari = num[i+kumi];
			for(j=i;j>=0;j-=kumi){
				if(num[j]>kari){
					num[j+kumi] = num[j];
				}else{
					break;
				}
				num[j]=kari;
			}
		}
	}
	printf("%d間隔でソート\n",kumi);
	myPrint(num);
}

void myPrint(int *num){
	int i;
	for(i=0;i<N;i++){
		printf("%2d ",num[i]);
	}
	printf("\n");
}

int main(void){
	int i,num[N];

	srand((unsigned)time(NULL));
	for(i=0;i<N;i++){
		//num[i]=rand()%(N+1);
		num[i]=N-i;
	}

	printf("元データ\n");
	myPrint(num);

	int h=1;
	while(h<=((N-9)/9)){
		h=3*h + 1;
	}
	while(h>0){
		seiretu(h,num);
		h=(h-1)/3;
	}

	printf("結果\n");
	myPrint(num);


}
