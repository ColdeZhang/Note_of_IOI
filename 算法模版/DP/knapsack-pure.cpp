#include <cstdio>

#define re register
#define rep(i, a, b) for(re int i = (a); i <= (b); ++ i)
#define Rep(i, a, b) for(re int i = (a); i <  (b); ++ i)
#define drep(i, a, b) for(re int i = (a); i >= (b); -- i)

const int C = 1e6 + 5;

int n, V, f[C];

int main() {
    scanf("%d%d", &n, &V);
    rep(i, 1, n) {
        re int w, v;
        scanf("%d%d", &w, &v);
        drep(j, V, v)
            f[j] = f[j - v] + w;
    } printf("%d\n", f[V]);
    return 0;
}