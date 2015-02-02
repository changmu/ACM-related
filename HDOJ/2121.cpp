////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ��ľ
////Run ID: 
////Submit time: 2014-08-08 20:38:52
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2121
////Problem Title: 
////Run result: Accept
////Run time:343MS
////Run memory:380KB
//////////////////System Comment End//////////////////
//not mine
#include<iostream>
#include<climits>
#include<math.h>
using namespace std;
const int N = 1000+10;
const int M = 12000;
struct edge
{
    int u,v;
    int cost;
}e[M];
int pre[N],id[N],visit[N];//id�������Ȧ��
int in[N];//�뻡��С��
int minRoot;
int Directed_MST(int root,int n,int m)//n��ʾ������m��ʾ������root��ʾ��
{
    int u,v,i;
    int ret=0;
    while(true)
    {
        for(i=0;i<n;i++)
            in[i]=INT_MAX;
        for(i=0;i<m;i++)
        {
            u=e[i].u;
            v=e[i].v;
            if(e[i].cost<in[v]&&u!=v)
            {
                pre[v]=u;//�ҳ�ÿ�������С�뻡
                if(u==root)
                    minRoot=i;
                in[v]=e[i].cost;
            }
        }
        for(i=0;i<n;i++)
        {
            if(i==root)
                continue;
            if(in[i]==INT_MAX){//�������и��ڵ����뻡���ͷ���false
                return -1;
            }
        }
        in[root]=0;
        int cnt=0;
        memset(id,-1,sizeof(id));
        memset(visit,-1,sizeof(visit));
        for(i=0;i<n;i++)
        {
            ret+=in[i];//������Ȧ
            v=i;
            while(visit[v]!=i&&id[v]==-1&&v!=root)
            {
                visit[v]=i;
                v=pre[v];
            }
            if(v!=root&&id[v]==-1)
            {
                for(u=pre[v];u!=v;u=pre[u])
                    id[u]=cnt;
                id[v]=cnt++;
            }
        }
        if(cnt==0)
            break;
        for(i=0;i<n;i++)
        {
            if(id[i]==-1)
                id[i]=cnt++;
        }
        for(i=0;i<m;i++)
        {
            v=e[i].v;//�������㣬���±�ǡ�
            e[i].u=id[e[i].u];
            e[i].v=id[e[i].v];
            if(e[i].u!=e[i].v)
                e[i].cost-=in[v];
        }
        n=cnt;
        root=id[root];
    }
    return ret;
}
int main()
{
    int n,m,m1;
    int T,c;
    int r=0;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int i,a,b;
        r=0;
        m1=m;
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            e[i].u=a;
            e[i].v=b;
            e[i].cost=c;
            r+=c;
        }
        r++;
        for(i=0;i<n;i++)
        {
            e[m].u=n;
            e[m].v=i;
            e[m].cost=r;
            m++;
        }
        int ans=Directed_MST(n,n+1,m);
        minRoot-=m1;//��С����Ӧ�ı��Ϊi-m1
        if(ans==-1||ans>=2*r)
            puts("impossible");
        else
            printf("%d %d\n",ans-r,minRoot);
        puts("");
    }
    return 0;
}