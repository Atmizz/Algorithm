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
inline ll max(ll a, ll b) {return a > b ? a : b;}
const int MaxN = 1e6 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
struct edge {
  int to, net;
}e[MaxN<<1];
int n, val[MaxN], head[MaxN << 1], cnt = 1, size[MaxN], r1, r2;
bool vis[MaxN], flag;
ll dp[MaxN][2], ans;
void Insert(int u, int v) {
  e[++cnt] = {v, head[u]};
  head[u] = cnt;
}
void dfs(int u, int fa) {
  vis[u] = 1; size[++size[0]] = u;
  for(int i = head[u]; i; i = e[i].net) {
    int v = e[i].to;
    if(v == fa) continue;
    if(!vis[v]) dfs(v, u);
    else if(vis[v] && !flag) {
      flag = true;
      r1 = u, r2 = v;
    }
  }
}
void dfs2(int u, int fa) {
  dp[u][0] = 0; dp[u][1] = val[u];
  for(int i = head[u]; i; i = e[i].net) {
    int v = e[i].to;
    if(v == fa || v == -1) continue;
    dfs2(v, u);
    dp[u][1] += dp[v][0];
    dp[u][0] += max(dp[v][0], dp[v][1]);
  }
}
int main() {
  n = read();
  for(int i = 1; i <= n; ++ i) {
    val[i] = read(); int x = read();
    Insert(i, x); Insert(x, i);
  }
  for(int i = 1; i <= n; ++ i)
    if(!vis[i]) {
      size[0] = 0; flag = false; dfs(i, -1);
      if(!flag) {
        int root = size[1];
        dfs2(root, -1);
        ans += max(dp[root][0], dp[root][1]);
      } else {
        ll maxv = -INF;
        for(int i = head[r1]; i; i = e[i].net) {
          int v = e[i].to;
          if(v == r2) {
            e[i].to = -1;
            e[i^1].to = -1;
            break;
          }
        }
        dfs2(r1, -1); maxv = max(maxv, dp[r1][0]);
        dfs2(r2, -1); maxv = max(maxv, dp[r2][0]);
        ans += maxv;
      }
    }
  printf("%lld", ans);
  return 0;
}