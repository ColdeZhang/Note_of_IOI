#include <cstdio>

typedef long long ll;

#define re register
const ll N = 2e5 + 5;
const ll SGT = N << 5;
const ll mod = 19831205ll;

ll rt, ind;
ll ls[SGT], rs[SGT];
ll sum[SGT], tag[SGT];

static inline void pd(ll p, ll l, ll r) {
	if(!tag[p]) return;  re ll mid = (l + r) >> 1;
	if(!ls[p]) ls[p] = ++ ind; sum[ls[p]] = tag[p] * (mid - l + 1);
	if(!rs[p]) rs[p] = ++ ind; sum[rs[p]] = tag[p] * (r - mid);
	tag[ls[p]] = tag[rs[p]] = tag[p]; tag[p] = 0; return;
}

void modify(ll &p, ll l, ll r, ll L, ll R, ll x) {
	if(l > R || r < L) return; if(!p) p = ++ ind;
	if(L <= l && r <= R) { tag[p] = x; sum[p] = x * (r - l + 1); return; }
	pd(p, l, r); re ll mid = (l + r) >> 1;
	modify(ls[p], l, mid, L, R, x), modify(rs[p], mid + 1, r, L, R, x);
	sum[p] = (sum[ls[p]] + sum[rs[p]]) % mod; return;
}

ll query(ll p,ll l,ll r,ll L,ll R) {
	if(!p || l > R || r < L) return 0;
	if(l >= L && r <= R) return sum[p];
	pd(p, l, r); re ll mid = (l + r) >> 1;
	return (query(ls[p], l, mid, L, R) + query(rs[p], mid + 1, r, L, R)) % mod;
}

ll n, m;

int main() {
    scanf("%lld%lld", &n, &m);
	re ll opt, l, r, x; while(m --) {
		scanf("%lld%lld%lld", &opt, &l, &r); 
		if(opt < 2) scanf("%lld", &x), modify(rt, 1, n, l, r, x);
		else printf("%lld\n", query(rt, 1, n, l, r));
	} return 0;
}