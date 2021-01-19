#include <cstdio>

#define re register
#define rep(i, a, b) for(re int i = (a); i <= (b); ++ i)
#define Rep(i, a, b) for(re int i = (a); i <  (b); ++ i)

const int N = 1e7 + 5;

bool vis[N]; int prime[N], p;

static inline void euler(int lim) {
    rep(i, 2, lim) {
        if(!vis[i]) prime[++ p] = i;
        for(re int j = 1; j <= p && i * prime[j] <= lim; ++ j) {
            vis[i * prime[j]] = 1;
            if(!(i % prime[j])) 
                break;
        }
    }
    return ;
}

int n; 

int main() {
    scanf("%d", &n); euler(n);
    rep(i, 1, p) printf("%d\n", prime[i]);
    return 0;
}