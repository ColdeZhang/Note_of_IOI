#include<cstdio>
#include<cstring>

typedef long long ll;
#define re register
#define rep(i, a, b) for(re int (i) = (a); (i) <= (b); ++ (i))
#define mst(a, b) memset((a), (b), sizeof((a)))

using namespace std;

const int N = 25;
ll a, b, f[N][N], cnt, p[N];
template <typename T>
extern inline T abs(T x){ return x < 0 ? -x : x; }

inline ll dfs(int pos,int lst,bool lim1,bool lim2) {
    if(!pos) return 1;
    if(!lim2 && !lim1 && f[pos][lst] != -1) 
		return f[pos][lst];
    int op, up = lim1 ? p[pos] : 9;
    ll tmp = 0; rep(i, 0, up){
        if(abs(i - lst) < 2) continue;
        op = i; if(lim2 && !i) op = -2;
        tmp += dfs(pos - 1, op, (lim1) && (i == up), (op == -2));
    } if(!lim1 && !lim2) f[pos][lst] = tmp;
    return tmp;
}
inline ll solve(ll x) {
    cnt = 0; while(x) p[++ cnt] = x % 10, x /= 10;
    return dfs(cnt, -2, 1, 1);
}
int main() {
	scanf("%d%d", &a, &b); mst(f, -1);
    printf("%lld\n",solve(b) - solve(a - 1));
    return 0;
}
