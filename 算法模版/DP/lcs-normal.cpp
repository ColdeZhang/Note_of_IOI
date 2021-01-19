#include <cstdio>
#include <cstring>

#define re register
#define rep(i, a, b) for(re int i = (a); i <= (b); ++ i)

const int N = 1e4 + 5;

static inline int max(int a, int b) {
    return a > b ? a : b;
}

int n, m, tmp;
char a[N], b[N];
int f[2][N];

int main() {
    scanf("%s",a + 1); n = strlen(a + 1);
    scanf("%s",b + 1); m = strlen(b + 1);
    int now = 0; rep(i, 0, n) {
        now ^= 1; rep(j, 1, m) {
            f[now][j] = max(f[now ^ 1][j],f[now][j - 1]);
            tmp = f[now ^ 1][j - 1] + 1;
            if(a[i] == b[j] && f[now][j] < tmp) f[now][j] = tmp;
        }
    } printf("%d",f[now][m]); return 0;
}