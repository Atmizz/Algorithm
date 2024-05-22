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
int n, m, d, ans[N];
struct Node {
  int time, id, usd;
  friend bool operator < (Node a, Node b) {
    return a.time == b.time ? a.id < b.id : a.time < b.time;
  }
}a[N];
void solve() {
  std :: cin >> n >> m >> d;
  for(int i = 1; i <= n; ++ i) {
    std :: cin >> a[i].time;
    a[i].id = i;
  }
  std :: sort(a + 1, a + 1 + n);
  int day = 0;
  for(int i = 1; i <= n; ++ i) {
    if(a[i].usd) {
      continue;
    }
    day ++;
    a[i].usd = day;
    int lst = a[i].time + d + 1;
    while(lst <= m) {
      int pos = std :: lower_bound(a + 1, a + 1 + n, (Node){lst, 0, 0}) - a;
      while(pos <= n && a[pos].usd) {
        pos ++;
      }
      if(pos > n) {
        break;
      }
      a[pos].usd = day;
      lst = a[pos].time + d + 1;
    }
  }
  for(int i = 1; i <= n; ++ i) {
    ans[a[i].id] = a[i].usd;
  }
  std :: cout << day << '\n';
  for(int i = 1; i <= n; ++ i) {
    std :: cout << ans [i] << ' ';
  }
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