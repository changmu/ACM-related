/************************************************************* 
 * �ݳ�ԭ����M��N�ĵ�K�������������ʵ�����
 * �ݳ�ԭ����Ҫ������������ӣ�Ȼ�����Ǹ�������������ȽϿӵ�
 * �ط���Ҫ�ȷֱ����M��N�������ӣ�Ȼ������ȥ�أ������������
 * M��N����С���������ٻᳬʱ������M��N���ǽӽ�1�ڵ���������ô
 * LCM�ʹ�������ˣ�forѭ����Ҫִ�н�һ�ڴΣ���������������
 * ����forѭ�������Ҫִ��2 * sqrt(1��)������Ƚϣ���Ȼ�Ǻ���ʡʱ
 *************************************************************/ 
#include <stdio.h>
#include <string.h>
#include <algorithm>

typedef __int64 LL;
const LL inf = 1LL << 62;
int M, N, K, back, id;
LL Prime[30], Complex[20000];

void get_prime(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (n % i) continue;
        Prime[id++] = i;
        while (n % i == 0)
            n /= i;
    }
    if (n > 1) Prime[id++] = n;
}

void get_divisor_group() {
    int i, j, t;
    id = back = 0;
    
    get_prime(M);
    get_prime(N);

    std::sort(Prime, Prime + id);
    id = std::unique(Prime, Prime + id) - Prime;

    Complex[back++] = -1;
    for (i = 0; i < id; ++i) {
        t = back;
        for (j = 0; j < t; ++j)
            Complex[back++] = Prime[i] * Complex[j] * -1;
    }
}

LL not_coprime(LL num) {
    LL cnt = 0;
    for (int i = 1; i < back; ++i)
        cnt += num / Complex[i];
    return cnt;
}

LL binary_solve() {
    LL L = 1, R = inf, mid, cnt;

    get_divisor_group();

    while (L < R) {     // �ҳ���һ�����ڵ���K����
        mid = L + R >> 1;
        if ((cnt = mid - not_coprime(mid)) < K)
            L = mid + 1;
        else R = mid;
    }

    return L;
}

int main() {
    int T, cas, i;

    scanf("%d", &T);
    for (cas = 1; cas <= T; ++cas) {
        scanf("%d%d%d", &M, &N, &K);
        printf("Case %d: %I64d\n", cas, binary_solve());
    }
    return 0;
}
