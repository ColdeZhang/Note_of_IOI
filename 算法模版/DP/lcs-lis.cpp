#include <cstdio>
#include <algorithm>

#define re register
#define Rep(i, a, b) for(re int i = (a); i < (b); ++ i)

const int N = 1e6 + 5;

int a[N], b[N];
int d[N], stack[N], len;
int main() {
    int n; scanf("%d",&n);
    Rep(i, 0, n) {
        scanf("%d",&a[i]);
        d[a[i]] = i + 1;
    } Rep(i, 0, n)  {
        scanf("%d",&b[i]);
        b[i] = d[b[i]];
    } stack[1] = b[0], len = 1;
    Rep(i, 0, n) {
        if(stack[len] < b[i]) stack[++ len] = b[i];
        else *std::upper_bound(stack + 1,stack + 1 + len,b[i]) = b[i];
    } printf("%d",len); return 0;
}