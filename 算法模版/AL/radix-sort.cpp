#include <cstdio>

#define re register
#define Rep(i, a, b) for(re int i = (a); i < (b); ++ i)
#define Down(i, a) for(re int i = (a) - 1; ~i; -- i)

const int N = 1e5 + 5;
int n, cnt[4][0x100], b[N], a[N];

static inline void sort() {
    Rep(i, 0, n)
        ++ cnt[0][(a[i]      ) & 0xff],
        ++ cnt[1][(a[i] >>  8) & 0xff],
        ++ cnt[2][(a[i] >> 16) & 0xff],
        ++ cnt[3][(a[i] >> 24) & 0xff];

    Rep(i, 1, 0x100)
        cnt[0][i] += cnt[0][i - 1],
        cnt[1][i] += cnt[1][i - 1],
        cnt[2][i] += cnt[2][i - 1],
        cnt[3][i] += cnt[3][i - 1];

    Down(i, n)
        b[-- cnt[0][(a[i]      ) & 0xff]] = a[i];
    Down(i, n)
        a[-- cnt[1][(b[i] >>  8) & 0xff]] = b[i];
    Down(i, n)
        b[-- cnt[2][(a[i] >> 16) & 0xff]] = a[i];
    Down(i, n)
        a[-- cnt[3][(b[i] >> 24) & 0xff]] = b[i];
}

int main() {
	scanf("%d", &n);
	Rep(i, 0, n) scanf("%d", &a[i]);
	sort(); 
	Rep(i, 0, n) printf("%d ", a[i]);
	return 0;
}
