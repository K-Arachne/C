#include<stdio.h>
#include<time.h>
#define N 20000

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
	printf("\n間隔%dでソート\n",kumi);
	//myPrint(num);
}

void myPrint(int *num){
	int i;
	for(i=0;i<N;i++){
		printf("%d ",num[i]);
	}
	printf("\n");
}

int main(void){
	int i,num[N],yes;

	srand((unsigned)time(NULL));
	for(i=0;i<N;i++){
		num[i]=rand()%(N+1);
	}

	printf("元データ(%d個)を表示しますか(0 or 1)-> ",N);
	scanf("%d",&yes);
	if(yes){
		myPrint(num);
	}

	int h=1;
	while(h<=((N-9)/9)){
		h=3*h + 1;
	}

	clock_t t_start,t_end;
	t_start=clock();
	while(h>0){
		seiretu(h,num);
		h=(h-1)/3;
	}
	t_end = clock();

	printf("\n%f秒でソートしました\n",(double)(t_end-t_start)/CLOCKS_PER_SEC);

	printf("結果を表示しますか(0 or 1)-> ");
	scanf("%d",&yes);
	if(yes){
		myPrint(num);
	}

	return 0;
}
