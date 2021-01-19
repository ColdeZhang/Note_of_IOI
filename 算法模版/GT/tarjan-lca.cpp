#include <cstdio>

#define re register
#define rep(i, a, b) for(re int i = (a); i <= (b); ++ i)
#define Rep(i, a, b) for(re int i = (a); i <  (b); ++ i)
#define fwd(i, u) for(re int i = head[(u)]; i; i = e[i].nxt)
#define qfwd(i, u) for(re int i = qhead[(u)]; i; i = q[i].nxt)

const int N = 1e6 + 5;
const int M = 2e6 + 5;

int n, m, s, head[N], cnt, lca[M];

int qhead[N], qcnt;

struct EDGE { int to, nxt; } e[M], q[M];
static inline void add(int u, int v) {
    e[++ cnt].to = v, e[cnt].nxt = head[u], head[u] = cnt;
    return ;
}
static inline void qadd(int u, int v) {
    q[++ qcnt].to = v, q[qcnt].nxt = qhead[u], qhead[u] = qcnt;
    return ;
}

bool vis[N] ;int fa[N];

int find(int x) {
    return fa[x] == x? x : fa[x] = find(fa[x]);
}

void tar(int u) {
    re int v; vis[u] = 1; fwd(i, u) {
        v = e[i].to; if(vis[v]) continue;
        tar(v), fa[v] = u;
    } qfwd(i, u) {
        v = q[i].to;
        if(vis[v]) {
            lca[i] = find(v);
            if(i & 1) lca[i + 1] = lca[i];
            else lca[i - 1] = lca[i];
        }
    } return ;
}
int main() {
    scanf("%d%d%d", &n, &m, &s);
    re int u, v; Rep(i, 1, n) {
        scanf("%d%d",&u,&v);
        add(u, v), add(v, u),
        fa[i] = i;
    } fa[n] = n; rep(i, 1, m) {
        scanf("%d%d",&u,&v);
        qadd(u, v),qadd(v, u);
    } tar(s); rep(i, 1, m)
        printf("%d\n", lca[i << 1]);
    return 0;
}