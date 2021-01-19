#include <cstdio>

typedef long long ll;

#define re register
#define rep(i, a, b) for(re int i = (a); i <= (b); ++ i)
#define Rep(i, a, b) for(re int i = (a); i <  (b); ++ i)

const int N = 1e5 + 5;

struct SEG { int l, r; ll w, add; } tr[N << 5];
ll a[N];

void build(int i, int l, int r) {
    tr[i].l = l, tr[i].r = r, tr[i].add = 0;
    if(l == r) { tr[i].w = a[l]; return ; }
    re int mid = (l + r) >> 1, lson = (i << 1), rson = lson | 1;
    build(lson, l, mid), build(rson, mid + 1, r);
    tr[i].w = tr[lson].w + tr[rson].w;
    return ;
}

static inline void pd(int i) {
    re int lson = (i << 1), rson = lson | 1;
    tr[lson].w += tr[i].add * (tr[lson].r - tr[lson].l + 1);
    tr[rson].w += tr[i].add * (tr[rson].r - tr[rson].l + 1);
    tr[lson].add += tr[i].add, tr[rson].add += tr[i].add; 
    tr[i].add = 0; return ;
}

void modify(int i, int l, int r, ll val) {
    if(l <= tr[i].l && tr[i].r <= r) {
        tr[i].add += val,
        tr[i].w += val * (tr[i].r - tr[i].l + 1);
        return ;
    } if(tr[i].add) pd(i); 
    re int lson = (i << 1), rson = lson | 1;
    if(tr[lson].r < l) modify(rson, l, r, val);
    else if(tr[rson].l > r) modify(lson, l, r, val);
    else modify(lson, l, r, val), modify(rson, l, r, val);
    tr[i].w = tr[lson].w + tr[rson].w; return ;
}

ll query(int i, int l, int r) {
    if(l <= tr[i].l && tr[i].r <= r) return tr[i].w;
    if(tr[i].add) pd(i);
    re int lson = (i << 1), rson = lson | 1;
    if(tr[lson].r < l) return query(rson, l, r);
    if(tr[rson].l > r) return query(lson, l, r);
    return query(lson, l, r) + query(rson, l, r);
}

int n, m;

int main() {
    scanf("%d%d", &n, &m);
    rep(i, 1, n) scanf("%lld", &a[i]); 
    build(1, 1, n); re int opt, l, r; 
    re ll val; while(m --) {
        scanf("%d", &opt);
        if(opt == 1) {
            scanf("%d%d%lld", &l, &r, &val);
            modify(1, l, r, val);
        } else {
            scanf("%d%d", &l, &r);
            printf("%lld\n", query(1, l, r));
        }
    }
    return 0;
}