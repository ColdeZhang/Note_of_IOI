#include <cstdio>
#include <cstring>

#define re register

const int N = 1e6 + 5;

char s[N], p[N];
int nxt[N], lens, lenp;

static inline void compute() {
    nxt[0] = nxt[1] = 0;
    for(re int k = 0, i = 1; i < lenp; ++ i) {
        while(k && p[i] != p[k]) 
            k = nxt[k];
        if(p[i] == p[k]) ++ k;
        nxt[i + 1] = k;
    } return ;
}

static inline void compare() {
    for(re int i = 0, j = 0; j < lens; ++ j) {
        while(i && s[j] != p[i])
            i = nxt[i];
        if(s[j] == p[i]) ++ i;
        if(i == lenp) printf("%d\n", j - lenp + 2); 
    } return; 
}

static inline void output() {
    for(re int i = 1; i <= lenp; ++ i)
        printf("%d ", nxt[i]);
    return ;
}

int main() {
    scanf("%s%s", s, p), 
    lens = strlen(s), lenp = strlen(p);
    compute(), compare(), output(); 
    return 0;
}