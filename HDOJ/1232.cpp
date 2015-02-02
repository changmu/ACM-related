////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ��ľ
////Run ID: 
////Submit time: 2014-04-29 10:49:15
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1232
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:212KB
//////////////////System Comment End//////////////////
//���鼯
#include <stdio.h>
int pre[1002];

int find(int k){
	int i = k;
	while(i != pre[i]) //�ҵ���ͼ�ġ�Ԫ˧��
		i = pre[i]; 
	int j = k, t; //ѹ��·�����ѱ�������ÿ������ϼ�ֱ�ӻ��ɡ�Ԫ˧��
	while(j != i){
		t = pre[j];
		pre[j] = i;
		j = t;
	}
	return i; //"Ԫ˧"
}

int main(){
	int n, m, a, b, sum, x, y;
	while(scanf("%d", &n), n){
		scanf("%d", &m);
		sum = n - 1;
		for(int i = 1; i <= n; ++i) //ÿ�����ж��Ƕ�����
			pre[i] = i;
		while(m--){
			scanf("%d%d", &a, &b);
			x = find(a);
			y = find(b);
			if(x != y){ //��������㲻��ͬһ��ͼ����Ļ��Ͱ�������ͼ��������
				pre[x] = y;
				--sum;
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}