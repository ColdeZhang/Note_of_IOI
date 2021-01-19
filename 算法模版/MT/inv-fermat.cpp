#include <cstdio>

typedef long long ll;

ll n, p;

static inline ll qpow(ll a, ll b) {
    ll res = 1; while(b) {
        if(b & 1) res = (res * a) % p;
        a = (a * a) % p, b >>= 1;
    } return res;
}

int main() {
    scanf("%lld%lld", &n, &p);
    printf("%lld\n", qpow(n, p - 2));
    return 0;
}