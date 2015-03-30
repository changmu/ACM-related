/************************************************************* 
 * ���鼯��
 * ��N���ˣ����Ƿֱ�����������֯A/B�� ������M����Ϣ��
 * D(x, y) ��ʾx��y���ڲ�ͬ����֯�� A(x, y) �ش�x��y�Ƿ�����
 * ͬһ����֯.
 *************************************************************/ 
#include <stdio.h>
#include <string.h>

const int maxn = 100005;
int pre[maxn<<1];
int N, M;

int uFind(int x) {
    return pre[x] ? pre[x] = uFind(pre[x]) : x;
}

bool same(int x, int y) {
    return uFind(x) == uFind(y);
}

bool unite(int x, int y) {
    x = uFind(x);
    y = uFind(y);
    if (x == y) return false;
    pre[x] = y; return true;
}

int main() {
    int T, x, y;
    char ch[2];

    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &N, &M);

        memset(pre, 0, sizeof(pre));

        while (M--) {
            scanf("%s%d%d", ch, &x, &y);
            if (*ch == 'D') {
                unite(x, y + N);        // ͬʱά�����û�����������
                unite(x + N, y);
            } else {
                if (same(x, y))
                    puts("In the same gang.");
                else if (same(x, y + N))
                    puts("In different gangs.");
                else
                    puts("Not sure yet.");
            }
        }
    }
    return 0;
}
