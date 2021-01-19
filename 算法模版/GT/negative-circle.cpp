#include <cstdio>
#include <queue>

#define re register
#define rep(i, a, b) for(re int i = (a); i <= (b); ++ i)
#define fwd(i, u) for(re int i = head[(u)]; i; i = e[i].nxt)

const int M = 6e3 + 5;
const int N = 2e3 + 5;
const int INF = 0x3f3f3f3f;

int n, m, head[N], dis[N], cnt, step[N];
bool inq[N];

struct EDGE {
	int nxt, to, w;
}e[M];

static inline void add(int u, int v, int w) {
	e[++ cnt].nxt = head[u],
	e[cnt].to = v, 
	e[cnt].w = w,
	head[u] = cnt;
	return ;
}

std::queue<int> q;

static inline bool spfa(int s) {
	rep(i, 1, n) dis[i] = INF,step[i] = inq[i] = 0;
	while (!q.empty()) q.pop();
	dis[s] = 0, q.push(s), inq[s] = step[s] = 1;
	while (!q.empty()) {
		re int u = q.front(); q.pop(), inq[u] = false;
		fwd(i, u) {
			re int v = e[i].to;
			if (dis[v] > dis[u] + e[i].w) {
				dis[v] = dis[u] + e[i].w;
				if (!inq[v]) {
					step[v] = step[u] + 1;
					if (step[v] > n) return 1;
					q.push(v), inq[v] = true;
				}
			}
		}
	} return 0;
}

int main() {
    int T; scanf("%d", &T); while (T --) {
		scanf("%d%d", &n, &m); while (m --) {
			re int u, v, w; scanf("%d%d%d", &u, &v, &w);
			add(u, v, w); if (w >= 0) add(v, u, w);
		} puts(spfa(1) ? "YES" : "NO");		
		cnt = 0; rep(i, 1, n) head[i] = 0; 
	}
	return 0;
}


