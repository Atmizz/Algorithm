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
const int N = 1e6 + 20;
int n, m, b[N], c[N], maxx[N];
void solve() {
  std :: cin >> n >> m;
  for(int i = 0; i <= n + 1; ++ i) {
    c[i] = 0; b[i] = INF;
  }
  for(int i = 1; i <= m; ++ i) {
    int l, r;
    std :: cin >> l >> r;
    c[l] ++; c[r+1] --;
    b[r] = std :: min(b[r], l);
  }
  for(int i = n; i >= 1; -- i) {
    b[i] = std :: min(b[i], b[i+1]);
  }
  for(int i = 1; i <= n; ++ i) {
    c[i] += c[i-1];
    if(c[i] != 0) {
      maxx[i] = std :: max(maxx[i-1], c[i] + maxx[b[i]-1]);
    } else {
      maxx[i] = maxx[i-1];
    }
  }
  std :: cout << maxx[n] << '\n';
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