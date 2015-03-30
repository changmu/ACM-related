/************************************************************* 
 * ��N����ľ���������������ɸ�����ΪtarLen��ľ���и���ɣ���tarLen��
 * ��Сֵ(��ֵ��Ϊ����).
 * �ص��֦��
 * 1������װ��tarlen����ѡ�дӸߵ��͵ĵ�һ����
 * 2������ǰ���ѷ��ʻ��߱�ʣ����Ҫ���ȳ����߸�ǰһ��δ���ʵĳ���
 *  һ������continue
 *************************************************************/ 
#include <stdio.h>
#include <string.h>

const int maxn = 70;
int sticks[maxn], N, tarLen;
bool used[maxn];

void quickSort(int *A, int L, int R) {
    if (R - L < 1) return;

    int key = A[L], u = L, v = R;
    while (L < R) {
        while (L < R && A[R] <= key) --R;       // increase order
        A[L] = A[R];
        while (L < R && A[L] >= key) ++L;
        A[R] = A[L];
    }
    A[L] = key;

    quickSort(A, u, L - 1);
    quickSort(A, L + 1, v);
}

bool catSticks(int startIndex, int needtarLen, int needSumLen) {
    if (needtarLen == 0) {                          // assemble one
        if (needSumLen == 0) return true;           // all sticks is assembled

        int i;
        for (i = 1; i < startIndex; ++i)
            if (!used[i]) break;

        used[i] = true;
        if (catSticks(i + 1, tarLen - sticks[i], needSumLen - sticks[i]))
            return true;
        else {
            used[i] = false;
            return false;
        }
    }
    for (int i = startIndex; i < N; ++i) {
        if (used[i] || sticks[i] > needtarLen || sticks[i] == sticks[i-1] && !used[i-1]) // cut
            continue;

        used[i] = true;
        if (catSticks(i + 1, needtarLen - sticks[i], needSumLen - sticks[i]))
            return true;
        else {
            used[i] = false;
        }
    }

    return false;
}

int main() {
    int i, sumtarLen, tarNum, tmp;
    while (scanf("%d", &N), N) {
        for (i = sumtarLen = 0; i < N; ++i) {
            scanf("%d", &sticks[i]);
            sumtarLen += sticks[i];
            used[i] = false;
        }

        quickSort(sticks, 0, N - 1);

        used[0] = true;     // the first one must be chosen
        for (tarLen = sticks[0]; tarLen < sumtarLen; ++tarLen) {
            if (sumtarLen % tarLen) continue;

            if (catSticks(1, tarLen - sticks[0], sumtarLen - sticks[0]))
                break;
        }

        printf("%d\n", tarLen);
    }
    return 0;
}
