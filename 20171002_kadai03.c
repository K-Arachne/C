#include<stdio.h>

#define myFor(x) for(i=0;i<x;i++)
int main(void)
{
	int i,i1,i2,prime_fig,prime_num=0;
	int prime[100]={0};

	i1 = 2;
	myFor(99){
		i2 = 2;
		prime_fig = 1;
		myFor(i1-2){
			if(i1%i2==0){
				prime_fig = 0;
			}
			i2++;
		}
		if(prime_fig){
			prime[prime_num++] = i1;
		}
		i1++;
	}

	myFor(prime_num){
		printf("%d\n",prime[i]);
	}

	return 0;
}
