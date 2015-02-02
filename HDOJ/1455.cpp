////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ��ľ
////Run ID: 
////Submit time: 2014-08-06 09:49:06
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1455
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:220KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <algorithm>
using std::sort;
int stick[66], n, sum, len, ok, temp;
bool vis[66];

bool cmp(int a, int b){
	return a > b;
}

bool DFS(int k, int left, int total){ //��k��ľ����ʣ�µ�ƥ�䳤�ȣ�ʣ�µ��ܳ���
	if(left == 0){ //�Ѿ�ƥ����һ��
		total -= len;
		if(!total) return true;
		
		int i = 1;
		while(vis[i]) ++i;
		vis[i] = 1; //cut, �ҵ��ĵ�һ���϶�Ҫ�ã���ʱ�͸����õ���������û�TLE
		if(DFS(i + 1, len - stick[i], total)) return true;
		vis[i] = 0;
		return false;
	}
	
	for(int i = k; i < n; ++i){
		if(i > 0 && stick[i] == stick[i-1] && !vis[i-1]) //cut,��ǰһ����ͬ���ȵ�ƥ��ʧЧ����ǰ����Ҫ������ȥ
			continue;
		if(!vis[i] && left >= stick[i]){			
			vis[i] = 1; left -= stick[i]; 
			if(DFS(i + 1, left, total)) return true;
			vis[i] = 0; 
			if(!left) return false; //cut
			left += stick[i];
		}
	}
	return false;
}

int main(){
	while(scanf("%d", &n), n){
		sum = ok = 0;
		for(int i = 0; i < n; ++i){
			scanf("%d", stick + i);
			vis[i] = 0; sum += stick[i];
		}
		sort(stick, stick + n, cmp);
		temp = sum / 2; len = stick[0]; //��֦1
		vis[0] = 1;
		while(len <= temp){
			if(sum % len == 0 && DFS(1, len - stick[0], sum)){ //��֦2
				printf("%d\n", len); 
				ok = 1; break;
			}
			++len;
		}
		if(!ok) printf("%d\n", sum);
	}
	return 0;
}