#include <cstdio>
#include <algorithm>

#define re register
#define rep(i, a, b) for(re int i = (a); i <= (b); ++ i)
#define Rep(i, a, b) for(re int i = (a); i <  (b); ++ i)

typedef long long ll;

const int M = 1e6 + 5;
const int N = 2e5 + 5;

struct EDGE { int u, v, w; }e[M];

static inline bool cmp(EDGE A, EDGE B) {
    return A.w < B.w;
}

static inline void swap(int &a, int &b) {
    re int t = a; a = b, b = t; return ;
}

int n, m, fa[N], sz[N]; ll ans = 0;

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

bool merge(int x, int y) {
    re int fx = find(x), fy = find(y);
    if(fx == fy) return false;
    if(sz[fx] > sz[fy]) swap(fx, fy);
    fa[fx] = fy, sz[fy] += sz[fx]; return true;
}

int main() {
    scanf("%d%d", &n, &m); 
    rep(i, 1, m) scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w); 
    rep(i, 1, n) sz[fa[i] = i] = 1; std::sort(e + 1, e + m + 1, cmp);
    re int cnt = 0; rep(i, 1, m) {
        if(!merge(e[i].u, e[i].v)) 
            continue;
        ++ cnt; ans += e[i].w;
        if(cnt == n - 1) break;
    } if(cnt != n - 1) puts("orz"); 
    else printf("%lld\n", ans); return 0;
}