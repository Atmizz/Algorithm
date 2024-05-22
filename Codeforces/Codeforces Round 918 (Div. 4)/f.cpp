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
struct Line {
  int l, r;
  friend bool operator < (Line a, Line b) {
    return a.l == b.l ? a.r < b.r : a.l < b.l;
  }
}l[N];
int n;
int lowbit(int x) {
  return x & -x;
}
void solve() {
  std :: cin >> n;
  std :: vector <int> v;
  for(int i = 1; i <= n; ++ i) {
    std :: cin >> l[i].l >> l[i].r;
    v.push_back(l[i].l);
    v.push_back(l[i].r);
  }
  std :: sort(v.begin(), v.end());
  for(int i = 1; i <= n; ++ i) {
    l[i].l = std :: lower_bound(v.begin(), v.end(), l[i].l) - v.begin() + 1;
    l[i].r = std :: lower_bound(v.begin(), v.end(), l[i].r) - v.begin() + 1; 
  }
  std :: sort(l + 1, l + 1 + n);

  std :: vector <int> sum(n * 2 + 1);
  auto add = [&](int x) -> void {
    for(; x <= n * 2; x += lowbit(x)) {
      sum[x] ++;
    }
  };
  auto query = [&](int x) -> int {
    i64 s = 0;
    for(; x; x -= lowbit(x)) {
      s += sum[x];
    }
    return s;
  };
  i64 ans = 0;
  for(int i = n; i >= 1; -- i) {
    // deb(l[i].l); deb(l[i].r);
    ans += query(l[i].r) - query(l[i].l-1);
    add(l[i].r);
  }
  std :: cout << ans << '\n';
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