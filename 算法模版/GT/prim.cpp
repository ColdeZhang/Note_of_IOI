#include <cstdio>
#include <queue>

typedef long long ll;

#define re register 
#define rep(i, a, b) for(re int i = (a); i <= (b); ++ i)
#define Rep(i, a, b) for(re int i = (a); i <  (b); ++ i)
#define fwd(i, u) for(re int i = head[(u)]; i; i = e[i].nxt)

const ll INF = 0x3f3f3f3f3f3f;
const int N = 2e5 + 5;
const int M = 1e6 + 5;

struct EDGE { int to, nxt; ll w; }e[M << 1];
int head[N], cnt, n, m;
bool vis[N]; ll dis[N], ans;

static inline void add(int u, int v, ll w) {
    e[++ cnt].nxt = head[u], e[cnt].to = v, e[cnt].w = w, head[u] = cnt;
    e[++ cnt].nxt = head[v], e[cnt].to = u, e[cnt].w = w, head[v] = cnt;
    return ;
}
struct NODE {
    ll d; int id;
    bool operator < (const NODE& rhs) const {
        return d > rhs.d;
    }
};
std::priority_queue<NODE> q;
static inline void prim() {
    rep(i, 1, n) dis[i] = INF; q.push( (NODE){ 0, 1 } );
    while (!q.empty()) { NODE u = q.top(); q.pop();
    	if (vis[u.id]) continue; vis[u.id] = 1; ans += u.d;
        fwd(i, u.id) if(dis[e[i].to] > e[i].w && !vis[e[i].to]) 
            dis[e[i].to] = e[i].w, q.push( (NODE){ dis[e[i].to], e[i].to} );
    } printf("%lld\n",ans); return ;
}
int main() {
    scanf("%d%d", &n, &m);
    re int u, v; re ll w; rep(i, 1, m) {
        scanf("%d%d%lld", &u, &v, &w);
        add(u, v, w);
    } prim(); return 0;
}