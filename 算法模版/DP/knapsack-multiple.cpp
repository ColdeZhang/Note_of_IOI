#include <cstdio>
#include <cstring>

#define re register
#define rep(i, a, b) for(re int i = (a); i <= (b); ++ i)
#define Rep(i, a, b) for(re int i = (a); i <  (b); ++ i)

typedef long long ll;

const int N = 1e3 + 6;
const int M = 2e4 + 6;

int n, m, f[M], g[M], q[M];

static inline void upmax(int &a, int b) {
    if(a < b) a = b; return ;
}

int main() {
    scanf("%d%d", &n, &m); Rep(i, 0, n) {
        re int v, w, s; scanf("%d%d%d", &v, &w, &s);
        memcpy(g, f, sizeof(f)); Rep(j, 0, v) {
            re int h = 0, t = -1;
            for(re int k = j; k <= m; k += v) {
                if (h <= t && q[h] < k - s * v) ++ h;
                if (h <= t) upmax(f[k], g[q[h]] + (k - q[h]) / v * w);
                while (h <= t && g[q[t]] - (q[t] - j) / v * w <= g[k] - (k - j) / v * w) -- t;
                q[++ t] = k;
            }
        }
    } printf("%d\n", f[m]); return 0;   
}