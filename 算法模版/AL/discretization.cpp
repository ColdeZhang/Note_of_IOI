#include <cstdio>
#include <algorithm>

#define re register
#define rep(i, a, b) for(re int i = (a); i <= (b); ++ i)
#define Rep(i, a, b) for(re int i = (a); i <  (b); ++ i)

const int N = 1e6 + 5;

int n, a[N], b[N]; 

int main() {
    //scanf("%d", &n); Rep(i, 0, n) scanf("%d", &a[i]), b[i] = a[i];
    //std::sort(b, b + n); int len = std::unique(b, b + n) - b;
    //Rep(i, 0, n) printf("%d\n", std::lower_bound(b, b + len, a[i]) - b);
    scanf("%d", &n); rep(i, 1, n) scanf("%d", &a[i]), b[i] = a[i];
    std::sort(b + 1, b + n + 1); int len = std::unique(b + 1, b + n + 1) - b - 1;
    rep(i, 1, n) printf("%d\n", std::lower_bound(b + 1, b + len + 1, a[i]) - b); 
    return 0;
}
