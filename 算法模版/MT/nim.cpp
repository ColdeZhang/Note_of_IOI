#include <cstdio>
#define re register
#define Rep(i, a, b) for(re int i = (a); i < (b); ++ i)
#define rep(i, a, b) for(re int i = (a); i <= (b); ++ i)
int T, n; int main() {
    scanf("%d", &T); Rep(i, 0, T) {
        scanf("%d", &n); int ans = 0; 
        re int x; rep(i, 1, n) scanf("%d", &x), ans ^= x;
        puts(ans ? "Yes" : "No");
    } return 0;
}
