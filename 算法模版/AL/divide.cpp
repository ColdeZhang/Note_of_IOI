#include <cstdio>

#define re register
#define rep(i, a, b) for(re int i = (a); i <= (b); ++ i)
#define Rep(i, a, b) for(re int i = (a); i <  (b); ++ i)

const int N = 1e6 + 5;
const int INF = 0x3f3f3f3f;

int n, m, cnt, ans[N], c[N];

struct QUERY {
    int l, r, k, pos, opt; 
} q[N], q1[N], q2[N];

static inline void modify(int x, int val) {
    while (x <= n) c[x] += val, x += (x & -x); 
    return ;
}

static inline int query(int x) {
    int res = 0; while (x) {
        res += c[x]; 
        x -= (x & -x);
    } return res; 
}

void solve(int l, int r, int ql, int qr) {
    if (l > r || ql > qr) return ;
    if (l == r) {
        rep(i, ql, qr) if (q[i].opt) 
            ans[q[i].pos] = l;
        return ; 
    } int cnt1 = 0, cnt2 = 0, mid = (l + r) >> 1;
    rep(i, ql, qr) {
        if (!q[i].opt) {
            if (q[i].l <= mid) 
                modify(q[i].pos, q[i].k),
                q1[++ cnt1] = q[i];
            else q2[++ cnt2] = q[i];
        } else {
            int tmp = query(q[i].r) - query(q[i].l - 1);
            if (q[i].k <= tmp) q1[++ cnt1] = q[i];
            else q[i].k -= tmp, q2[++ cnt2] = q[i];
        }
    } rep(i, 1, cnt1) if (!q1[i].opt) modify(q1[i].pos, -q1[i].k);
    rep(i, 1, cnt1) q[ql + i - 1] = q1[i];
    rep(i, 1, cnt2) q[ql + cnt1 + i - 1] = q2[i];
    solve(l, mid, ql, ql + cnt1 - 1),
    solve(mid + 1, r, ql + cnt1, qr); 
    return ;
}

int main() {
    scanf("%d%d", &n, &m);
    int x; rep(i, 1, n) 
        scanf("%d", &x),
        q[++ cnt] = (QUERY){x, 0, 1, i, 0};
    int l, r, k; rep(i, 1, m) {
        scanf("%d%d%d", &l, &r, &k);
        q[++ cnt] = (QUERY){l, r, k, i, 1};
    } solve(-INF, INF, 1, cnt); 
    rep(i, 1, m) printf("%d\n", ans[i]);  
    return 0;
}