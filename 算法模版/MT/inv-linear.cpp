#include <cstdio>

#define rep(i, a, b) for(int i = (a); i <= (b); ++ i)

typedef long long ll;

const int N = 1e7 + 9;

ll n, p, inv[N];

int main() {
    inv[1] = 1; scanf("%lld%lld", &n, &p);
    puts("1"); rep(i, 2, n) {
        inv[i] = ((p - p / i) * inv[p % i]) % p;
        printf("%lld\n", inv[i]);
    } return 0;
}