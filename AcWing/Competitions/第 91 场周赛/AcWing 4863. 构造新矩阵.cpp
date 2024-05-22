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
const int MaxN = 1e5 + 10;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int T, n, m;
std :: vector <int> g[MaxN];
bool vis[MaxN];
bool check(int k) {
  bool ans = false;
  for(int i = 0; i < m; ++ i) vis[i] = false;
  for(int i = 0; i < n; ++ i) {
    bool flag = 1;
    for(int j = 0; j < m; ++ j)
      if(g[j][i] >= k) {
        flag = 0;
        if(vis[j]) ans = true;
        vis[j] = true;
      }
    if(flag) return false;
  } return ans;
}
int main() {
  T = read();
  while(T --) {
    m = read(); n = read();
    for(int i = 0; i < m; ++ i) {
      g[i].resize(n);
      for(int j = 0; j < n; ++ j)
        g[i][j] = read();
    }
    int l = 1, r = 1e9, mid;
    while(l < r) {  
      mid = (l + r + 1) >> 1;
      if(check(mid)) l = mid;
      else r = mid - 1;
    } printf("%d\n", r);
  }
  return 0;
}