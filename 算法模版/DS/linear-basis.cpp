#include <cstdio>

#define re register
#define Rep(i, a, b) for(re int i = (a); i < (b); ++ i)
#define down(i, a) for(re int i = (a); ~i; -- i)

typedef unsigned long long ull;
const int N = 63;

ull p[N + 5];

inline void ins(ull x){
    down(i, N) if((x >> i) & 1){
	if(!p[i]){
	    p[i] = x;
	    return ;
	}
	x ^= p[i];
    } return ;
}

ull query(ull x) {
    ull res = x; down(i, N)
        if((res ^ p[i]) > res)
            res ^= p[i];
    return res;
}

int n; ull x; 

int main() {
    scanf("%d", &n);
    Rep(i, 0, n) scanf("%llu", &x), ins(x);
    printf("%llu\n", query(0));
    return 0;
}
