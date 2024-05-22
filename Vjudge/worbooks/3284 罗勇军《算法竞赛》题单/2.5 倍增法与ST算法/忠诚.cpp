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
const int MaxN = 1e5 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int m, n, f[MaxN][22];
int query(int l, int r) {
  int k = std :: log2(r - l + 1);
  return min(f[l][k], f[r-(1<<k)+1][k]);
}
int main() {
  m = read(); n = read();
  memset(f, 0x3f, sizeof f);
  for(int i = 1; i <= m; ++ i) f[i][0] = read();
  for(int j = 1; j <= 20; ++ j)
    for(int i = 1; i + (1 << j) - 1 <= m; ++ i)
      f[i][j] = min(f[i][j-1], f[i+(1<<(j-1))][j-1]);
  std :: vector <int> ans;
  for(int i = 1; i <= n; ++ i) {
    int l = read(), r = read();
    ans.push_back(query(l, r));
  }
  for(auto x : ans) printf("%d ", x);
  return 0;
}