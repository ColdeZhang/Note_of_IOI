#include <cstdio>

#define re register
#define rep(i, a, b) for(re int i = (a); i <= (b); ++ i)
#define Rep(i, a, b) for(re int i = (a); i <  (b); ++ i)

const int N = 1e4 + 5;

int fa[N], sz[N], n, m;

static inline void swap(int &a, int &b) {
    int t = a; a = b, b = t; return ;
}

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

static inline bool check(int x, int y){
    return find(x) == find(y);
}

static inline void merge(int x, int y){
    re int fx = find(x), fy = find(y);
    if(fx == fy) return ;
    if(sz[fx] > sz[fy]) swap(fx, fy);
    fa[fx] = fy, sz[fy] += sz[fx]; return ;
}

int main() {
    scanf("%d%d", &n, &m);
    rep(i, 1, n) sz[fa[i] = i] = 1;
    re int opt, x, y; while(m --) {
        scanf("%d%d%d", &opt, &x, &y); 
        if(opt == 1) merge(x, y);
        else puts(check(x, y) ? "Y" : "N");
    } return 0;
}