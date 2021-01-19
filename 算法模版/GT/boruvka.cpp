#include <cstdio>

#define re register
#define rep(i, a, b) for(re int i = (a); i <= (b); ++ i)
#define fwd(i, u) for(re int i = head[(u)]; i; i = e[i].nxt)
typedef long long ll;

const int N = 5e3 + 5;
const int M = 4e5 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

typedef long long ll;

int n, m, fa[N], sz[N], head[N], cnt;

struct EDGE {
    int to, nxt;
    ll w;
} e[M];

static inline void add(int u, int v, ll w) {
    e[++ cnt].to = v, 
    e[cnt].nxt = head[u],
    e[cnt].w = w,
    head[u] = cnt;
    return ;
}

bool vis[N];

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

static inline void swap(int &a, int &b) {
    re int t = a; a = b, b = t; return; 
}

static inline void merge(int x, int y) {
    re int fx = find(x), fy = find(y);
    if (fx == fy) return ;
    if (sz[fx] > sz[fy]) swap(fx, fy);
    fa[fx] = fy; return ;
}

static inline void init() {
    rep(i, 1, n) vis[i] = 0; 
    return ;
}

int main() {
    scanf("%d%d", &n, &m);
    rep(i, 1, n) fa[i] = i, sz[i] = 1;
    re int u, v; re ll w, ans = 0;
    while (m --) {
        scanf("%d%d%lld", &u, &v, &w);
        add(u, v, w), add(v, u, w);
    } e[0].w = INF; re bool mk = 0; while (1) {
        init(); rep(i, 1, n) {
            re int f = find(i); if (vis[f]) continue;
            re int res = 0; vis[f] = 1; 
            rep(j, 1, n) {
                if (find(j) != f) 
                    continue;
                fwd(k, j) {
                    re int v = e[k].to;
                    if (find(v) == f) 
                        continue;
                    if (e[res].w > e[k].w)
                       res = k;
                }
            }
            if (!res) { mk = 1; break; }
            ans += e[res].w, 
            merge(i, e[res].to);
        } if (mk) break;
    } if (!mk) puts("orz");
    else printf("%lld\n", ans);
    return 0;
}