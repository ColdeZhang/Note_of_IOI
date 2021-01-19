#include <cstdio>
#include <algorithm>

#define re register
#define rep(i, a, b) for(re int i = (a); i <= (b); ++ i)
#define Rep(i, a, b) for(re int i = (a); i <  (b); ++ i)

const int N = 2e5 + 5;
const int SEG = N << 5;

int lc[SEG], rc[SEG], rt[N], sum[SEG];
int a[N], b[N], ind, n, m, p;

void build(int &t, int l, int r) {
    t = ++ ind; if(l == r) return ;
    re int mid = (l + r) >> 1;
    build(lc[t], l, mid), build(rc[t], mid + 1, r); 
    return ;
}

int modify(int i, int l, int r) {
    int cur = ++ ind;
    lc[cur] = lc[i], rc[cur] = rc[i], sum[cur] = sum[i] + 1;
    if(l == r) return cur; int mid = (l + r) >> 1;
    if(p <= mid) lc[cur] = modify(lc[cur], l, mid);
    else rc[cur] = modify(rc[cur], mid + 1, r);
    return cur;
}

int query(int u, int v, int l, int r, int k) {
    if(l == r) return l;
    int mid = (l + r) >> 1, val = sum[lc[v]] - sum[lc[u]];
    if(val >= k) return query(lc[u], lc[v], l, mid, k);
    return query(rc[u], rc[v], mid + 1, r, k - val);
}

int main() {
    scanf("%d%d", &n, &m);
    rep(i, 1, n) scanf("%d", &a[i]), b[i] = a[i];
    std::sort(b + 1, b + n + 1); 
    re int len = std::unique(b + 1, b + n + 1) - b - 1;
    build(rt[0], 1, len); rep(i, 1, n) {
        p = std::lower_bound(b + 1, b + len + 1, a[i]) - b;
        rt[i] = modify(rt[i - 1], 1, len);
    } re int l, r, k; while(m --) {
        scanf("%d%d%d", &l, &r, &k);
        printf("%d\n", b[query(rt[l - 1], rt[r], 1, len, k)]);
    } return 0;
}