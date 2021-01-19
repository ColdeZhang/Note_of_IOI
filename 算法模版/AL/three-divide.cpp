#include<cstdio>

#define re register
#define rep(i, a, b) for(re int i = (a); i <= (b); ++ i)
#define Down(i, a) for(re int i = (a); ~i; -- i)

typedef long double ldb;
typedef double db; 

const ldb eps = 1e-10;
const int N = 20;

db l, r, a[N]; int n;

inline db f(db x) {
    db u[N]; u[n] = a[n]; Down(i, n - 1)
        u[i] = u[i + 1] * x + a[i];
    return u[0];
}

static inline db check(db x) {
    db dx = eps, dy = f(x + dx) - f(x);
    return dy / dx;
}

int main() {
    scanf("%d%lf%lf",&n, &l, &r);
    rep(i, 0, n) scanf("%lf",&a[n - i]);
    db mid; while(r - l > eps) {
        mid = (l + r) / 2;
        if(check(mid) > 0) l = mid;
        else r = mid;
    } printf("%.5lf\n", mid); return 0;
}
