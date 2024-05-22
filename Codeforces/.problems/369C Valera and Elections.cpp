#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl '\n'
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1e5 + 20;
int n, head[N], cnt, dp[N];
std :: vector <int> ans;
struct Edge {
  int to, net, flag;
}e[N<<1];
void Insert(int u, int v, int w) {
  e[++cnt] = {v, head[u], w};
  head[u] = cnt;
}
void dfs(int u, int fa) {
  for(int i = head[u]; i; i = e[i].net) {
    int v = e[i].to;
    if(v == fa) continue;
    dfs(v, u); dp[u] += dp[v];
  }
  for(int i = head[u]; i; i = e[i].net) {
    int v = e[i].to;
    if(v == fa) {
      if(e[i].flag == 2 && dp[u] == 0) {
        dp[u] = 1;
        ans.push_back(u);
      }
      break;
    }
  }
}
void solve() {
  std :: cin >> n;
  for(int i = 1; i < n; ++ i) {
    int x, y, z;
    std :: cin >> x >> y >> z;
    Insert(x, y, z);
    Insert(y, x, z);
  }
  dfs(1, 1);
  std :: cout << ans.size() << '\n';
  for(auto x : ans) {
    std :: cout << x << ' ';
  }
}
int main() {
  //freopen("1.in", "r", stdin);
  //freopen("1.out", "w", stdout);
  std :: ios :: sync_with_stdio(false);
  std :: cin.tie(0);
  std :: cout.tie(0);
  int T = 1;
  //std :: cin >> T; 
  while(T --) solve();
  return 0;
}