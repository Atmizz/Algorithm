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
const int MaxN = 5e3 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int m, n, p[MaxN], f[MaxN], ans;
int main() {
  m = read(); n = read();
  for(int i = 1; i <= n; ++ i) p[i] = read();
  std :: vector <std :: vector <int> > v(n, std :: vector <int>(m));
  for(int i = 1; i <= m; ++ i)
    for(int j = 1; j <= n; ++ j)
      v[j].push_back(read());
  std :: sort(v.begin(), v.end());
  for(int i = 1; i <= n; ++ i) {
    f[i] = p[i];
    for(int j = 1; j < i; ++ j)
      f[i] = max(f[i], f[j] + p[i]);
    ans = max(ans, f[i]);
  }
  printf("%d", ans);
  return 0;
}