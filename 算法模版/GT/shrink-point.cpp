#include <cstdio> 
#include <cstring>

#define re register
#define rep(i, a, b) for(re int i = (a); i <= (b); ++ i)
#define Rep(i, a, b) for(re int i = (a); i <  (b); ++ i)
#define fwd(i, u) for(re int i = head[(u)]; i; i = e[i].nxt)

const int N = 1e5 + 5;
const int M = 2e6 + 5;

static inline void upmin(int &a, int b) {
    if(a > b) a = b; return ;
}

int head[N], cnt;

struct EDGE { int to, nxt; } e[M];

static inline void add(int u, int v) {
    e[++ cnt].to = v, e[cnt].nxt = head[u], head[u] = cnt;
    return ;
}

int n, m, sta[N], top, low[N], dfn[N];
int tot, col[N], ind; bool ins[N];

void tar(int u) {
    sta[++ top] = u; low[u] = dfn[u] = ++ ind, 
    ins[u] = 1; fwd(i, u) {
        re int v = e[i].to;
        if(!dfn[v]) tar(v), upmin(low[u], low[v]);
        else if(ins[v]) upmin(low[u], dfn[v]);
    } if(dfn[u] == low[u]) {
        ++ tot; while(sta[top + 1] != u)
            col[sta[top]] = tot,
            ins[sta[top --]] = 0;
    } return ;
}

int main() {
    while(~scanf("%d%d", &n, &m)){
        memset(dfn, 0, sizeof(dfn));
        re int u, v; ind = tot = 0;
        rep(i, 1, m) scanf("%d%d", &u, &v), add(u, v);
        rep(i, 1, n){ 
            if(!dfn[i]) ind = 0, tar(i);
            head[i] = 0;
        } cnt = 0; printf("%d\n", tot);
    } return 0;
}