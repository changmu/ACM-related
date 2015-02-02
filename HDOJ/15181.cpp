////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ��ľ
////Run ID: 
////Submit time: 2014-11-04 11:56:45
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1518
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <functional>
#include <algorithm>

#define maxn 22

int L[maxn], n, tar, times; // tar�Ǳ߳���
bool vis[maxn], ok;

bool DFS(int k, int leftLen) {
    if(!leftLen) { // ��ǰ��������
        if(++times == 4) return true; // 4����ȫ����ϳ���
        for(int i = 1; i < n; ++i) { // ��ʼ�����һ����
            if(!vis[i]) { // ��һ��δѡ��Ĺ��ӱ�ѡ�������޷���������ô����ʧ��
                vis[i] = 1;
                if(DFS(i + 1, tar - L[i])) 
                    return true; // �������
                else { // ʧ�������
                    --times; // ֮ǰ����Ϸ���ʧ�ܣ������ֳ����������
                    vis[i] = 0;
                    return false;
                }
            }
        }
    }

    int i;
    for(i = k; i < n; ++i) {
        if(!vis[i] && L[i] <= leftLen) {
            vis[i] = 1;
            if(L[i-1] == L[i] && !vis[i-1]) { // ��Ҫ��֦��ԭ����
                // ��ǰһ������ǰ��������ͬ��δѡ��˵��ǰһ����
                //���䷽��ʧ�ܣ���ô��ǰ����ѡ��Ļ�Ҳ�ض�ʧ�ܣ�����cut��
                vis[i] = 0;
                continue;
            }
            if(DFS(i+1, leftLen - L[i]))
                return true;
            vis[i] = 0;
        }
    }

    return false;
}

int main() {
    int t, i;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        tar = 0;
        for(i = 0; i < n; ++i) {
            scanf("%d", &L[i]);
            vis[i] = 0; tar += L[i];
        }

        if(tar % 4) { // cut1, you know why
            printf("no\n");
            continue;
        }
        tar /= 4; // ��Ҫ��ϵ�Ŀ�곤��

        std::sort(L, L + n, std::greater<int>()); // ����
        if(L[0] > tar) { // cut2, you know why
            printf("no\n");
            continue;
        }

        times = 0; vis[0] = 1; // cut3, ��һ����ѡ������Ҫ�ļ�֦��
        //��Ϊ�����һ����ʼ�޷������ô����Ӻ��濪ʼ����ϳ�
        //Ŀ�곤��Ҳ��������ϳ�������
        DFS(1, tar - L[0]); // ���ڵ�һ����ѡ����ô�ӵڶ�����ʼ������
        //�ڶ�������Ϊʣ����Ҫ��ϵĳ���

        printf(times == 4 ? "yes\n" : "no\n"); // 4����ȫ����ϳɹ���yes
    }
    return 0;
}