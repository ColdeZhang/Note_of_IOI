#include<cstdio>

#define re register

const int N = 1e6 + 5;
struct SPLAY {
    int rt, tot, fa[N], ch[N][2], val[N], cnt[N], sz[N];
    inline void upd(int x) { sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + cnt[x]; }
    inline bool get(int x) { return x == ch[fa[x]][1]; }
    inline void clr(int x) { ch[x][0] = ch[x][1] = fa[x] = val[x] = sz[x] = cnt[x] = 0; }
    inline void rot(int x){
        int y = fa[x], z = fa[y], chk = get(x);
        ch[fa[ch[x][chk ^ 1]] = y][chk] = ch[x][chk ^ 1];
        fa[fa[ch[x][chk ^ 1] = y] = x] = z;
        if(z) ch[z][y == ch[z][1]] = x;
        upd(x), upd(y);
    }
    inline void splay(int x){
        for(re int f = fa[x]; f = fa[x], f; rot(x))
            if(fa[f]) rot(get(x) == get(f) ? f : x);
        rt = x;
    }
    inline void ins(int k){
        if(!rt) {
            val[++ tot] = k, cnt[tot] ++;
            upd(rt = tot); return ;
        }
        re int cur = rt, f = 0;
        while(1) {
            if(val[cur] == k){
                cnt[cur] ++, upd(cur), upd(f); 
                splay(cur); break;
            } f = cur, cur = ch[cur][val[cur] < k];
            if(!cur) {
                val[++ tot] = k, cnt[tot] ++;
                fa[tot] = f, ch[f][val[f] < k] = tot;
                upd(tot), upd(f), splay(tot); break;
            }
        }
    }
    inline int rk(int k){
        re int res = 0, cur = rt;
        while(1) {
            if(k < val[cur]) cur = ch[cur][0];
            else {
                res += sz[ch[cur][0]];
                if(k == val[cur]){
                    splay(cur); return res + 1;
                } res += cnt[cur];
                cur = ch[cur][1];
            }
        }
    }
    inline int kth(int k){
        int cur = rt;
        while(1) {
            if(ch[cur][0] && k <= sz[ch[cur][0]])
                cur = ch[cur][0];
            else  {
                k -= cnt[cur] + sz[ch[cur][0]];
                if(k <= 0) return val[cur];
                cur = ch[cur][1];
            }
        }
    }
    inline int nxt(){
        int cur = ch[rt][1]; 
        while(ch[cur][0]) cur = ch[cur][0];
        return cur;
    }
    inline int pre(){
        int cur = ch[rt][0];
        while(ch[cur][1]) cur = ch[cur][1];
        return cur;
    }
    inline void del(int k){
        rk(k); if(cnt[rt] > 1){
            cnt[rt] --; upd(rt); 
            return ;
        }
        if(!ch[rt][0] && !ch[rt][1]) {
            clr(rt), rt = 0; return ;
        }
        if(!ch[rt][0]){
            int cur = rt; rt = ch[rt][1];
            fa[rt] = 0; clr(cur); return ;
        }
        if(!ch[rt][1]){
            int cur = rt; rt = ch[rt][0];
            fa[rt] = 0; clr(cur); return ;
        }
        int x = pre(), cur = rt;
        splay(x); fa[ch[cur][1]] = x;
        ch[x][1] = ch[cur][1], clr(cur), upd(rt);
    }
}tr;

int main(){
    int n; scanf("%d", &n);  while(n --){
        re int opt, x; scanf("%d%d", &opt, &x);
        if(opt == 1) tr.ins(x);
        else if(opt == 2) tr.del(x); 
        else if(opt == 3) printf("%d\n", tr.rk(x));
        else if(opt == 4) printf("%d\n", tr.kth(x));
        else if(opt == 5) tr.ins(x), printf("%d\n", tr.val[tr.pre()]), tr.del(x);
        else tr.ins(x), printf("%d\n", tr.val[tr.nxt()]), tr.del(x);
    } return 0;
}