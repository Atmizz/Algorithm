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
const int MaxN = 1e4 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, k;
std :: unordered_set <int> s[60];
int main() {
  n = read();
  for(int i = 1; i <= n; ++ i) {
    int x = read();
    for(int j = 1; j <= x; ++ j)
      s[i].insert(read());
  }
  k = read();
  for(int i = 1; i <= k; ++ i) {
    int u = read(), v = read();
    double nc = 0;
    for(auto x : s[v])
      if(s[u].count(x)) nc ++;
    printf("%.2lf%%\n", nc * 100.00 / (s[u].size() + s[v].size() - nc));
  }
  return 0;
}