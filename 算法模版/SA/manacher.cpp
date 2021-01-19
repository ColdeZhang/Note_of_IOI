#include <cstdio>

const int N = 3e7 + 5;

char data[N]; int p[N], cnt, ans;

#define re register
#define rep(i, a, b) for(re int i = (a); i <= (b); ++ i)
static inline int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    char c = getchar(); data[0] = '!', data[cnt = 1] = '|';
    while (c < 'a' || c > 'z') c = getchar(); 
    while (c >= 'a' && c <= 'z') 
        data[++ cnt] = c, data[++ cnt] = '|', c = getchar();
    int r = 0,mid = 0;
    for (int t = 1;t <= cnt;t ++) {
        if(t <= r) p[t] = min(p[(mid << 1) - t],r - t + 1);
        while(data[t - p[t]] == data[t + p[t]]) ++ p[t];
        if(p[t] + t > r) r = p[t] + t - 1,mid = t;
        if(p[t] > ans) ans = p[t];
    } printf("%d\n", ans - 1); return 0;
}