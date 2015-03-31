/************************************************************* 
 * ���ƥ��+���鼯��
 * N��Ů����N���к�������Ϸ��
 *  1.��������ֵn, m, f�ֱ��ʾn���к�Ů����m����Ů����ϵ��f��
 *      Ů����ϵ��
 *  2.��������Ů���Ժ��ܸ��飬��Ů���������ѹ�ϵ�����ǹ���
 *      ������ʶ���к���
 * �ʣ�
 *  ����Ϸ�������������? (ÿһ�������˶��ý��)
 *************************************************************/ 
#include <stdio.h>
#include <string.h>

const int maxn = 110;
bool G[maxn][maxn];
int pre[maxn], N, M, F;
int vis[maxn], B[maxn];

int uFind(int k) {
    return pre[k] ? pre[k] = uFind(pre[k]) : k;
}

void unite(int x, int y) {
    x = uFind(x);
    y = uFind(y);

    if (x == y) return;
    for (int i = 1; i <= N; ++i)    // ���Լ����˼ʹ�ϵ���ݸ�����
        if (G[x][i]) G[y][i] = true;

    pre[x] = y;
}

int find_match(int x) {
    for (int i = 1; i <= N; ++i) {
        if (G[x][i] && !vis[i]) {
            vis[i] = true;
            if (!B[i] || find_match(B[i])) {
                B[i] = x;
                return 1;
            }
        }
    }
    return 0;
}

int max_match() {
    int cnt = 0;
    for (int i = 1; i <= N; ++i) {
        memset(vis, 0, sizeof(vis));
        cnt += find_match(i);
    }

    return cnt;
}

void divorce() {
    for (int i = 1; i <= N; ++i)
        G[B[i]][i] = false;
}

int max_match_round() {
    int cnt = 0;
    while (true) {
        memset(B, 0, sizeof(B));

        if (max_match() == N) ++cnt;
        else break;

        divorce();
    }

    return cnt;
}

void copy_relation() {
    int ori;
    for (int i = 1; i <= N; ++i) {
        ori = uFind(i);
        memcpy(G[i], G[ori], sizeof(bool) * (N + 1));
    }
}

int main() {
    int T, i, x, y;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &N, &M, &F);

        memset(G, 0, sizeof(G));
        memset(pre, 0, sizeof(pre));

        while (M--) {
            scanf("%d%d", &x, &y);
            G[x][y] = true;
        }

        while (F--) {
            scanf("%d%d", &x, &y);
            unite(x, y);
        }

        copy_relation();

        printf("%d\n", max_match_round());
    }
    return 0;
}
