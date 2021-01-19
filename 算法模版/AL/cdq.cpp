#include<cstdio>
#include<cctype>
#include<algorithm>
using namespace std;

typedef long long ll;

#define rep(i, a, b) for(register int i = (a); i <= (b); ++ i)
#define Rep(i, a, b) for(register int i = (a); i <  (b); ++ i)
#define drep(i, a, b) for(register int i = (a); i >= (b); -- i)
#define dRep(i, a, b) for(register int i = (a) - 1; i >= (b); -- i)

#define Finline __inline__ __attribute__ ((always_inline))
Finline char get_char(){
    static char READBUF[200000001], *READP1 = READBUF, *READP2 = READBUF + fread(READBUF, 1, 200000000, stdin);
    return READP1 == READP2 ? EOF : *READP1 ++;
}
static inline int rd() {
    int num = 0; char c;
    while(!isdigit(c = get_char()));
    while(num = num * 10 + c - 48, isdigit(c = get_char()));
    return num;
}
const int MAXWRITEBUF = 1 << 21;
const int FLUSHSIZE = MAXWRITEBUF >> 1;
char WRITEBUF[MAXWRITEBUF], WRITENUM[20];int WRITEP1, WRITEP2 = -1;
template <typename T>
static inline void wi(T x, char opt)  {
    do{WRITENUM[++ WRITEP1] = x % 10 + 48;}while(x/=10);
    do{WRITEBUF[++ WRITEP2] = WRITENUM[WRITEP1];}while(--WRITEP1);
    WRITEBUF[++ WRITEP2] = opt;
}

const int N = 1e5 + 10;
struct NODE{
    int opt, val, d, id;
}e[N << 1];
int n , m, tot;
int pos[N], c[N];
ll ans[N];

inline bool cmp1(NODE x, NODE y){
    return x.d < y.d;
}
inline void add(int x, int k){
    while(x <= n)
        c[x] += k, 
        x += (x & (-x));
    return ;
}
inline int query(int x){
    int sum = 0;
    while(x)
        sum += c[x],
        x -= (x & (-x));
    return sum;
}
void radix_sort(int *l, int *r) {
    int cnt[4][0x100] = {}, b[r - l] = {}, *l1 = b, *r1 = &b[r - l];
    for (register int *i = l; i != r; ++i) {
        ++cnt[0][(*i      ) & 0xff];
        ++cnt[1][(*i >>  8) & 0xff];
        ++cnt[2][(*i >> 16) & 0xff];
        ++cnt[3][(*i >> 24) & 0xff];
    }
    for (register int i = 1; i < 0x100; ++i) {
        cnt[0][i] += cnt[0][i - 1];
        cnt[1][i] += cnt[1][i - 1];
        cnt[2][i] += cnt[2][i - 1];
        cnt[3][i] += cnt[3][i - 1];
    }
    for (register int *i = r; (i--) != l; )
        b[--cnt[0][(*i      ) & 0xff]] = *i;
    for (register int *i = r1; (i--) != l1; )
        l[--cnt[1][(*i >>  8) & 0xff]] = *i;
    for (register int *i = r; (i--) != l; )
        b[--cnt[2][(*i >> 16) & 0xff]] = *i;
    for (register int *i = r1; (i--) != l1; )
        l[--cnt[3][(*i >> 24) & 0xff]] = *i;
}
void cdq(int l, int r){
    if(l == r) return;
    int mid = (l + r) >> 1, j = l;
    cdq(l, mid), cdq(mid + 1, r);
    sort(e + l, e + mid + 1, cmp1);
    sort(e + mid + 1, e + r + 1, cmp1);
    rep(i, mid + 1, r){
        while(j <= mid && e[j].d <= e[i].d)
            add(e[j].val, e[j].opt), ++ j;
        ans[e[i].id] += e[i].opt * (query(n) - query(e[i].val));
    } Rep(i, l, j) add(e[i].val, -e[i].opt);
    j = mid; for(register int i = r; i > mid; -- i){
        while(j >= l && e[j].d >= e[i].d)
            add(e[j].val, e[j].opt), --j;
        ans[e[i].id] += e[i].opt * query(e[i].val - 1);
    } for(register int i = mid; i > j; -- i) 
        add(e[i].val, -e[i].opt);
    return ;
}
int main(){
    n = rd(), m = rd(); int x;
    rep(i, 1, n) pos[(x = rd())] = i, 
        e[++ tot] = (NODE){1, x, i, 0};
    rep(i, 1, m) x = rd(),
        e[++ tot] = (NODE){-1, x, pos[x], i};
    cdq(1, tot); rep(i, 1, m) ans[i] += ans[i - 1];
    Rep(i, 0, m) wi(ans[i], '\n');
    fwrite(WRITEBUF, 1, WRITEP2 + 1, stdout);
    return 0;
}
