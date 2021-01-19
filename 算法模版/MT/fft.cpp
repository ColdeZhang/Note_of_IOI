#include <cstdio>
#include <cctype> 
#include <cmath>
#include <algorithm>

#define re register
#define rep(i, a, b) for(re int i = (a); i <= (b); ++ i)
#define Rep(i, a, b) for(re int i = (a); i <  (b); ++ i)

typedef long long ll;
typedef double db;

const int MAXN = 4e6 + 5;
const db PI = acos(-1.0);

#define Finline __inline__ __attribute__ ((always_inline))
Finline char get_char(){
    static char READBUF[200000001], *READP1 = READBUF, *READP2 = READBUF + fread(READBUF, 1, 200000000, stdin);
    return READP1 == READP2 ? EOF : *READP1 ++;
}

static inline int rd(){
    char c;
    while(!isdigit(c = get_char()));
    return c - 48;
}

const int MAXWRITEBUF = 1e7 + 5;
char WRITEBUF[MAXWRITEBUF], WRITENUM[20];int WRITEP1, WRITEP2 = -1;
template <typename T>
static inline void wi(T x, char opt)  {
    if(x < 0) WRITEBUF[++ WRITEP2] = 45, x = -x;
    do{WRITENUM[++ WRITEP1] = x % 10 + 48;}while(x/=10);
    do{WRITEBUF[++ WRITEP2] = WRITENUM[WRITEP1];}while(--WRITEP1);
    WRITEBUF[++ WRITEP2] = opt;
}

struct Complex{
    db real, imag;
    Complex(db a = 0, db b = 0) : real(a), imag(b){}
    Complex(const Complex &a) : real(a.real), imag(a.imag){}
    Complex conj() const{
        return Complex(real, -imag);
    }
    Complex &operator=(const Complex &a){
        real = a.real, imag = a.imag; return *this;
    }
    Complex &operator+=(const Complex &a){
        real += a.real, imag += a.imag; return *this;
    }
    Complex &operator-=(const Complex &a){
        real -= a.real, imag -= a.imag; return *this;
    }
    Complex &operator*=(const Complex &a){
        db tmp1 = real * a.real - imag * a.imag;
        db tmp2 = real * a.imag + imag * a.real;
        real = tmp1, imag = tmp2;
        return *this;
    }
    Complex &operator/=(const Complex &a){
        db tmp1 = (real * a.real + imag * a.imag) / (a.real * a.real + a.imag * a.imag);
        db tmp2 = (imag * a.real - real * a.imag) / (a.real * a.real + a.imag * a.imag);
        real = tmp1, imag = tmp2;
        return *this;
    }
    friend Complex operator+(const Complex &a,const Complex &b){Complex c(a);return c+=b;}
    friend Complex operator-(const Complex &a,const Complex &b){Complex c(a);return c-=b;}
    friend Complex operator*(const Complex &a,const Complex &b){Complex c(a);return c*=b;}
    friend Complex operator/(const Complex &a,const Complex &b){Complex c(a);return c/=b;}
}eps[MAXN], a[MAXN], b[MAXN];

static inline void swap(Complex &a, Complex &b) {
    Complex t = a; a = b, b = t; return ; 
}

int r[MAXN];

void init(int n){
    int l = n >> 1;
    for(int i = 0; i < l; ++ i){
        eps[l + i].real = cos(i * PI / l),
        eps[l + i].imag = sin(i * PI / l);
    }
    while(l >>= 1)
        for(int i = 0; i < l; ++ i)
            eps[l + i] = eps[(l + i) << 1];
    return ;
}
void FFT(int n,Complex x[]){
    Rep(i, 0, n) if(i < r[i]) swap(x[i], x[r[i]]);
    for(re int i = 2; i <= n; i <<= 1){
        re int l = i >> 1;
        for(re int j = 0; j < n; j += i){
            for(re int k = 0; k < l; ++ k){
                Complex u = x[k + j], v = eps[l + k] * x[k + j + l];
                x[k + j] = u + v;
                x[k + j + l] = u - v;
            }
        }
    }
}
int n, m;
int main(){
    scanf("%d%d", &n, &m); ++ n, ++ m;
    Rep(i, 0, n) a[i].real = rd(); 
    Rep(i, 0, m) b[i].real = rd();
    int len = 1, mi = 0, lim = n + m;
    while(len < lim) ++ mi, len <<= 1; -- mi;
    rep(i, 0, len) r[i] = (r[i >> 1] >> 1) | ((i & 1) << mi);
    init(len), FFT(len, a), FFT(len, b);
    Rep(i, 0, len) a[i] *= b[i];
    std::reverse(a + 1, a + len);
    FFT(len, a); Rep(i, 0, len) a[i] /= len;
    -- lim; Rep(i, 0, lim)
        wi(static_cast<ll>(a[i].real + 0.5), ' ');
    fwrite(WRITEBUF, 1, WRITEP2 + 1, stdout);
    return 0;
}
