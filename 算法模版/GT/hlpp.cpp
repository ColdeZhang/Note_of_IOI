#include <cctype>
#include <cstdio>
#include <cmath>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;
typedef long double ldb;

#define re register
#define rep(i, a, b) for(re int i = (a); i <= (b); ++ i)
#define Rep(i, a, b) for(re int i = (a); i <  (b); ++ i)
#define fwd(i, u) for(re int i = head[(u)]; i; i = e[i].nxt)

#define MAXBUF 2097152
#define FLUSHSIZE 1966080
#define Finline __inline__ __attribute__ ((always_inline))
char READ_BUF[MAXBUF],*READ_P1=READ_BUF,*READ_P2=READ_BUF;
Finline ll getc(){return READ_P1==READ_P2&&(READ_P2=(READ_P1=READ_BUF)+fread(READ_BUF,1,MAXBUF,stdin),READ_P1==READ_P2)?EOF:*READ_P1++;}
static inline ll rd() {
    ll num=0;char c,sf=1;
    while(isspace(c=getc()));if(c=='-') sf=-1,c=getc();
    while(num=num*10+c-48,isdigit(c=getc()));
    return num*sf;
}
char WRITE_BUF[MAXBUF],WRITE_BUFFER[20];ll WRITE_P1,WRITE_P2=-1;
static inline void flush(){fwrite(WRITE_BUF,1,WRITE_P2+1,stdout),WRITE_P2=-1;}
static inline void check(){if(WRITE_P2>FLUSHSIZE) flush();return ;}
static inline void write(ll x) {
    if(x<0) WRITE_BUF[++WRITE_P2]=45,x=-x;
    do{WRITE_BUFFER[++WRITE_P1]=x%10+48;}while(x/=10);
    do{WRITE_BUF[++WRITE_P2]=WRITE_BUFFER[WRITE_P1];}while(--WRITE_P1);
    WRITE_BUF[++WRITE_P2]='\n';
}

const ll N = 1e4 + 5;
const ll M = 3e5 + 5;
const ll INF = 0x3f3f3f3f;

struct EDGE { ll nxt, to, w; } e[M];
ll n, m, s, t, head[N], cnt = 1;
inline void add(ll w, ll v, ll u) {
    e[++ cnt].to = v, e[cnt].nxt = head[u], e[cnt].w = w, head[u] = cnt,
    e[++ cnt].to = u, e[cnt].nxt = head[v], e[cnt].w = 0, head[v] = cnt;
    return;
}
ll dep[N], last[N], gap[N]; bool vis[N]; std::queue<ll> q;
struct cmp {
    inline bool operator()(ll a, ll b) const { 
        return dep[a] < dep[b]; 
    } 
};
inline void bfs() {
    memset(dep, 0x3f, sizeof(dep));
    dep[t] = 0, q.push(t); while (!q.empty()) {
        ll u = q.front(); q.pop(), vis[u] = false;
        fwd(i, u) if (dep[e[i].to] > dep[u] + 1 && e[i ^ 1].w) {
            dep[e[i].to] = dep[u] + 1;
            if (!vis[e[i].to]) q.push(e[i].to), vis[e[i].to] = 1;
        }
    } return;
}
priority_queue<ll, vector<ll>, cmp> que;
inline void PUSH(ll u) {
    fwd(i, u) if (e[i].w && dep[e[i].to] + 1 == dep[u]) {
        ll v = e[i].to, val = min(e[i].w, last[u]);
        e[i].w -= val, e[i ^ 1].w += val, last[u] -= val, last[v] += val;
        if (!vis[v] && v != t && v != s)
            que.push(v), vis[v] = 1;
        if (!last[u]) break;
    } return ;
}
inline void relabel(ll u) {
    dep[u] = INF; fwd(i, u) 
        if (e[i].w && dep[e[i].to] + 1 < dep[u])
            dep[u] = dep[e[i].to] + 1;
    return ;
}
inline ll hlpp() {
    bfs(); if (dep[s] == INF) return 0;
    dep[s] = n; rep(i, 1, n)
        if (dep[i] < INF) gap[dep[i]] ++;
    for (ll i = head[s]; i; i = e[i].nxt) {
        ll v = e[i].to, val = e[i].w; if (val) {
            last[s] -= val, last[v] += val,
            e[i].w += val, e[i ^ 1].w += val;
            if (v != t && v != s && !vis[v])
                que.push(v), vis[v] = 1;
        }
    } while (!que.empty()) {
        ll u = que.top(); que.pop(), vis[u] = 0;
        PUSH(u); if (last[u]) {
            if (!(--gap[dep[u]]))
                rep(i, 1, n) if (i != s && i != t && dep[i] > dep[u] && dep[i] < n + 1)
                    dep[i] = n + 1;
            relabel(u), gap[dep[u]] ++, que.push(u), vis[u] = 1;
        }
    } return last[t];
}
int main() {
    n = rd(), m = rd(), s = rd(), t = rd();
    while (m --) add(rd(), rd(), rd());
    write(hlpp()), flush(); return 0;
}
