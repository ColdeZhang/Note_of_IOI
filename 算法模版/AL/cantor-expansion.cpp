#include <cstdio>

#define re register
#define rep(i, a, b) for(re int i = (a); i <= (b); ++ i)
#define down(i, a) for(re int i = (a); i; -- i)
#define bitpre(i, a) for(re int i = (a); i; i -= (i & -i))
#define bitsuf(i, a, b) for(re int i = (a); i <= (b); i += (i & -i))

const int N = 1e6 + 5;
const int mod = 998244353;

int n, a[N], c[N];

int main() {
	scanf("%d", &n); re int fac = 1, ans = 1;
	down(i, n) scanf("%d",&a[i]); rep(i, 1, n)  {
        re int s = 0; bitpre(j, a[i]) s += c[j];
        ans = ( ans + 1ll * fac * s ) % mod, 
		fac = 1ll * fac * i % mod;
		bitsuf(j, a[i], n) ++ c[j];
    } printf("%d", ans); return 0;
}
