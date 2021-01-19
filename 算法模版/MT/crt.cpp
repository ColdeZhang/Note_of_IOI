#include <cstdio>

#define re register
#define rep(i, a, b) for(re int i = (a); i <= (b); ++ i)
#define Rep(i, a, b) for(re int i = (a); i <  (b); ++ i)

typedef long long ll;

const int N = 10 + 5;

ll n, ans, a[N], b[N], c[N], inv[N], M, m[N];

void exgcd(ll a, ll b, ll &x, ll &y) {
    if(!b) { x = 1, y = 0; return ; }
    exgcd(b, a % b, y, x);
    y -= x * (a / b); return ;
}

static inline ll Inv(ll num, ll p) {
    ll x, y; exgcd(num, p, x, y);
    x = ((x % p) + p) % p;
    return x;
}

int main() {
    scanf("%lld", &n); M = 1;
    rep(i, 1, n) scanf("%lld%lld", &a[i], &b[i]), M = M * a[i];
    rep(i, 1, n) m[i] = M / a[i], inv[i] = Inv(m[i], a[i]);
    rep(i, 1, n) c[i] = inv[i] * m[i], ans = (ans + c[i] * b[i]) % M;
    ans = ((ans % M) + M) % M, printf("%lld\n", ans);
    return 0;
}