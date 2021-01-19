#include <cstdio>
#include <algorithm>

#define re register
#define rep(i, a, b) for(re int i = (a); i <= (b); ++ i)

const int N = 1e6 + 5;
int a[N], d[N];

int main() {
    int n, len = 1;
    scanf("%d", &n); rep(i, 1, n) scanf("%d",&a[i]);
    d[1] = a[1]; rep(i, 2, n) {
        if(d[len] < a[i]) d[++ len] = a[i];
        else *std::lower_bound(d + 1 , d + 1 + len , a[i]) = a[i];
    } printf("%d",len); return 0;
}