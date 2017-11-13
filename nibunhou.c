#include<stdio.h>
double myF(double x);


int main(void){
	double a,b,e;

	//a,bの値が正しく入力されるまで繰り返す
	while(1){
		printf("区間a,bを入力->");
		scanf("%lf,%lf",&a,&b);
		if(myF(a)*myF(b)<0){
			break;
		}else{
			printf("区間が不正です\n");
		}
	}

	printf("探索精度eを入力 e=");
	scanf("%lf",&e);

	int fugoA,fugoB,fugoAB;
	while(1){
		//|b-a|<e となったら終了
		if((b-a)<e){
			break;
		}

		//符号が正なら1,負なら0
		fugoA=(0<myF(a));
		fugoB=(0<myF(b));
		fugoAB=(0<myF((a+b)/2));

		if(fugoAB==fugoA){
			a=(a+b)/2;
		}else if(fugoAB==fugoB){
			b=(a+b)/2;
		}
		printf("解は%fと%fの間にあると考えられます\n",a,b);
	}

	printf("答えは約%fです",b);

	return 0;

}

//f(x)を返す関数
double myF(double x){
	//100km/hをm/sに変換して、vに代入
	double v = 27.7778;
	double g = 9.8;
	return ( 0.75*v	+ (v*v)/(2.0*x*g) -100);
}
