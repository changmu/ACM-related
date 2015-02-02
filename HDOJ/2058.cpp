////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ��ľ
////Run ID: 
////Submit time: 2014-01-29 23:31:59
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2058
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:228KB
//////////////////System Comment End//////////////////
/*��һ�������еĺ͵���M����ô��������п��Կ���a+1, a+2, ... , a+d ��ʱ��
d��Ϊ������еĳ���,��ʼ���־���a+1����������еĺͼ�M=a*d + (1 + d) * d /2;
�ó�d*d<2 * m���Ӷ�����ö��d,�����a*/
#include <stdio.h>
#include <math.h>
int main(){
	int n, m, d, x;
	while(scanf("%d%d", &n, &m), n || m){
		d = (int)sqrt(2.0 * m);
		while(d > 0){
			x = m - (1 + d) * d / 2;
			if(x % d == 0) printf("[%d,%d]\n", x / d + 1, x / d + d);
			--d;
		}
		printf("\n");
	}
	return 0;
}