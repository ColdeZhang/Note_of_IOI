#include<cstdio>
#include<algorithm>
#include<cctype>

#define fwd(i, u) for(register int i = head[(u)]; i; i = e[i].nxt)
#define rep(i, a, b) for(register int i = (a); i <= (b); ++ i)
#define Rep(i, a, b) for(register int i = (a); i <  (b); ++ i)

inline int rd(){
    int res = 0; char c = getchar();
    while(!isdigit(c)) c = getchar();
    while(isdigit(c)) res = res * 10 + c - 48, c = getchar();
    return res;
}
inline int max(int a, int b){ return a > b ? a : b; }
inline void upmax(int &a, int b){ if(b > a) a = b; return ; }

const int N = 1e4 + 5;
const int M = 1e2 + 5;

int n, m, q[M];
int son_sz[N], sz[N], rt, tot = 0;
int dis[N], b[N], a[N];
bool vis[N], mk[M];

int e_cnt = 0, head[N];
struct EDGE{int to, nxt, w;}e[N << 1];
void add(int w, int v, int u){
    e[++ e_cnt] = (EDGE){v, head[u], w}; head[u] = e_cnt;
    e[++ e_cnt] = (EDGE){u, head[v], w}; head[v] = e_cnt;
    return ;
}

void get_rt(int u, int f, int total){
    sz[u] = 1, son_sz[u] = 0;
    fwd(i, u){
        int v = e[i].to;
        if(v == f || vis[v]) continue;
        get_rt(v, u, total), sz[u] += sz[v];
        upmax(son_sz[u], sz[v]);
    }
    upmax(son_sz[u], total - sz[u]);
    if(!rt || son_sz[u] < son_sz[rt]) rt = u;
    return ;
}
inline bool cmp(int x, int y){ return dis[x] < dis[y]; }
void get_dis(int u, int f, int d, int from){
    dis[(a[++ tot] = u)] = d, b[u] = from;
    fwd(i, u){
        int v = e[i].to;
        if(v == f || vis[v]) continue;
        get_dis(v, u, d + e[i].w, from);
    }
    return ;
}
void calc(int u){
    a[(tot = 1)] = u, dis[(b[u] = u)] = 0;
    fwd(i, u){
        int v = e[i].to;
        if(vis[v]) continue;
        get_dis(v, u, e[i].w, v);
    }
    std::sort(a + 1, a + tot + 1, cmp);
    rep(i, 1, m){
        int l = 1, r = tot;
        if(mk[i]) continue;
        while(l < r){
            if(dis[a[l]] + dis[a[r]] > q[i]) -- r;
            else if(dis[a[l]] + dis[a[r]] < q[i]) ++ l;
            else if(b[a[l]] == b[a[r]]){
                if(dis[a[r]] == dis[a[r - 1]]) -- r;
                else ++ l;
            } else{ mk[i] = true; break; }
        }
    }
    return ;
}
void solve(int u){
    vis[u] = true, calc(u);
    fwd(i, u){
        int v = e[i].to;
        if(vis[v]) continue;
        get_rt(v, (rt = 0), sz[v]);
        solve(rt);
    } return ;
}
int main(){
    n = rd(), m = rd();
    Rep(i, 1, n) add(rd(), rd(), rd());
    rep(i, 1, m) if(!(q[i] = rd())) mk[i] = 1;
    get_rt(1, 0, (son_sz[0] = n)), solve(rt);
    rep(i, 1, m) puts( mk[i] ? "AYE" : "NAY" );
    return 0;
}
