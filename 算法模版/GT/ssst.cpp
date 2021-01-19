#include<cstdio>
#include<algorithm>

#define rep(i, a, b) for(register int i = (a); i <= (b); ++ i)
#define fwd(i, u) for(register int i = head[(u)]; i; i = e[i].nxt)

typedef long long ll;

static inline ll max(ll a, ll b){
    return a > b ? a : b;
}
static inline void upmax(ll &a, ll b){
    if(a < b) a = b; return ;
}
static inline void upmin(ll &a, ll b){
    if(a > b) a = b; return ;
}
static inline void swap(ll &a, ll &b){
    register ll t = a; a = b; b = t;
    return ;
}

const ll MAXN = 1e6 + 5;
const ll MAXM = 3e6 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;

ll n, m, f[MAXN], mst, head[MAXN], cnt;
struct INIT { ll u, v, w; bool mk; } tmp[MAXM];
struct EDGE { ll to, nxt, w; } e[MAXN << 1];

static inline bool cmp(INIT A, INIT B){
    return A.w < B.w;
}

ll find(ll x){
    return f[x] == x ? x : f[x] = find(f[x]);
}

static inline void merge(ll x, ll y){
    f[find(x)] = find(y); return ;
}

static inline bool check(ll x, ll y){
    return find(x) == find(y);
}

static inline void add(ll u, ll v, ll w){
    e[++ cnt].to = v, e[cnt].w = w, e[cnt].nxt = head[u], head[u] = cnt;
    e[++ cnt].to = u, e[cnt].w = w, e[cnt].nxt = head[v], head[v] = cnt;
    return ;
}

ll w[MAXN], val[MAXN], son[MAXN], id[MAXN], fa[MAXN];
ll ind, dep[MAXN], sz[MAXN], top[MAXN];

struct SEG { ll l, r, MAX, SEC; } tr[MAXN << 2];
void build(ll i,ll l,ll r){
    tr[i].l = l, tr[i].r = r; if(l == r) tr[i].MAX = w[l], tr[i].SEC = -INF; else{
        register ll mid = (l + r) >> 1, lson = (i << 1), rson = lson | 1;
        build(lson, l, mid), build(rson, mid + 1, r);
        tr[i].MAX = tr[lson].MAX, tr[i].SEC = tr[lson].SEC;
        if(tr[rson].MAX > tr[i].MAX) tr[i].SEC = tr[i].MAX, tr[i].MAX = tr[rson].MAX;
        if(tr[rson].MAX < tr[i].MAX && tr[rson].MAX > tr[i].SEC) tr[i].SEC = tr[rson].MAX;
        if(tr[rson].SEC > tr[i].SEC) tr[i].SEC = tr[rson].SEC;
    } return ;
}
ll query_max(ll i,ll l,ll r){
    if(l <= tr[i].l && tr[i].r <= r) return tr[i].MAX; else{
        register ll mid = (tr[i].l + tr[i].r) >> 1;
        if(r <= mid) return query_max(i << 1,l,r);
        if(l > mid) return query_max((i << 1) + 1,l,r);
        return max(query_max(i << 1,l,r), query_max((i << 1) + 1,l,r));
    } 
}

static inline ll Range_MAX(ll u, ll v){
    ll res = -INF; while(top[u] != top[v]){
        if(dep[top[u]] < dep[top[v]]) swap(u,v);
        upmax(res, query_max(1, id[top[u]], id[u]));
        u = fa[top[u]];
    } if(dep[u] > dep[v]) swap(u, v);
    if(id[u] == id[v]) return res;
    else  upmax(res, query_max(1, id[u] + 1, id[v]));
    return res;
}

ll TMPMAX, TMPSEC;

void query_sec(ll i, ll l,ll r){
    if(l <= tr[i].l && tr[i].r <= r) {
        if(tr[i].MAX > TMPMAX) TMPSEC = TMPMAX, TMPMAX = tr[i].MAX;
        if(tr[i].MAX < TMPMAX && tr[i].MAX > TMPSEC) TMPSEC = tr[i].MAX;
        if(tr[i].SEC > TMPSEC) TMPSEC = tr[i].SEC;
    } else{
        register ll mid = (tr[i].l + tr[i].r) >> 1;
        if(r <= mid) query_sec(i << 1,l,r);
        else if(l > mid) query_sec((i << 1) + 1,l,r);
        else query_sec(i << 1,l,r), query_sec((i << 1) + 1,l,r);
    } return ;
}

static inline ll Range_SEC(ll u,ll v){
    TMPMAX = TMPSEC = -INF; while(top[u] != top[v]){
        if(dep[top[u]] < dep[top[v]]) swap(u,v);
        query_sec(1, id[top[u]], id[u]), u = fa[top[u]];
    } if(dep[u] > dep[v]) swap(u,v); 
    if(id[u] == id[v]) return TMPSEC;
    else query_sec(1, id[u], id[v]); return TMPSEC; 
}

inline void dfs1(ll u, ll F, ll depth){
    dep[u] = depth, fa[u] = F, sz[u] = 1; 
    ll maxson = -1;  fwd(i, u){
        register ll v = e[i].to;
        if(v == F) continue; val[v] = e[i].w;
        dfs1(v, u, depth + 1), sz[u] += sz[v];
        if(sz[v] > maxson) son[u] = v, maxson = sz[v];
    } return ;
}
inline void dfs2(ll u,ll topf){
    id[u] = ++ ind, w[ind] = val[u], top[u] = topf; 
    if(!son[u]) return; dfs2(son[u], topf); fwd(i, u){
        register ll v = e[i].to;
        if(v == fa[u] || v == son[u]) continue;
        dfs2(v, v);
    } return ;
}

int main(){
    scanf("%lld%lld", &n, &m); rep(i, 1, n) f[i] = i;
    rep(i, 1, m) 
    	scanf("%lld%lld%lld", &tmp[i].u, &tmp[i].v, &tmp[i].w),
        tmp[i].mk = 0;
    std::sort(tmp + 1, tmp + m + 1, cmp); 
    register ll num = 1; rep(i, 1, m){
        if(tmp[i].u == tmp[i].v) continue;
        if(check(tmp[i].u, tmp[i].v)) continue;
        merge(tmp[i].u, tmp[i].v);
        add(tmp[i].u, tmp[i].v, tmp[i].w);
        mst += tmp[i].w, ++ num, tmp[i].mk = 1;
        if(num == n) break;
    } val[1] = -INF; dfs1(1, 0, 1), dfs2(1, 1); build(1, 1, n);
    register ll ans = INF; rep(i, 1, m) if(!tmp[i].mk) {
        if(tmp[i].u == tmp[i].v) continue;
        register ll MAX = Range_MAX(tmp[i].u, tmp[i].v);
        if(MAX == tmp[i].w) MAX = Range_SEC(tmp[i].u, tmp[i].v);
        upmin(ans, mst - MAX + tmp[i].w);
    } printf("%lld\n", ans); return 0;
}

