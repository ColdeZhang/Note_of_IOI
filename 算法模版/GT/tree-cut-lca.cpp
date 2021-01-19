#include <cstdio>

#define re register
#define rep(i, a, b) for(re int i = (a); i <= (b); ++ i)
#define Rep(i, a, b) for(re int i = (a); i <  (b); ++ i)
#define fwd(i, u) for(re int i = head[(u)]; i; i = e[i].nxt)

const int N = 1e6 + 5;
const int M = 2e6 + 5;

int n, m, s, head[N], cnt, dep[N], top[N], fa[N], sz[N], son[N];

static inline void swap(int &a, int &b) {
    int t = a; a = b, b = t; return ;
}

struct EDGE {
    int to, nxt; 
} e[M];

static inline void add(int u, int v){
    e[++ cnt].to = v, e[cnt].nxt = head[u], head[u] = cnt;
    return ;
}

void dfs1(int u, int f, int depth) {
    fa[u] = f, dep[u] = depth;
    sz[u] = 1; fwd(i, u) {
        re int v = e[i].to;
        if(v == f) continue;
        dfs1(v, u, depth + 1);
        sz[u] += sz[v];
        if(sz[v] > sz[son[u]]) 
            son[u] = v;
    }
    return ;
}

void dfs2(int u, int topf) {
    top[u] = topf;
    if(son[u]) dfs2(son[u], topf);
    fwd(i, u) {
        re int v =  e[i].to;
        if(v == fa[u] || v == son[u]) 
            continue;
        dfs2(v, v);
    }
    return ;
}

int query(int u, int v) {
    while(top[u] != top[v]) {
        if(dep[top[u]] < dep[top[v]]) 
            swap(u, v);
        u = fa[top[u]];
    } return dep[u] < dep[v] ? u : v;
}

int main() {
    scanf("%d%d%d", &n, &m, &s); re int u, v;
    Rep(i, 1, n) scanf("%d%d", &u, &v), add(u, v), add(v, u);
    dfs1(s, 0, 1), dfs2(s, s); while(m --) {
        scanf("%d%d", &u, &v); printf("%d\n", query(u, v));
    } return 0;
}