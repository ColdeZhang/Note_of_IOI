#include <cstdio>
#include <cmath>

#define re register
#define rep(i, a, b) for(re int i = (a); i <= (b); ++ i)

const int N = 1e6 + 5;
const int BIT = 20 + 5;

int f[N][BIT];

static inline int max(int a, int b){
    return a > b ? a : b;
}

inline int query(int l, int r) {
    int k = log2(r - l + 1);
    return max(f[l][k], f[r - (1 << k) + 1][k]);
}

int main() {
    re int n, m; scanf("%d %d", &n, &m);
    rep(i, 1, n) scanf("%d", &f[i][0]);
    re int lim = log2(n); rep(j, 1, lim)
        for (re int i = 1; i + (1 << j) - 1 <= n; ++ i) 
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
    while(m --) {
        re int l, r; scanf("%d %d", &l, &r);
        printf("%d\n", query(l, r));
    } return 0;
}