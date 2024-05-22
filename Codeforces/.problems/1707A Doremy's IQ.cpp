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
const int MaxN = 1e5 + 20;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int T, n, q, a[MaxN], b[MaxN];
int main() {
  T = read();
  while(T --) {
    n = read(); q = read(); 
    for(int i = 1; i <= n; ++ i) a[i] = read();
    int iq = 0;
    for(int i = n; i >= 1; -- i) {
      if(a[i] <= iq) b[i] = 1;
      else if(iq < q) iq ++, b[i] = 1;
      else b[i] = 0;
    }
    for(int i = 1; i <= n; ++ i) std :: cout << b[i];
    puts("");
  }
  return 0;
}