#include<cstdio>
#define re register
#define rep(i, a, b) for(re int i = (a); i <= (b); ++ i)
#define Rep(i, a, b) for(re int i = (a); i <  (b); ++ i)
const int N = 1e4 + 5;
int a[N], b[N], f[N], pos[N];
void output(int x) {
    if(!x) return;
    output(pos[x]);
    printf("%d ",b[x]);
}
int main() {
    int n, m, Max = 0; scanf("%d",&n);
    rep(i, 1, n) scanf("%d",&a[i]);
    scanf("%d", &m); rep(i, 1, m) scanf("%d",&b[i]);
    rep(i, 1, n) {
        re int t = 0; rep(j, 1, m) {
            if(a[i] == b[j]) f[j] = f[t] + 1, pos[j] = t;
            if(a[i] > b[j] && f[t] < f[j]) t = j;
        }
    }
    rep(i, 1, m) if(f[i] > f[Max]) Max = i;
    printf("%d\n",f[Max]); output(Max); return 0;
}