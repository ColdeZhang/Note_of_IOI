#include <cstdio>
#define re register
#define rep(i, a, b) for(re int i = (a); i <= (b); ++ i)
const int N = 5e6 + 5;
typedef long long ll;
const ll mod = 998244352;
ll a[N];

static inline ll qpow(ll a, ll b) {
    ll res = 1; while(b) {
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod, b >>= 1;
    } return res;
}

int main() {
    ll x, n; scanf("%lld%lld", &x, &n);
    rep(i, 1, n) 
        scanf("%lld", &a[i]), 
        printf("%lld ", qpow(x, a[i]));
    puts(""); return 0;
}