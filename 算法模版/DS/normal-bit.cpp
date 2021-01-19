#include <cstdio>

#define re register
#define rep(i, a, b) for(re int i = (a); i <= (b); ++ i)
#define Rep(i, a, b) for(re int i = (a); i <  (b); ++ i)

typedef long long ll;

const int N = 5e5 + 5;

int n, m; ll c[N];

static inline void modify(int pos, ll val) {
    while(pos < N) {
        c[pos] += val;
        pos += pos & -pos;
    } return ;
}

static inline ll query(int pos) {
    ll res = 0; while(pos) {
        res += c[pos];
        pos -= pos & -pos;
    } return res;
}

int main() {
    scanf("%d%d", &n, &m); re ll x;
    rep(i, 1, n) scanf("%lld", &x), modify(i, x);
    re int opt, l, r; re ll val; while(m --) {
        scanf("%d", &opt); if(opt == 1) 
            scanf("%d%lld", &l, &val),
            modify(l, val);
        else scanf("%d%d", &l, &r),
            printf("%lld\n", query(r) - query(l - 1));
    } return 0;
}