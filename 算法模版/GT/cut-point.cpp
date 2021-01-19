#include <cstdio>
#include <cstring>

#define re register
#define rep(i, a, b) for(re int i = (a); i <= (b); ++ i)
#define Rep(i, a, b) for(re int i = (a); i <  (b); ++ i)
#define fwd(i, u) for(re int i = head[(u)]; i; i = e[i].nxt)

const int N = 1e6 + 5;
const int M = 2e6 + 5;

struct EDGE { int to, nxt; } e[M];

int head[N], cnt;

static inline void add(int u, int v) {
    e[++ cnt].to = v, e[cnt].nxt = head[u], head[u] = cnt;
    e[++ cnt].to = u, e[cnt].nxt = head[v], head[v] = cnt;
}

static inline void upmin(int &a, int b) {
    if(a > b) a = b; return ;
}

int dfn[N], low[N], ind, res; bool mk[N];

void tar(int u, int fa) {
    dfn[u] = low[u] = ++ ind; re int child = 0; 
    fwd(i, u) {
        re int v = e[i].to;
        if(v == fa) continue;
        if(!dfn[v]) {
            ++ child, tar(v, u);
            upmin(low[u], low[v]);
            if(fa != u && low[v] >= dfn[u] && !mk[u])
                mk[u] = true, ++ res;
        } else upmin(low[u], dfn[v]);
    } if(u == fa && child >= 2 && !mk[u]) 
        mk[u] = true, ++ res;
    return ;
}

int n, m; 

int main() {
    scanf("%d", &n); while(n) {
        re int st; ind = 0; scanf("%d", &st); while(st) {
            char c = getchar(); re int num = 0;
            while(c != '\n') {
                while(c < 48) c = getchar();
                while(c > 47) num = num * 10 + c - 48, c = getchar();
                add(st, num); num = 0;
            } scanf("%d", &st);
        } rep(i, 1, n){ if(!dfn[i]) ind = 0, tar(i, i); head[i] = 0; }
        memset(dfn, 0, sizeof(dfn)), memset(mk, 0, sizeof(mk));
        printf("%d\n", res), res = 0; scanf("%d", &n);
    } return 0;
}