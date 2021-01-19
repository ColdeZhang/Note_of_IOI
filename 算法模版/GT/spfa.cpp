#include <cstdio>
#include <queue>

#define re register
#define rep(i, a, b) for(re int i = (a); i <= (b); ++ i)
#define fwd(i, u) for(re int i = head[(u)]; i; i = e[i].nxt)

const int N = 2e5 + 5;
const int M = 1e6 + 5;
const int INF = 0x3f3f3f3f;

struct EDGE { int to, w, nxt; } e[M];

int n, head[N], dis[N], cnt; bool inq[N];

static inline void add(int u, int v, int w) {
    e[++ cnt].to = v, e[cnt].nxt = head[u],
    e[cnt].w = w, head[u] = cnt; 
    e[++ cnt].to = u, e[cnt].nxt = head[v],
    e[cnt].w = w, head[v] = cnt;  return ;
}

std::queue<int> q;

static inline void spfa(int s) {
    rep(i, 1, n) dis[i] = INF, inq[i] = 0; dis[s] = 0;
    q.push(s), inq[s] = 1; while(!q.empty()) {
        re int u = q.front(); q.pop();
        inq[u] = 0; fwd(i, u) {
            re int v = e[i].to;
            if(dis[v] > dis[u] + e[i].w) {
                dis[v] = dis[u] + e[i].w;
                if(!inq[v]) inq[v] = 1, q.push(v); 
            }
        }
    } return ;
}

int main() {
    re int m, s, t, u, v, w;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    while(m --)
        scanf("%d%d%d", &u, &v, &w),
        add(u, v, w);
    spfa(s); printf("%d\n", dis[t]);
    return 0;
}