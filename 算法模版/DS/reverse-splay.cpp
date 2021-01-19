#include<cstdio>
#include<algorithm>

#define re register
#define rep(i, a, b) for(re int i = (a); i <= (b); ++ i)

const int N = 100005, INF = 0x7fffffff;

int rt, tot, ori[N], tag[N], val[N], fa[N], ch[N][2], sz[N];

struct Splay {
    static inline void upd(int x) { sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + 1; }
    static inline bool get(int x) { return x == ch[fa[x]][1]; }
    static inline void pd(int x){
        if(x && tag[x]){
            tag[ch[x][1]] ^= 1, tag[ch[x][0]] ^= 1;
            std::swap(ch[x][1], ch[x][0]), tag[x] = 0;
        }
    }
    static inline int build(int l, int r, int f){
        if(l > r){return 0;}
        int mid = (l + r) >> 1, cur = ++ tot;
        fa[cur] = f, ch[cur][0] = ch[cur][1] = 0;
        val[cur] = ori[mid], sz[cur] ++;
        ch[cur][0] = build(l, mid - 1, cur);
        ch[cur][1] = build(mid + 1, r, cur);
        upd(cur); return cur;
    }
    static inline void rotate(int x) {
        int y = fa[x], z = fa[y], chk = get(x); 
        pd(x), pd(y), ch[y][chk] = ch[x][chk ^ 1],
        fa[ch[x][chk ^ 1]] = y, ch[x][chk ^ 1] = y;
        if (z) ch[z][y == ch[z][1]] = x;
        fa[y] = x, fa[x] = z, upd(y), upd(x);
    }
    static inline void splay(int x, int goal) {
        for (int f = fa[x]; (f = fa[x]) != goal; rotate(x))
            if(fa[f] != goal) rotate(get(x) == get(f) ? f : x);
        if(!goal) rt = x;
    }
    static inline int kth(int k) {
        int cur = rt;
        while (1) {
            pd(cur);
            if (ch[cur][0] && k <= sz[ch[cur][0]])
                cur = ch[cur][0];
            else {
                k -= sz[ch[cur][0]] + 1;
                if (k <= 0) return cur;
                cur = ch[cur][1];
            }
        }
    }
    static inline void rev(int L, int R){
        int l = L - 1, r = R + 1;
        l = kth(l), r = kth(r);
        splay(l, 0), splay(r, l);
        tag[ch[ch[rt][1]][0]] ^= 1;
        return ;
    }
    void dfs(int cur){
        if(!cur) return ;
        pd(cur), dfs(ch[cur][0]);
        if(val[cur] != INF && val[cur] != -INF) 
            printf("%d ", val[cur]);
        dfs(ch[cur][1]);
        return ;
    }
} tr;

int main() {
    int n, m; scanf("%d%d", &n, &m);
    ori[1] = INF, ori[n + 2] = -INF;
    rep(i, 1, n) ori[i + 1] = i;
    rt = tr.build(1, n + 2, 0);
    int x, y; rep(i, 1, m){
        scanf("%d%d", &x, &y);
        tr.rev(x + 1, y + 1);
    } tr.dfs(rt); return 0;
}