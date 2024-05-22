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
int n, col[N], cnt, head[N], num[N];
std :: set <int> s;
struct Edge {
  int to, net;
}e[N<<1];
inline void Insert(int u, int v) {
  e[++cnt] = {v, head[u]};
  head[u] = cnt;
}
void dfs(int u, int fa) {
  for(int i = head[u]; i; i = e[i].net) {
    int v = e[i].to;
    if(v == fa) continue;
    if(col[v] != col[u]) {
      s.insert(v);
      s.insert(u);
      num[u] ++; num[v] ++;
    }
    dfs(v, u);
  }
}
void solve() {
  std :: cin >> n;
  for(int i = 1; i < n; ++ i) {
    int u, v;
    std :: cin >> u >> v;
    Insert(u, v); Insert(v, u);
  }
  for(int i = 1; i <= n; ++ i) {
    std :: cin >> col[i];
  }
  dfs(1, 1);
  for(auto x : s) {
    if(num[x] == s.size() - 1) {
      std :: cout << "YES\n";
      std :: cout << x;
      return ;
    }
  }
  if(s.empty()) {
    std :: cout << "YES\n1";
    return ;
  }
  std :: cout << "NO";
}
int main() {
  //freopen("1.in", "r", stdin);
  //freopen("1.out", "w", stdout);
  std :: ios :: sync_with_stdio(false);
  std :: cin.tie(0);
  std :: cout.tie(0);
  int T = 1;
  // std :: cin >> T; 
  while(T --) solve();
  return 0;
}