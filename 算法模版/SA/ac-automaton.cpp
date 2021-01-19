#include <cstdio>
#include <queue>
#include <cstring>

#define re register
#define rep(i, a, b) for(re int i = (a); i <= (b); ++ i)
#define Rep(i, a, b) for(re int i = (a); i <  (b); ++ i)

const int N = 1e6 + 5;
char s[N];
int n, ind, fail[N], val[N], c[N][26];
static inline void ins() {
    int len = strlen(s), cur = 0;
    Rep(i, 0, len) {
        int v = s[i] - 'a';
        if(!c[cur][v]) c[cur][v] = ++ ind;
        cur = c[cur][v];
    } val[cur] ++; return ;
}
std::queue<int> q;
static inline void build() {
    Rep(i, 0, 26) if(c[0][i])
        fail[c[0][i]] = 0,
        q.push(c[0][i]);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        Rep(i, 0, 26) if(c[u][i])
            fail[c[u][i]] = c[fail[u]][i],
            q.push(c[u][i]);
        else c[u][i] = c[fail[u]][i];
    } return ;
}
static inline int query() {
    int len = strlen(s), cur = 0, ans = 0;
    Rep(i, 0, len) {
        cur = c[cur][s[i] - 'a'];
        for(int t = cur; t && ~val[t]; t = fail[t])
            ans += val[t],val[t] = -1;
    } return ans;
}
int main() {
    scanf("%d",&n); while(n --) scanf("%s",s), ins();
    build(), scanf("%s",s), printf("%d\n", query());
    return 0;
}