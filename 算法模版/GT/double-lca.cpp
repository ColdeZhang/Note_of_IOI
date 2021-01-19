#include<cstdio>
const int N = 5e5 + 5;
const int M = (N << 1);
const int LOG = 20;

#define re register
#define fwd(i, u) for(re int i = head[(u)]; i; i = e[i].nxt)
#define Rep(i, a, b) for(re int i = (a); i < (b); ++ i)
#define rep(i, a, b) for(re int i = (a); i <=  (b); ++ i)
#define Down(i, a) for(re int i = (a); ~i; -- i)

static inline void swap(int &a, int &b) {
    re int t = a; a = b, b = t; return ;
}

struct EDGE  {
	int to, nxt;
}e[M];

int head[N], cnt;
static inline void add(int u, int v)  {
    e[++ cnt].to = v, e[cnt].nxt = head[u], 
    head[u] = cnt; return ; 
}
int n, m, s;
namespace LCA {
    int anc[N][LOG], depth[N], dist[N];
    void dfs(int u, int p, int d) {
        anc[u][0] = p, depth[u] = d; fwd(i, u) {
            re int v = e[i].to;
            if (v == p) continue;
            dist[v] = dist[u] + 1;
            dfs(v, u, d + 1);
        } return ;
    }
    static inline void init(int rt, int n) {
        dist[rt] = 0, dfs(rt, 0, 1);
        Rep(j, 1, LOG) rep(i, 1, n)
            anc[i][j] = anc[anc[i][j - 1]][j - 1];
        return ;
    }
    static inline void swim(int& x, int h) { 
        for (re int i = 0; h > 0; ++ i) {
            if (h & 1) x = anc[x][i]; h >>= 1;
        } return ;
    }
    static inline int query(int x, int y) {
        if (depth[x] < depth[y]) swap(x, y);
        swim(x, depth[x] - depth[y]);
        if (x == y) return x;
        Down(i, LOG - 1) if (anc[x][i] != anc[y][i]) 
            x = anc[x][i], y = anc[y][i];
        return anc[x][0];
    }
}
int main() {
    scanf("%d%d%d", &n, &m, &s); 
    re int u, v; Rep(i, 1, n)
        scanf("%d%d", &u, &v),
        add(u, v), add(v, u); 
	LCA :: init(s, n); while (m --) {
        scanf("%d%d", &u, &v); 
		printf("%d\n",LCA::query(u, v));
	} return 0;
}