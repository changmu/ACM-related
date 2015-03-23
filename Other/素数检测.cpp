/************************************************************* 
 * ԭ��: ���n��������������Ȼ��һ��С�ڵ���sqrt(n)������
 *************************************************************/ 
#include <stdio.h>
#include <string.h>
#include <math.h>

bool isPrime(int n) {
    if (n < 2) return false;
    int k = (int) sqrt(n);
    for (int i = 2; i <= k; ++i)
        if (n % i == 0) return false;
    return true;
}

int main() {
    printf("%d: %s\n", 1234567, isPrime(1234567) ? "Yes" : "No");
    return 0;
}
