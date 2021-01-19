#include <cstdio>
#include <ctime>
#include <cstdlib>

typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;

#define re register
#define Rep(i, a, b) for(re int i = (a); i <  (b); ++ i)

inline ll mul(ull x,ull y,ll p){
    return (x * y - (ull)((ldb)x / p * y) * p + p) % p;
}
inline ll qpow(ll x, ll k, ll p){
    re ll ans = 1;
    for(; k; k >>= 1, x = mul(x, x, p))
    	if(k & 1) ans = mul(ans, x, p);
    return ans;
}

static inline bool MR(ll n, int repeat){
    if(n == 2 || n == 3) return true;
    if(!(n & 1) || n == 1) return false;
    re ll d = n - 1; re int s = 0;
    while(!(d & 1)) ++ s, d >>= 1;
    srand((unsigned)time(NULL));
    Rep(i, 0, repeat){
        re ll a = rand() % (n - 2) + 2, x = qpow(a, d, n), y;
        if(x == 1 || x == n-1) continue;
        Rep(j, 0, s){
            y = mul(x, x, n);
            if(y == 1 && x != 1 && x != (n - 1))
                return false;
            x = y;
        } if(y != 1) return false;
    } return true;
}

static inline ll abs(ll x){return x < 0 ? -x : x;}
static inline void upmax(ll a, ll b) { if(a < b) a = b; return ; }
static inline ll func(ll x, ll c, ll p){return (mul(x, x, p) + c) % p;}
static inline ll gcd(ll a,ll b){
    if(!a) return b; if(!b) return a;
    re int t = __builtin_ctzll(a | b);
    a >>= __builtin_ctzll(a);
    do{
        b >>= __builtin_ctzll(b);
        if(a > b){ll t = b; b = a, a = t;}
        b -= a;
    }while(b);
    return a << t;
}

static inline ll PR(ll p){
    if(!(p & 1ll)) return 2ll;
    if(!(p % 3ll)) return 3ll;
    re ll x, y, z, c; ll i, j;
    while(1) {
        y = x = rand() % p;
        z = 1, c = rand() % p;
        i = 0, j = 1;
        while(++ i){
            x = func(x, c, p);
            z = mul(z, abs(y - x), p);
            if(!z) break;
            if(!(i % 127) || i == j){
                ll d = gcd(z, p);
                if(d > 1) return d;
                if(i == j)
                    y = x, j <<= 1;
    }   }   }
}

ll MAX = 0;

static inline void fac(ll x){
    if(x < 2) return ;
    if(x < MAX) return ;
    if(MR(x, 10)) upmax(MAX, x);
    else{
        re ll val = PR(x);
        while(x == val) val = PR(x);
        fac(val), fac(x / val);
    }
    return ;
}

int T;

int main(){
    scanf("%d", &T);
    srand(time(NULL));
    re ll x; while(T --){
        scanf("%lld", &x);
        if(MR(x, 10)) puts("Prime");
        else{
            fac(x); printf("%lld\n", MAX);
            MAX = 0;
        }
    } return 0;
}