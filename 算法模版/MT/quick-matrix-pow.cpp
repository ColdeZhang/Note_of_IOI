#include <cstdio>
#include <cstring>

#define re register
#define rep(i, a, b) for(re int i = (a); i <= (b); ++ i)
#define Rep(i, a, b) for(re int i = (a); i <  (b); ++ i)

typedef long long ll;

const int mod = 1e9 + 7;

static inline void up(ll &x, ll y) {
    x = (x + y) % mod;
}

const int n = 100 + 5;

struct mat {
    ll a[n][n];
    friend mat operator * (const mat x, const mat y) {
        mat z; memset(z.a, 0, sizeof(z.a));
        Rep(i, 0, n) Rep(j, 0, n) Rep(k, 0, n)
            up(z.a[i][j], x.a[i][k] * y.a[k][j]);
        return z;
    }
};

mat qpow(mat x, ll b) {
    mat res; Rep(i, 0, n) Rep(j, 0, n) res.a[i][j] = 0;
    Rep(i, 0, n) res.a[i][i] = 1; while(b) {
        if(b & 1) res = res * x; x = x * x, b >>= 1;
    } return res;
}

int main() {
    ll N, K; scanf("%lld%lld", &N, &K); mat base;
    Rep(i, 0, N) Rep(j, 0, N) scanf("%lld", &base.a[i][j]);
    mat ans = qpow(base, K); Rep(i, 0, N) {
        Rep(j, 0, N) printf("%lld ", ans.a[i][j]);
        putchar('\n');
    } return 0;
}