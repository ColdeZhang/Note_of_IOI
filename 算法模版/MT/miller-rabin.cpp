#include <cstdio>
#include <cassert>
#define re register
#define Rep(i, a, b) for(re int i = (a); i < (b); ++ i)
typedef long long ll;
const int p[] = { 2, 3, 5, 7, 17, 19, 61 };
ll mul(ll a, ll b, ll p) {
    ll w = (long double)a * b / p + 0.5, r = a * b - w * p;
    assert((__int128)w * p + r == (__int128)a * b);
    return r < 0 ? r + p : r;
}
ll qpow(ll a, ll b, ll p) {
    ll res = 1; while(b) {
        if (b & 1) res = mul(res, a, p);
        a = mul(a, a, p), b >>= 1;
    } return res;
}
bool mr(ll n) {
    if (n == 1) return 0;
    Rep(i, 0, 7) if (!(n % p[i])) return n == p[i];
    ll r = n - 1, x, y; int t = 0;
    while (!(r & 1)) r >>= 1, ++t;
    Rep(i, 2, 7) {
        x = qpow(p[i], r, n);
        for (re int j = 0; j < t && x > 1; ++j) {
            y = mul(x, x, n);
            if (y == 1 && x != n - 1)
                return 0;
            x = y;
        } if (x != 1) return 0;
    } return 1;
}
int main() {
    ll n; while (~scanf("%lld", &n)) 
        puts(mr(n) ? "Y" : "N");
    return 0;
}