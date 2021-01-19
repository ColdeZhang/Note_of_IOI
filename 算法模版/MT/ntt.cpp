#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e7 + 5;
const ll MOD = 998244353;
const ll yg = 3;
const ll ygi = 332748118;

#define re register
#define rep(i, a, b) for(re int i = (a); i <= (b); ++ i)
#define Rep(i, a, b) for(re int i = (a); i <  (b); ++ i)
#define drep(i, a, b) for(re int i = (a); i >= (b); -- i)
#define dRep(i, a, b) for(re int i = (a) - 1; i >= (b); -- i)

#define Finline __inline__ __attribute__ ((always_inline))
Finline char get_char(){
    static char READBUF[200000001], *READP1 = READBUF, *READP2 = READBUF + fread(READBUF, 1, 200000000, stdin);
    return READP1 == READP2 ? EOF : *READP1 ++;
}

static inline int rd(){
    int num = 0; char c;
    while(!isdigit(c = get_char()));
    while(num = num * 10 + c - 48, isdigit(c = get_char()));
    return num;
}

static inline int ri(){
    char c;
    while(!isdigit(c = get_char()));
    return c - 48;
}

const int MAXWRITEBUF = 1e7 + 5;
char WRITEBUF[MAXWRITEBUF], WRITENUM[20];int WRITEP1, WRITEP2 = -1;
template <typename T>
static inline void wi(T x, char opt) {
    if(x < 0) WRITEBUF[++ WRITEP2] = 45, x = -x;
    do{WRITENUM[++ WRITEP1] = x % 10 + 48;}while(x/=10);
    do{WRITEBUF[++ WRITEP2] = WRITENUM[WRITEP1];}while(--WRITEP1);
    WRITEBUF[++ WRITEP2] = opt;
}

static inline int qpow(ll a, ll b) {
    re ll ans = 1;
    while(b){
        if(b & 1) 
            ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans;
}

ll a[N], b[N], eps[N];
int r[N];

static inline void init(int n){
    ll mi = 0; for(re int i = 2; i <= n; i <<= 1)
        eps[mi ++] = qpow(yg, (MOD - 1) / i);
}

static inline void NTT(int n, ll *x){
    Rep(i, 0, n) if(i < r[i]) swap(x[i], x[r[i]]);
    ll mi = 0; for(re int i = 2; i <= n; i <<= 1){
        int l = i >> 1; ll temp = eps[mi ++];
        for(re int j = 0; j < n; j += i){
            ll t = 1; for(re int k = 0; k < l; ++ k, t = (t * temp) % MOD){
                ll u = x[k + j], v = (t * x[k + j + l]) % MOD;
                x[k + j] = (u + v) % MOD;
                x[k + j + l] = (u - v + MOD) % MOD;
            }
        }
    }
}

int n, m;

int main(){
    n = rd() + 1, m = rd() + 1;
    Rep(i, 0, n) a[i] = ri();
    Rep(i, 0, m) b[i] = ri();
    int len = 1, mi = 0, lim = n + m;
    while(len < lim)
        ++ mi, len <<= 1;
    -- mi; rep(i, 0, len)
        r[i] = (r[i >> 1] >> 1) | ((i & 1) << mi);
    init(len), NTT(len, a), NTT(len, b);
    Rep(i, 0, len) a[i] = (a[i] * b[i]) % MOD;
    NTT(len, a), reverse(a + 1, a + len);
    ll inv = qpow(len, MOD - 2);
    Rep(i, 0, len) a[i] = (a[i] * inv) % MOD;
    -- lim; Rep(i, 0, lim) wi(a[i], ' ');
    fwrite(WRITEBUF, 1, WRITEP2 + 1, stdout);
    return 0;
}
