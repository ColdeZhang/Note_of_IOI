#include <cstdio>

#define re register
#define rep(i, a, b) for(re int i = (a); i <= (b); ++ i)

const int N = 1e6 + 5;

static inline void upmax(int &a, int b) {
    if(a < b) a = b; return ;
}

int n, ans, f[N];
struct Node{ int val, num; }z[N];
inline void modify(int x, int val) {
    while(x < N) {
        upmax(f[x], val);
        x += x & -x;
    } return ;
}
inline int query(int x) {
	int res = 0; while(x) {
        upmax(res, f[x]);
        x -= x & -x;
    } return res;
} 
int main()
{
	scanf("%d",&n); rep(i, 1, n) scanf("%d",&z[i].val);
    rep(i, 1, n) {
		int Max = query(z[i].val - 1);
		modify(z[i].val , ++ Max);
		upmax(ans,Max);
	} printf("%d",ans); return 0;
}