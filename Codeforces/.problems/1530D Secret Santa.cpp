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
const int N = 2e5 + 20;
int n, a[N], ans[N];
void solve() {
  std :: cin >> n;
  for(int i = 1; i <= n; ++ i) {
    std :: cin >> a[i];
  }
  std :: queue <int> q;
  std :: map <int, int> m;
  for(int i = 1; i <= n; ++ i) {
    if(a[i] != i && !m[a[i]]) {
      m[a[i]] = 1;
    }
  }
  for(int i = 1; i <= n; ++ i) {
    if(m[i] == 0) {
      q.push(i);
    }
    m[i] = 0;
  }
  for(int i = 1; i <= n; ++ i) {
    if(a[i] != i && !m[a[i]]) {
      m[a[i]] = i;
      ans[i] = a[i];
      continue;
    }
    if(q.front() == i) {
      q.push(q.front());
      q.pop();
    }
    ans[i] = q.front();
    q.pop();
  }
  int cnt = 0;
  for(int i = 1; i <= n; ++ i) {
    if(ans[i] == i) {
      ans[i] = a[i];
      ans[m[a[i]]] = i;
    }
  }
  for(int i = 1; i <= n; ++ i) {
    cnt += (ans[i] == a[i]);
  }
  std :: cout << cnt << '\n';
  for(int i = 1; i <= n; ++ i) {
    std :: cout << ans[i] << ' ';
  }
  std :: cout << '\n';
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