#include <cstdio>

int gcd(int a, int b) {
    return !b ? a : gcd(b, a % b);
}

int main() {
    int n, m; scanf("%d%d", &n, &m);
    int GCD = gcd(n, m), LCM = n * m / GCD;
    printf("%d %d\n", GCD, LCM);
    return 0;
}