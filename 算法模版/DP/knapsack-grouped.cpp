#include <cstdio>

#define re register
#define rep(i, a, b) for(re int i = (a); i <= (b); ++ i)
#define Rep(i, a, b) for(re int i = (a); i <  (b); ++ i)
#define drep(i, a, b) for(re int i = (a); i >= (b); -- i)

const int C = 1e6 + 5;

static inline void upmax(int &a, int b){
    if(a < b) a = b; return ;
}

int n, V, f[C];

int main() {
    scanf("%d%d", &n, &V);
    rep(k, 1, n) {
        re int cnt; scanf("%d", &cnt);
        drep(i, V, 0) rep(j, 1, cnt) { 
            re int w, c; scanf("%d%d", &w, &c);
            if (i >= w) upmax(f[i], f[i - w] + c);
        }
    } printf("%d\n", f[V]); return 0;
}