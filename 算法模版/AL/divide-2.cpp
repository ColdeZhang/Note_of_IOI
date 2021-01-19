#include <cstdio>

#define re register
#define rep(i, a, b) for(re int i = (a); i <= (b); ++ i)

static inline int rd() {
    re int res = 0; char c = getchar(); 
    while (c < 48 || c > 57) c = getchar();
    while (c >= 48 && c <= 57) res = res * 10 + c - 48, c = getchar();
    return res; 
}

const int N = 1e6 + 5;
const int INF = 0x3f3f3f3f;

int n, m, cnt;
struct QUERY {
    int l, r, k, pos, opt; 
} q[N], q1[N], q2[N];

int ans[N], c[N];

static inline void add(int x, int val) {
    while (x <= n) c[x] += val, x += x & -x;
    return ;
}

static inline int ask(int x) {
    re int res = 0; while (x)
        res += c[x], x -= x & -x; 
    return res; 
}

void solve(int l, int r, int ql, int qr) {
    if (l > r || ql > qr) return ;
    if (l == r) {
        rep(i, ql, qr) if (q[i].opt)
            ans[q[i].pos] = l; 
        return ;
    } int cnt1 = 0, cnt2 = 0, mid = (l + r) >> 1;
    rep(i, ql, qr) if (q[i].opt) {
        re int tmp = ask(q[i].r) - ask(q[i].l - 1);
        if (q[i].k <= tmp) q1[++ cnt1] = q[i];
        else q[i].k -= tmp, q2[++ cnt2] = q[i];
    } else {
        if (q[i].l <= mid) add(q[i].pos, q[i].k), q1[++ cnt1] = q[i];
        else q2[++ cnt2] = q[i];
    } rep(i, 1, cnt1) if (!q1[i].opt) add(q1[i].pos, -q1[i].k);
    rep(i, 1, cnt1) q[ql + i - 1] = q1[i];
    rep(i, 1, cnt2) q[ql + cnt1 + i - 1] = q2[i];
    solve(l, mid, ql, ql + cnt1 - 1), 
    solve(mid + 1, r, ql + cnt1, qr); 
}

int a[N];

int main() {
    n = rd(), m = rd();
    rep(i, 1, n) a[i] = rd(), q[++ cnt] = (QUERY){a[i], 0, 1, i, 0};
    int tot = 0; rep(i, 1, m) {
        char c = getchar(); while (c != 'Q' && c != 'C') 
            c = getchar();
        int x = rd(), y = rd(), z; 
        if (c == 'C') q[++ cnt] = (QUERY){ a[x], 0, -1, x, 0 },
            q[++ cnt] = (QUERY){ a[x] = y, 0, 1, x, 0 };
        else z = rd(), q[++ cnt] = (QUERY) { x, y, z, ++ tot, 1 };
    } solve(-INF, INF, 1, cnt);
    rep(i, 1, tot) printf("%d\n", ans[i]);
    return 0;
}
