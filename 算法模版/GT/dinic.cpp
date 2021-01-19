#include <cstdio>
#include <queue>
#include <cctype>
#include <cstring>

typedef long long ll;
#define re register
#define rep(i, a, b) for(re int i = (a); i <= (b); ++ i)
#define Rep(i, a, b) for(re int i = (a); i <  (b); ++ i)
#define fwd(i, u) for(re int i = head[(u)]; i; i = e[i].nxt)

#define Finline __inline__ __attribute__((always_inline))
Finline char get_char() {
    static char buf[200000001], *p1 = buf, *p2 = buf + fread(buf, 1, 200000000, stdin);
    return p1 == p2 ? EOF : *p1++;
}
static inline ll rd() {
    ll num = 0; char c;
    while ((c = get_char()) < 48);
    while (num = num * 10 + c - 48, (c = get_char()) >= 48) ;
    return num;
}

static inline ll min(ll a, ll b) {
    return a < b ? a : b; 
}

const int N = 1e6 + 5;
const int M = 1e6 + 5;
const ll INF = 2e10 + 5;

int s, t, cnt, n, m;

struct NODE { int nxt, to; ll w; } e[M];
int head[N], depth[N], cur[N];
static inline void add(int u, int v, ll w) {
    e[++ cnt].to = v, e[cnt].nxt = head[u];
    e[cnt].w = w, head[u] = cnt; return ; 
}
static inline bool bfs() {
    memset(depth, 0, sizeof(depth));
    std::queue<ll> q; depth[s] = 1, q.push(s); 
    do { ll u = q.front(); q.pop();
        fwd(i, u) if (e[i].w > 0 && !depth[e[i].to])
            depth[e[i].to] = depth[u] + 1, q.push(e[i].to);
    } while (!q.empty()); return depth[t];
}
ll dfs(ll u, ll dist) {
    if (u == t) return dist; for(int& i = cur[u]; i; i = e[i].nxt)
        if ((depth[e[i].to] == depth[u] + 1) && e[i].w) {
            ll di = dfs(e[i].to, min(dist, e[i].w));
            if (di > 0) { e[i].w -= di, e[i ^ 1].w += di; return di; }
        }
    return 0;
}
static inline ll dinic() {
    ll ans = 0; while (bfs()) {
        rep(i, 1, n) cur[i] = head[i];
        while (ll di = dfs(s, INF)) ans += di;
    } return ans;
}
int main() {
    n = rd(), m = rd(), s = rd(), t = rd();
    cnt = 1; Rep(i, 0, m) {
        re int u = rd(), v = rd(); re ll w = rd();
        add(u, v, w), add(v, u, 0);
    } printf("%lld\n", dinic()); return 0;
}
