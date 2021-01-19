#include <cstdio>

void exgcd(int a, int b, int &x, int &y) {
    if(!b) { x = 1, y = 0; return ; }
    exgcd(b, a % b, y, x); 
    y -= x * (a / b); return ;
}

static inline int inv(int num, int p) {
    int x, y; exgcd(num, p, x, y);
    x = ((x % p) + p) % p;
    return x;
}

int main() {
    int n, p; scanf("%d%d", &n, &p);
    printf("%d\n", inv(n, p)); return 0;
}