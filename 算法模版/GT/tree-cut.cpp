#include <cstdio>
#include <algorithm>

#define re register
#define rep(i, a, b) for(re int i = (a); i <= (b); ++ i)
#define Rep(i, a, b) for(re int i = (a); i <  (b); ++ i)
#define fwd(i, u) for(re int i = head[(u)]; i; i = e[i].nxt)

typedef long long ll;

const int N = 1e6 + 5;
const int M = 2e6 + 5;

struct EDGE { int nxt, to; } e[M];
int n, m, r, mod, cnt, sz[N], top[N];
int head[N], w[N], wt[N], dep[N];
int son[N], id[N], fa[N], ind;

static inline void swap(int &a, int &b) {
    re int t = a; a = b, b = t; return ;
}

static inline void add(int u, int v) {
    e[++cnt].to = v, e[cnt].nxt = head[u], 
    head[u] = cnt; return ;
}

struct SEG { int add, w, l, r; } tr[N << 2];
inline void build(int i, int l, int r) {
    tr[i].l = l, tr[i].r = r;
    if (l == r) tr[i].w = wt[l] % mod;
    else {
        int mid = (l + r) >> 1, lson = (i << 1), rson = lson | 1;
        build(lson, l, mid), build(rson, mid + 1, r), 
        tr[i].w = (tr[lson].w + tr[rson].w) % mod;
    } return ;
}
static inline void pd(int i) {
    int lson = i << 1, rson = lson | 1;
    tr[lson].add += tr[i].add, tr[rson].add += tr[i].add;
    tr[lson].w += tr[i].add * (tr[lson].r - tr[lson].l + 1), 
    tr[rson].w += tr[i].add * (tr[rson].r - tr[rson].l + 1);
    tr[lson].w %= mod, tr[rson].w %= mod, tr[i].add = 0;
    return ;
}
inline int query(int i, int l, int r) {
    if (l <= tr[i].l && tr[i].r <= r) return tr[i].w % mod;
    else {
        if (tr[i].add) pd(i);
        re int mid = (tr[i].l + tr[i].r) >> 1, lson = (i << 1), rson = lson | 1;
        if (r <= mid) return query(lson, l, r) % mod;
        if (l > mid) return query(rson, l, r) % mod;
        return (query(lson, l, r) + query(rson, l, r)) % mod;
    }
}
inline void update(int i, int l, int r, int k) {
    if (l <= tr[i].l && tr[i].r <= r)
        tr[i].add += k, tr[i].w += k * (tr[i].r - tr[i].l + 1);
    else {
        if (tr[i].add) pd(i);
        re int mid = (tr[i].l + tr[i].r) >> 1, lson = (i << 1), rson = lson | 1;
        if (l <= mid) update(lson, l, r, k);
        if (r > mid) update(rson, l, r, k);
        tr[i].w = (tr[lson].w + tr[rson].w) % mod;
    }
}
static inline ll qRange(int x, int y) {
    re ll ans = 0; while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        ans = (ans + query(1, id[top[x]], id[x]) % mod) % mod;
        x = fa[top[x]];
    } if (dep[x] > dep[y]) swap(x, y);
    ans = (ans + query(1, id[x], id[y]) % mod) % mod;
    return ans;
}
static inline void updRange(int x, int y, int k) {
    k %= mod; while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        update(1, id[top[x]], id[x], k);
        x = fa[top[x]];
    } if (dep[x] > dep[y]) swap(x, y);
    update(1, id[x], id[y], k);
}
inline ll qSon(int i) { return query(1, id[i], id[i] + sz[i] - 1) % mod; }
inline void updSon(int i, int k) { update(1, id[i], id[i] + sz[i] - 1, k); }
inline void dfs1(int u, int f, int depth) {
    dep[u] = depth, fa[u] = f, sz[u] = 1; 
    re int maxson = -1; fwd(i, u) {
        int v = e[i].to;
        if (v == f) continue;
        dfs1(v, u, depth + 1);
        sz[u] += sz[v];
        if (sz[v] > maxson)
            son[u] = v, 
            maxson = sz[v];
    } return ;
}

inline void dfs2(int u, int topf) {
    id[u] = ++ind, wt[ind] = w[u], top[u] = topf;
    if (!son[u]) return; dfs2(son[u], topf);
    fwd(i, u) {
        re int v = e[i].to;
        if (v == fa[u] || v == son[u])
            continue;
        dfs2(v, v);
    } return ;
}

int main() {
    scanf("%d%d%d%d", &n, &m, &r, &mod);
    rep(i, 1, n) scanf("%d", &w[i]); re int u, v;
    Rep(i, 1, n) scanf("%d%d", &u, &v), add(u, v), add(v, u);
    dfs1(r, 0, 1), dfs2(r, r), build(1, 1, n); 
    re int k, x, y, z; while (m--) {
        scanf("%d", &k); if (k == 1) scanf("%d%d%d", &x, &y, &z), updRange(x, y, z);
        else if (k == 2) scanf("%d%d", &x, &y), printf("%lld\n", qRange(x, y));
        else if (k == 3) scanf("%d%d", &x, &y), updSon(x, y);
        else scanf("%d", &x), printf("%lld\n", qSon(x));
    } return 0;
}