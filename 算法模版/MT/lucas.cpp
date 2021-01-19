#include <cstdio>

#define re register
#define rep(i, a, b) for(re int i = (a); i <= (b); ++ i)

typedef long long ll;

void exgcd(ll a, ll b, ll &x, ll &y) {
    if(!b) { x = 1, y = 0; return ; }
    exgcd(b, a % b, y, x); 
    y -= x * (a / b); return ;
}

static inline ll inv(ll num, ll p) {
    ll x, y; exgcd(num, p, x, y);
    x = ((x % p) + p) % p;
    return x;
}

static inline ll C(ll n, ll m, ll p) {
    if(m > n) return 0; ll ans = 1;
    rep(i, m + 1, n) ans = (ans * i) % p;
    rep(i, 2, n - m) ans = (ans * inv(i, p)) % p;
    return ans;
}

ll lucas(ll n, ll m, ll p) {
    return m ? lucas(n / p, m / p, p) * C(n % p, m % p, p) % p : 1;
}

int main() {
    re int T; scanf("%d", &T); while(T --) {
        re int n, m, p; scanf("%d%d%d", &n, &m, &p);
        printf("%lld\n", lucas(n + m, m, p));
    } return 0;
}