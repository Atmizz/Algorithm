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
const int MaxN = 2e4 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m, q, pa[MaxN];
int Find(int x) {
  return x == pa[x] ? pa[x] : pa[x] = Find(pa[x]);
}
int main() {
  n = read(); m = read();
  for(int i = 1; i <= n; ++ i) pa[i] = i;
  for(int i = 1; i <= m; ++ i) {
    int a = read(), b = read();
    a = Find(a); b = Find(b);
    pa[a] = b;
  } q = read();
  while(q --) {
    int u = read(), v = read();
    u = Find(u), v = Find(v);
    printf(u == v ? "Yes\n" : "No\n");
  }
  return 0;
}