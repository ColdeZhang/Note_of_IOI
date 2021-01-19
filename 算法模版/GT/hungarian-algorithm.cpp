#include<cctype>
#include<cstdio>
using namespace std;
typedef long long ll;
typedef long double ldb;
const int MAXBUF = 2097152;
const int PRINTBUF = 1966080;
#define Finline __inline__ __attribute__ ((always_inline))
char READ_BUF[MAXBUF],*READ_SIZE=READ_BUF,*READ_FLUSH_SIZE=READ_BUF;
Finline ll GETC()
{
    return READ_SIZE == READ_FLUSH_SIZE && (READ_FLUSH_SIZE = (READ_SIZE = READ_BUF) + 
    fread(READ_BUF,1,MAXBUF,stdin),READ_SIZE == READ_FLUSH_SIZE) ? EOF : *READ_SIZE ++;
}
inline ll rd()
{
    ll ret = 0,f = 0;char ch = GETC();
    while(!isdigit(ch)){if(ch == '-') f = 1;ch = GETC();}
    while(isdigit(ch)){ret = ret * 10 + ch - 48;ch = GETC();}
    return f?-ret:ret;
}
char WRITE_BUF[MAXBUF],PRINT_BUF[20];ll PRINT_FLUSH_SIZE,PRINT_SIZE=-1;
inline void flush(){fwrite(WRITE_BUF,1,PRINT_SIZE+1,stdout),PRINT_SIZE=-1;}
inline void write(ll x)
{
    if(PRINT_SIZE > PRINTBUF) flush();
    if(x<0) WRITE_BUF[++ PRINT_SIZE]=45,x = -x;
    do{PRINT_BUF[++ PRINT_FLUSH_SIZE] = x % 10 + 48;}while(x/=10);
    do{WRITE_BUF[++PRINT_SIZE] = PRINT_BUF[PRINT_FLUSH_SIZE];}while(--PRINT_FLUSH_SIZE);
}
#define file(FILE_NAME) freopen(FILE_NAME".in","r",stdin),freopen(FILE_NAME".out","w",stdout)
#define file_close fclose(stdin),fclose(stdout)

#define re register
#define rep(i, a, b) for(re int i = (a); i <= (b); ++ i)
#define fwd(i, u) for(re int i = head[(u)]; i; i = e[i].nxt)

const int MAXN = 1e3 + 5;
const int MAXM = 1e6 + 5;
int n, m, E, cnt, head[MAXN], dfn[MAXN], mch[MAXN];
struct EDGE { int to, nxt; } e[MAXM];
static inline void add(int u, int v) {
    e[++ cnt] = (EDGE){ v, head[u] };
    head[u] = cnt; return ;
}
bool dfs(int u, int tim) {
    fwd(i, u) {
        re int v = e[i].to;
        if (dfn[v] != tim) {
            dfn[v] = tim;
            if (!mch[v] || dfs(mch[v], tim)) {
                mch[v] = u; return true;
            }
        }
    }
    return false;
}
int main() {
    n = rd(), m = rd(), E = rd();
    rep(i, 1, E) {
        int u = rd(), v = rd();
        if (u > n || v > m)
            continue; add(u, v);
    } int ans = 0; rep(i, 1, n) 
        if (dfs(i, i)) ++ ans;
    write(ans), flush(); return 0;
}
