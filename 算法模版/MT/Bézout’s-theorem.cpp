#include <cstdio>
#define re register
#define rep(i, a, b) for(re int i = (a); i <= (b); ++ i)
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int main() {
    int n, g, a; scanf("%d", &n);
    scanf("%d", &a); if(a < 0) a = -a; 
    g = a; rep(i, 2, n) {
        scanf("%d", &a); 
        if(a < 0) a = -a;
        g = gcd(g, a);
    } printf("%d", g); return 0;
}
