#include<stdio.h>
#define N 100
int main(void)
{
	int search[N-1];
	int sosu[N-1];
	int i,sosu_num=0,k=2,f;
	for(i=0;i<N;i++){
		search[i] = i+2;
	}
	for(f=0;k*k<=N;f++){
		for(i=0;search[i]==0;i++){}
		k=search[i];
		sosu[sosu_num++]=k;
		for(i=0;i<N;i++){
			if(search[i]%k==0){
				search[i]=0;
			}
		}
	}

	for(i=0;i<N-1;i++){
		if(search[i]!=0){
			sosu[sosu_num++]=search[i];
		}
	}

	for(f=0;f<sosu_num;f++){
		printf("%d\n",sosu[f]);
	}

	printf("\n素数の数は%d個です\n",sosu_num+1);

	return 0;

}
