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
const int MaxN = 2e5 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int T, n, a[MaxN], pa[MaxN], ans1, ans2, du[MaxN], vis[MaxN];
std :: vector <int> blk[MaxN];
int Find(int x) {
  return x == pa[x] ? pa[x] : pa[x] = Find(pa[x]);
}
void Unity(int u, int v) {
  u = Find(u); v = Find(v);
  pa[u] = v;
}
int main() {
  T = read();
  while(T --) {
    for(int i = 1; i <= ans1; ++ i) blk[i].clear();
    n = read(); ans1 = 0; ans2 = 0;
    for(int i = 1; i <= n; ++ i) pa[i] = i, du[i] = 2, vis[i] = 0;
    for(int i = 1; i <= n; ++ i) {
      a[i] = read(); Unity(i, a[i]);
      du[i] --; du[a[i]]--;
    }
    for(int i = 1; i <= n; ++ i) {
      pa[i] = Find(i);
      if(vis[pa[i]] == 0) vis[pa[i]] = ++ans1;
      blk[vis[pa[i]]].push_back(du[i]);
    }
    for(int i = 1; i <= ans1; ++ i)
      std :: sort(blk[i].begin(), blk[i].end());
    std :: queue <int> q;
    std :: map<int, int> m;
    for(int i = 1; i <= ans1; ++ i) {
      du[i] = 0;
      for(auto x : blk[i])
        if(x == 1) du[i] ++;
        else break;
    }
    for(int i = 1; i <= ans1; ++ i) q.push(i);
    while(q.size()) {
      
    }
  }
  return 0;
}