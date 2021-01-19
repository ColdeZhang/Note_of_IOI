#include <cstdio>
#include <queue>
typedef double db;

#define re register
#define rep(i, a, b) for(re int i = (a); i <= (b); ++ i)
#define Rep(i, a, b) for(re int i = (a); i <  (b); ++ i)

const int N = 5e3 + 5;
const int M = 4e5 + 5;
const db inf = 2e9;

int n, m, k, cur, h[M], nxt[M], TO[M], cnt[N], ans;
int cur1, h1[M], nxt1[M], TO1[M];
db e, w[M], f[N],w1[M];
bool flag[N];

void add_edge(int x, int y, db z) {
    cur ++;
    nxt[cur] = h[x];
    h[x] = cur;
    TO[cur] = y;
    w[cur] = z;
}
void add_edge1(int x, int y, db z) {
    cur1 ++;
    nxt1[cur1] = h1[x];
    h1[x] = cur1;
    TO1[cur1] = y;
    w1[cur1] = z;
}
struct node {
    int x; db v;
    bool operator<(node a) const { return v + f[x] > a.v + f[a.x]; }
};
std::priority_queue<node> q;
struct node2 {
    int x; db v;
    bool operator<(node2 a) const { return v > a.v; }
} x;
std::priority_queue<node2> Q;

int main() {
    scanf("%d%d%lf", &n, &m, &e); while (m --) {
        int u, v; db val;
        scanf("%d%d%lf", &u, &v, &val);
        add_edge(u, v, val),
        add_edge1(v, u, val);
    } Rep(i, 1, n) f[i] = inf;
    Q.push({n, 0}); while (!Q.empty()) {
        x = Q.top(); Q.pop();
        if (flag[x.x]) continue;
        flag[x.x] = true, f[x.x] = x.v;
        for (int j = h1[x.x]; j; j = nxt1[j]) 
            Q.push({TO1[j], x.v + w1[j]});
    } k = (int)e / f[1]; q.push({1, 0});
    while (!q.empty()) {
        node x = q.top(); q.pop();
        cnt[x.x] ++; if (x.x == n) {
            e -= x.v; if (e < 0) {
                printf("%d\n", ans);
                return 0;
            } ans ++;
        } for (int j = h[x.x]; j; j = nxt[j])
            if (cnt[TO[j]] <= k && x.v + w[j] <= e) 
                q.push({TO[j], x.v + w[j]});
    } printf("%d\n", ans); return 0;
}
