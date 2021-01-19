#include <cstdio>
#include <queue> 
#include <cstring>
#include <cctype>

typedef long long ll;
typedef long double ldb;

#define MAXBUF 2097152
#define FLUSHSIZE 1966080
#define Finline __inline__ __attribute__((always_inline))
char READ_BUF[MAXBUF], *READ_P1 = READ_BUF, *READ_P2 = READ_BUF;
Finline ll getc() { return READ_P1 == READ_P2 && (READ_P2 = (READ_P1 = READ_BUF) + fread(READ_BUF, 1, MAXBUF, stdin), READ_P1 == READ_P2) ? EOF : *READ_P1++; }
static inline ll rd() {
    ll num = 0; char c, sf = 1;
    while (isspace(c = getc())) ;
    if (c == '-') sf = -1, c = getc();
    while (num = num * 10 + c - 48, isdigit(c = getc()));
    return num * sf;
}
char WRITE_BUF[MAXBUF], WRITE_BUFFER[20];
ll WRITE_P1, WRITE_P2 = -1;
static inline void flush() { fwrite(WRITE_BUF, 1, WRITE_P2 + 1, stdout), WRITE_P2 = -1; }
static inline void check() { if (WRITE_P2 > FLUSHSIZE) flush(); return; }
static inline void write(ll x) {
    if (x < 0) WRITE_BUF[++WRITE_P2] = 45, x = -x;
    do { WRITE_BUFFER[++WRITE_P1] = x % 10 + 48; } while (x /= 10);
    do { WRITE_BUF[++WRITE_P2] = WRITE_BUFFER[WRITE_P1]; } while (--WRITE_P1);
    WRITE_BUF[++WRITE_P2] = '\n';
}

static inline ll min(ll a, ll b) {
    return a < b ? a : b;
}

const ll INF = (1 << 30);
const ll N = 1e6 + 5;
const ll M = 1e6 + 5;
struct EDGE { ll to, nxt, w; } e[M];
ll n, m, s, t, dep[N], cur[N], gap[N], cnt = 1, head[N];
inline void add(ll w, ll v, ll u) {
    e[++cnt].to = v, e[cnt].w = w, e[cnt].nxt = head[u], head[u] = cnt;
    e[++cnt].to = u, e[cnt].w = 0, e[cnt].nxt = head[v], head[v] = cnt;
    return;
}
void bfs() {
    dep[t] = 1, ++gap[1]; std::queue<ll> q; q.push(t);
    while (!q.empty()) {
        ll u = q.front(); q.pop();
        for (ll i = head[u]; i; i = e[i].nxt) {
            ll v = e[i].to;
            if (dep[v] || !e[i ^ 1].w) continue;
            q.push(v), gap[dep[v] = dep[u] + 1]++;
        }
    }
    return;
}
ll maxflow;
ll dfs(ll u, ll flow) {
    if (u == t) { maxflow += flow; return flow; }
    ll used = 0; for (ll& i = cur[u]; i; i = e[i].nxt) {
        ll v = e[i].to; if (e[i].w && dep[v] + 1 == dep[u]) {
            ll val = dfs(v, min(e[i].w, flow - used));
            if (val) e[i].w -= val, e[i ^ 1].w += val, used += val;
            if (used == flow) return used;
        }
    }
    if (!(-- gap[dep[u]])) dep[s] = n + 1;
    ++ gap[++ dep[u]], cur[u] = head[u];
    return used;
}
int main() {
    n = rd(), m = rd(), s = rd(), t = rd();
    for (ll i = 1; i <= m; i++) add(rd(), rd(), rd());
    bfs(), memcpy(cur, head, sizeof(head));
    while (dep[s] <= n) dfs(s, INF);
    write(maxflow), flush(); return 0;
}
