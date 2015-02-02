////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ��ľ
////Run ID: 
////Submit time: 2014-08-09 09:31:17
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4009
////Problem Title: 
////Run result: Accept
////Run time:937MS
////Run memory:5736KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#define maxn 1002
#define maxm 1000002

int X, Y, Z;
struct Node{
	int x, y, z;
} ver[maxn];
struct Node2{
	int u, v, cost;
} E[maxm];
int in[maxn], hash[maxn], vis[maxn], pre[maxn];

int calDist(Node a, Node b){
	return abs(a.x - b.x) + abs(a.y - b.y) + abs(a.z - b.z);
}

__int64 ZL_MST(int root, int nv, int ne)
{
	__int64 ans = 0;
	int u, v, i, cnt;
	while(true){
		//0.��ʼ��
		for(i = 0; i < nv; ++i) in[i] = INT_MAX;
		//1.����С��߼�
		for(i = 0; i < ne; ++i){
			u = E[i].u; v = E[i].v;
			if(E[i].cost < in[v] && u != v){
				in[v] = E[i].cost; pre[v] = u;
			}
		}
		//2.�ҷǸ�����ߵ�(��)����Ϊ�ض��н�
		//3.�һ�����Ȩ�����±��
		memset(hash, -1, sizeof(hash));
		memset(vis, -1, sizeof(vis));
		cnt = in[root] = 0;
		for(i = 0; i < nv; ++i){
			ans += in[i]; v = i;
			while(vis[v] != i && v != root && hash[v] == -1){
				vis[v] = i; v = pre[v];
			}
			if(v != root && hash[v] == -1){
				for(u = pre[v]; u != v; u = pre[u])
					hash[u] = cnt;
				hash[v] = cnt++;
			}
		}
		if(cnt == 0) return ans; //�޻����㷨���
		for(i = 0; i < nv; ++i) 
			if(hash[i] == -1) hash[i] = cnt++;
		//4.���㣬����ÿһ���ߣ����¹�ͼ
		for(i = 0; i < ne; ++i){
			v = E[i].v;
			E[i].u = hash[E[i].u];
			E[i].v = hash[E[i].v];
			if(E[i].u != E[i].v) E[i].cost -= in[v];
		}
		//����������
		nv = cnt; root = hash[root];
	}
	return ans;
}

int main()
{
	int n, i, a, b, id;
	while(scanf("%d%d%d%d", &n, &X, &Y, &Z) != EOF && (n||X||Y||Z)){
		for(i = 0; i < n; ++i)
			scanf("%d%d%d", &ver[i].x, &ver[i].y, &ver[i].z);
		for(i = id = 0; i < n; ++i){
			scanf("%d", &a);
			while(a--){
				scanf("%d", &b);
				E[id].cost = calDist(ver[i], ver[--b]) * Y;
				if(ver[b].z > ver[i].z) E[id].cost += Z;
				E[id].u = i; E[id++].v = b;
			}
		}
		for(i = 0; i < n; ++i){
			E[id].u = n; E[id].v = i;
			E[id++].cost = ver[i].z * X;
		}
		printf("%I64d\n", ZL_MST(n, n + 1, id));
	}
	return 0;
}
