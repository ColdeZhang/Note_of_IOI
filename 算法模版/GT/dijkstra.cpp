#include <cstdio>
#include <queue>

#define re register
#define rep(i, a, b) for(re int i = (a); i <= (b); ++ i)
#define Rep(i, a, b) for(re int i = (a); i <  (b); ++ i)
#define fwd(i, u) for(re int i = head[(u)]; i; i = e[i].nxt)

typedef long long ll;

const ll INF = 0x3f3f3f3f3f3f;
const int M = 3e6 + 5;
const int N = 3e6 + 5;

struct EDGE {
    int to, nxt; ll w;
} e[M];

int n, m, head[N], cnt; ll dis[N];

static inline void add(int u, int v, ll w) {
    e[++ cnt].to = v, e[cnt].nxt = head[u],
    e[cnt].w = w, head[u] = cnt; return ;
}

struct NODE {
    ll d; int id;
    bool operator < (const NODE &rhs) const {
        return d > rhs.d;
    }
};

std::priority_queue<NODE> q;

int main() {
    re int T, u, v; re ll w; scanf("%d", &T); while(T --) {
        scanf("%d%d", &n, &m); while(m --)
            scanf("%d%d%lld", &u, &v, &w),
            add(u, v, w), add(v, u, w);
        rep(i, 1, n) dis[i] = INF; dis[1] = 0;
        q.push((NODE){ 0, 1 }); while(!q.empty()) {
            NODE u = q.top(); q.pop(); fwd(j, u.id) {
                re int v = e[j].to;
                if(dis[v] > u.d + e[j].w)
                    dis[v] = u.d + e[j].w,
                    q.push((NODE){ dis[v], v });
            }
        } rep(i, 1, n) printf("%lld ", dis[i]), head[i] = 0; 
        cnt = 0, putchar('\n');
    } return 0;
}