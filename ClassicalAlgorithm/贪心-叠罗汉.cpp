// ̰�ģ��������������յ�ţ����Сֵ
// ���⣺��Nͷţ��ÿͷţ��������w������s������һ������޺���Ϸ��
// ÿͷţ���ܵķ�������ͷ�ϵ�ţ�������� - �����������(�������Ϊ��)
// �ҵ�һ�����ŷ���ʹ�ó��������յ�ţ���������ֵ��С��
// �ⷨ�����Լٶ��Ѿ��ҵ�������������ô�������������ʱ���ֵһ�������
// �ɴ˿��Եõ�w1 + s1 < w2 + s2����������
#include <stdio.h>
#include <string.h>
#include <algorithm>

const int maxn = 5e4 + 10;
struct Node {
    int w, s;
} COW[maxn];
int N;

int max(int a, int b) { return a > b ? a : b; }

bool cmp(Node a, Node b) {
    return a.w + a.s < b.w + b.s;
}

int main() {
    long long ans, sum_w;

    while (~scanf("%d", &N)) {
        for (int i = 0; i < N; ++i)
            scanf("%d%d", &COW[i].w, &COW[i].s);

        std::sort(COW, COW + N, cmp);

        ans = 0 - COW[0].s;
        sum_w = COW[0].w;
        for (int i = 1; i < N; ++i) {
            ans = max(ans, sum_w - COW[i].s);
            sum_w += COW[i].w;
        }

        printf("%lld\n", ans);
    }
    return 0;
}
