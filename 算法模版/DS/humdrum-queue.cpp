#include <cstdio>
#include <queue>

#define re register
#define rep(i, a, b) for(re int i = (a); i <= (b); ++ i)

const int MAXN = 1e6 + 5;
int n, k, a[MAXN];
struct NODE{ int val, pos; };
std::deque<NODE> q;

void MAX(){
    q.clear(); rep(i, 1, n){
        while(!q.empty() && q.back().val <= a[i]) 
            q.pop_back();
        q.push_back((NODE){a[i], i});
        while(q.front().pos <= i - k) 
            q.pop_front();
        if(i >= k) printf("%d ", q.front().val);
    } puts(""); return ;
}

void MIN(){
    q.clear(); rep(i, 1, n){
        while(!q.empty() && q.back().val >= a[i]) 
            q.pop_back();
        q.push_back((NODE){a[i], i});
        while(q.front().pos <= i - k) 
            q.pop_front();
        if(i >= k)  printf("%d ", q.front().val);
    } puts(""); return ; 
}

int main(){
    scanf("%d%d",&n,&k);
    rep(i, 1, n) scanf("%d",&a[i]);
    MIN(), MAX(); return 0;
}
