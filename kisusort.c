#include<stdio.h>
#include<time.h>
#define N 20000

void myPrint(int *num);
void myBaburu(int,int *num);

int main(void){
	int i,num[N];

	//乱数を生成
	srand((unsigned)time(NULL));
	for(i=0;i<N;i++){
		num[i]=rand()%(N+1);
	}
	//元データを表示するかどうか
	int yes;
	printf("元データ(%d個)を表示しますか(0 or 1)-> ",N);
	scanf("%d",&yes);
	if(yes){
		myPrint(num);
	}
	//ここでバブルソートを呼び出し
	clock_t t_start,t_end;
	t_start=clock();
	for(i=1;i<N;i*=10){
		//iの値が1,10,100...と変化する
		myBaburu(i,num);
	}
	t_end = clock();

	printf("%f秒でソートしました\n",(double)(t_end-t_start)/CLOCKS_PER_SEC);
	printf("結果を表示しますか(0 or 1)-> ");
	scanf("%d",&yes);
	if(yes){
		myPrint(num);
	}

	return 0;
}

void myPrint(int *num){
	int i;
	for(i=0;i<N;i++){
		printf("%d ",num[i]);
	}
	printf("\n");
}

void myBaburu(int n,int *num){
	//nの位を基準にソート
	printf("%dの位を基準にソートしています\n",n);
	int jadge = 1,i;
	while(jadge){
		jadge = 0;
		for(i=0;i<N-1;i++){
			if((num[i]/n)%10>(num[i+1]/n)%10){
				int kari = num[i];
				num[i] = num[i+1];
				num[i+1] = kari;
				//入れ替えが発生したトリガを1
				jadge=1;
			}
		}
	}
}
