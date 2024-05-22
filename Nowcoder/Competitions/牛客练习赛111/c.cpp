#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define gc getchar()
typedef long long ll;
inline int read() {
  int s = 0, f = 1; char ch = gc;
  for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-') f = -1;
  for(; ch >= '0' && ch <= '9'; ch = gc)
    s = (s << 1) + (s << 3) + (ch ^ 48);
  return s * f;
}
inline int abs(int a) {return a < 0 ? -a : a;}
inline int min(int a, int b) {return a < b ? a : b;}
inline int max(int a, int b) {return a > b ? a : b;}
const int MaxN = 1e6 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
double x, m;
int T;
int main() {
  T = read();
  while(T --) {
    scanf("%lf %lf", &m, &x);
    double k1 = floor(m / x);
    double k2 = m / x;
    if(k2 != double(int(k2))) k2 = ceil(k2);
    else k2 ++;
    // std :: cout << "k : " << k1 << ' ' << k2 << '\n';
    double l1 = floor(m / k1);
    double l2 = m / k2;
    if(l2 != double(int(l2))) l2 = ceil(l2);
    else l2 ++;
    // std :: cout << "l : " << l1 << ' ' << l2 << '\n';
    printf("%.0lf\n", l1 - l2 + 1);
  }
  return 0;
}