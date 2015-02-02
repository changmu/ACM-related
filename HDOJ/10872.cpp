////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ��ľ
////Run ID: 
////Submit time: 2014-08-27 20:03:43
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1087
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:236KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define maxn 1002
//dp[i]��ʾ��i���������е����ֵ
int arr[maxn], dp[maxn];

int max(int a, int b){
    return a > b ? a : b;
}

int main()
{
    int n, i, j, ans;
    while(scanf("%d", &n), n){
        for(i = 0; i < n; ++i)
            scanf("%d", arr + i);
        ans = dp[0] = max(0, arr[0]);
        for(i = 1; i < n; ++i){
            dp[i] = max(0, arr[i]); //attention
            for(j = 0; j < i; ++j)
                if(arr[j] < arr[i]) dp[i] = max(dp[i], dp[j] + arr[i]);            
            if(dp[i] > ans) ans = dp[i]; 
        }
        printf("%d\n", ans);
    }
    return 0;
}