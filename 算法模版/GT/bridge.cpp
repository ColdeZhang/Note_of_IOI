#include <cstdio>
#include <algorithm>

#define re register
#define rep(i, a, b) for(re int i = (a); i <= (b); ++ i)
#define Rep(i, a, b) for(re int i = (a); i <  (b); ++ i)
#define fwd(i, u) for(re int i = head[(u)]; i; i = e[i].nxt)

static inline void upmin(int &a, int b) {
    if(a > b) a = b; return ;
}

const int MAXM = 2e6 + 5;
const int MAXN = 1e6 + 5;
int n, m; bool cut[MAXM];
int dfn[MAXN], low[MAXN], ind, res;
struct EDGE{ int nxt,to; }e[MAXM];
int cnt, head[MAXN];
inline void add(int u,int v){
    e[++ cnt].to = v, e[cnt].nxt = head[u], head[u] = cnt, cut[cnt] = 0;
    e[++ cnt].to = u, e[cnt].nxt = head[v], head[v] = cnt, cut[cnt] = 0;
}
void tar(int u, int fa){
	dfn[u] = low[u] = ++ ind; fwd(i, u){
        if(!(i ^ 1 ^ fa)) continue;
        int v = e[i].to; if(!dfn[v]) {
			tar(v, i), upmin(low[u], low[v]);
			if(low[v] > dfn[u])
                cut[i] = cut[i ^ 1] = 1;
		}else upmin(low[u], dfn[v]);
	} return ;
}
int main(){
    while(~scanf("%d%d",&n,&m)){
        rep(i, 1, n) dfn[i] = low[i] = head[i] = 0; 
        re int u, v; cnt = 1, res = 0; rep(i, 1, m)
            scanf("%d%d", &u, &v), add(u, v);
        rep(i, 1, n) if(!dfn[i])
            ind = 0, tar(i, 0);
        for(re int i = 2; i <= cnt; i += 2)
            res += cut[i];
        printf("%d\n", res);
    } return 0;
}