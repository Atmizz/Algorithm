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
const int N = 3e5 + 20;
int n, a[N], cnt, num[N];
i64 maxx1, maxx2;
std :: vector <int> son[N];
void dfs(int u) {
  if(!num[a[u]]) {
    cnt ++;
    if(cnt > maxx2 && cnt < maxx1) {
      maxx2 = cnt;
    } else if(cnt >= maxx1) {
      maxx2 = maxx1;
      maxx1 = cnt;
    }
  }
  num[a[u]] ++;
  for(auto v : son[u]) {
    dfs()
  }
}
void solve() {
  std :: cin >> n;
  maxx1 = maxx2 = 0;
  for(int i = 1; i <= n; ++ i) {
    son[i].clear();
  }
  for(int i = 2; i <= n; ++ i) {
    int pa; std :: cin >> pa;
    son[pa].push_back(i);
  }
  for(int i = 1; i <= n; ++ i) {
    std :: cin >> a[i];
  }
  dfs(1);
  std :: cout << maxx1 << 
}
int main() {
  //freopen("1.in", "r", stdin);
  //freopen("1.out", "w", stdout);
  std :: ios :: sync_with_stdio(false);
  std :: cin.tie(0);
  std :: cout.tie(0);
  int T = 1;
  std :: cin >> T; 
  while(T --) solve();
  return 0;
}