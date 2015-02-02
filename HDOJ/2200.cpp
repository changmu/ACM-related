////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ��ľ
////Run ID: 
////Submit time: 2014-05-31 21:00:52
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2200
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:200KB
//////////////////System Comment End//////////////////
//��n������ѡm���ˣ������飬�൱������m����֮���壬����(m-1)�����
#include <stdio.h>

__int64 cal(int n, int m){
	if(m > n / 2) m = n - m;
	__int64 ans = 1;
	for(int i = 0; i < m; ++i)
		ans = ans * (n - i) / (i + 1); //������д�� *=
	return ans;
}

int main(){
	int n;
	__int64 ans;
	while(scanf("%d", &n) == 1){
		ans = 0;
		for(int i = 2; i <= n; ++i)
			ans += (i - 1) * cal(n, i);
		printf("%I64d\n", ans);
	}
	return 0;
}