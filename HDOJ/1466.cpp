////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ��ľ
////Run ID: 
////Submit time: 2014-06-02 15:19:14
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1466
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
/*
**n��ֱ��ʱ���ܽ�����Ϊarr[n]���ֳ����飬ѡ����һ��A��Ϊ������Aƽ�еĶ���A�飬�����ķŵ�B�飬
**�򽻵���Ϊa * b + arr[b];
*/
#include <stdio.h>
bool arr[22][200];
//��Ƿ�ĳ�̶ֳ��Ͼ߱����������
int main(){
	int n, a, b;
	arr[0][0] = arr[1][0] = 1;
	for(int i = 2; i < 21; ++i){
		arr[i][0] = 1; //0һ���У�������
		for(int j = 1; j < i; ++j){
			a = j; b = i - j;
			for(int k = 0; k <= (b-1) * b / 2; ++k)
				if(arr[b][k]) arr[i][a * b + k] = 1;				
		}
	}
	while(scanf("%d", &n) == 1){
		for(int i = 0; i <= (n-1) * n / 2; ++i)
			if(i == 0) printf("%d", i);
			else if(arr[n][i]) printf(" %d", i);
		printf("\n");
	}
	return 0;
}